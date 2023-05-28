#pragma once

#include <iostream>
#include <boost/asio.hpp>
#include <boost/system.hpp>
#include <boost/thread.hpp>
#include <boost/bind.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/enable_shared_from_this.hpp>
#include <boost/core/noncopyable.hpp>
#include <socketapi.h>

#define MEM_FN(x) boost::bind(&self_type::x, shared_from_this())
#define MEM_FN1(x,y) boost::bind(&self_type::x, shared_from_this(),y)
#define MEM_FN2(x,y,z) boost::bind(&self_type::x, shared_from_this(),y,z)

using namespace boost::asio;
extern io_service service;


class TalkToSvr : public boost::enable_shared_from_this<TalkToSvr>,
	private boost::noncopyable
{
private:
    typedef TalkToSvr self_type;

    TalkToSvr(const std::string& message);
    void start(ip::tcp::endpoint ep);

public:
    typedef boost::system::error_code error_code;
    typedef boost::shared_ptr<TalkToSvr> ptr;

    static ptr start(ip::tcp::endpoint ep, const std::string& message);

    void stop();
    bool started();

    static const std::string& getAnswer();

private:
    void on_connect(const error_code& err);
    void on_read(const error_code& err, size_t bytes);

    void on_write(const error_code& err, size_t bytes);
    void do_read();

    void do_write(const std::string& msg);
    size_t read_complete(const boost::system::error_code& err, size_t bytes);


private:
    enum { max_msg = 1024 };
    bool started_;

    ip::tcp::socket sock_;
    static std::string message_;
    static bool gotten_;

    char read_buffer_[max_msg];
    char write_buffer_[max_msg];
};