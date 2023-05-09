#include <Changers/changer.hpp>

bool Changer::isVisible() const
{
	return visibility_;
}
void Changer::setVisibility(bool n)
{
	visibility_ = n;
}

void Changer::setScale(const vec2f& scale)
{
	scale_ = scale;
}
void Changer::setScale(const float& scale)
{
	scale_ = { scale, scale };
}
void Changer::setScale(const float& xs, const float& ys)
{
	scale_ = { xs, ys };
}