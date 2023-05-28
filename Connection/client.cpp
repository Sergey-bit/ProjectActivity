#include <Connection/client.hpp>


extern io_service service{};

std::string TalkToSvr::message_;
bool TalkToSvr::gotten_ = false;

TalkToSvr::TalkToSvr(const std::string& message) : sock_(service), started_(true)
{
    message_ = message;
}
TalkToSvr::ptr TalkToSvr::start(ip::tcp::endpoint ep, const std::string& message)
{
    ptr new_(new TalkToSvr(message));
    new_->start(ep);

    return new_;
}

void TalkToSvr::start(ip::tcp::endpoint ep)
{
    sock_.async_connect(ep, MEM_FN1(on_connect, _1));
}
void TalkToSvr::stop()
{
    if (!started_) return;
    started_ = false;
    sock_.close();
}

bool TalkToSvr::started()
{
    return started_;
}

void TalkToSvr::on_connect(const error_code& err)
{
    if (!err)
    {
        do_write(message_ + "\n");
    }
    else    
    {
        stop();
    }
}
void TalkToSvr::on_read(const error_code& err, size_t bytes)
{
    if (!err) {
        std::string copy(read_buffer_, bytes - 1);
        message_ = copy;

        gotten_ = true;
    }
    else
    {
        std::cout << err.value() << std::endl;
    }
    stop();
}

void TalkToSvr::on_write(const error_code& err, size_t bytes)
{
    do_read();
}
void TalkToSvr::do_read()
{
    async_read(sock_, buffer(read_buffer_),
        MEM_FN2(read_complete, _1, _2), MEM_FN2(on_read, _1, _2));
}

void TalkToSvr::do_write(const std::string& msg)
{
    if (!started()) 
    {
        return;
    }
    std::copy(msg.begin(), msg.end(), write_buffer_);

    sock_.async_write_some(
        buffer(write_buffer_, msg.size()),
        MEM_FN2(on_write, _1, _2)
    );
}
size_t TalkToSvr::read_complete(const boost::system::error_code& err, size_t bytes)
{
    if (err)
    {
        return 0;
    }
    bool found = std::find(read_buffer_, read_buffer_ + bytes, '\n') < read_buffer_ + bytes;

    // we read one-by-one until we get to enter, no buffering
    return found ? 0 : 1;
}

const std::string& TalkToSvr::getAnswer()
{
    if (gotten_)
    {
        return message_;
    }
    else
    {
        return "";
    }
}