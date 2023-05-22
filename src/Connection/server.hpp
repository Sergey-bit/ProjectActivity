#pragma once

#include <boost/bind.hpp>
#include <boost/asio.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/enable_shared_from_this.hpp>
#include <boost/core/noncopyable.hpp>

using namespace boost::asio;
using namespace boost::posix_time;

io_service service;

#define MEM_FN(x)       boost::bind(&self_type::x, shared_from_this())
#define MEM_FN1(x,y)    boost::bind(&self_type::x, shared_from_this(),y)
#define MEM_FN2(x,y,z)  boost::bind(&self_type::x, shared_from_this(),y,z)


class TalkToCl : public boost::enable_shared_from_this<TalkToCl>, boost::noncopyable
{
private:
    typedef TalkToCl self_type;

    TalkToCl();

public:
    typedef boost::system::error_code error_code;
    typedef boost::shared_ptr<TalkToCl> ptr;

    void start();
    static ptr new_();

    void stop();
    ip::tcp::socket& sock();

private:
    void on_read(const error_code& err, size_t bytes);
    void on_write(const error_code& err, size_t bytes);

    void do_read();
    void do_write(const std::string& msg);
    size_t read_complete(const boost::system::error_code& err, size_t bytes);

private:
    enum { max_msg = 1024 };
    bool started_;

    ip::tcp::socket sock_;

    char read_buffer_[max_msg];
    char write_buffer_[max_msg];
};

ip::tcp::acceptor acceptor(service, ip::tcp::endpoint(ip::tcp::v4(), 8001));

void handle_accept(TalkToCl::ptr client, const boost::system::error_code& err) {
    client->start();
    TalkToCl::ptr new_client = TalkToCl::new_();
    acceptor.async_accept(new_client->sock(), boost::bind(handle_accept, new_client, _1));
}


int main(int argc, char* argv[]) {
    TalkToCl::ptr client = TalkToCl::new_();
    acceptor.async_accept(client->sock(), boost::bind(handle_accept, client, _1));
    service.run();
}
