#pragma once

#include <boost/bind.hpp>
#include <boost/asio.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/enable_shared_from_this.hpp>
#include <boost/core/noncopyable.hpp>

using namespace boost::asio;
using namespace boost::posix_time;

#define MEM_FN(x)       boost::bind(&self_type::x, shared_from_this())
#define MEM_FN1(x,y)    boost::bind(&self_type::x, shared_from_this(),y)
#define MEM_FN2(x,y,z)  boost::bind(&self_type::x, shared_from_this(),y,z)


extern io_service service;
extern ip::tcp::acceptor acceptor;


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
    enum { max_msg = 65536 };
    bool started_;

    ip::tcp::socket sock_;

    char read_buffer_[max_msg];
    char write_buffer_[max_msg];
};