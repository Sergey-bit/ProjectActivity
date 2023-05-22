#include <Object.hpp>

void Core::GameObject::setScale(const vec2f& q)
{
	scale = (q);
}

bool Core::GameObject::isVisible() const
{
	return visibility_;
}

void Core::GameObject::setVisibility(bool x)
{
	visibility_ = x;
}