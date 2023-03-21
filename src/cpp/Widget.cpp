#include "Widget.hpp"

Core::Settings::Settings() : scale_(1.f, 1.f)
{

}
Core::Settings& Core::Settings::getInstance()
{
	static Settings wid = Settings();
	return wid;
}

vec2f Core::Settings::getGlobalScale() const
{
	return scale_;
}
void Core::Settings::setGlobalScale(const float& scale)
{
	scale_.x = scale;
	scale_.y = scale;
}

void Core::Settings::setGlobalScale(const float& xs, const float& ys)
{
	scale_.x = xs;
	scale_.y = ys;
}
void Core::Settings::setGlobalScale(const vec2f& scale)
{
	scale_.x = scale.x;
	scale_.y = scale.y;
}

