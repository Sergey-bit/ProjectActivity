#include <Frame.hpp>

Frame::Frame(const vec2i& size, const vec2i& position) :
	size_(size), pos_(position)
{

}

const vec2i& Frame::getSize() const
{
	return size_;
}
void Frame::setSize(const vec2i& nsize)
{
	size_ = nsize;
}

const vec2i& Frame::getPosition() const
{
	return pos_;
}
void Frame::setPosition(const vec2i& npos)
{
	pos_ = npos;
 }