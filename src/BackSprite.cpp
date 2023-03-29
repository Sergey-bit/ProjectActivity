#include "BackSprite.hpp"

BackSprite::BackSprite(sf::RenderWindow& window) :
	GameObject((Core::GameObject*)this), win_(window), scale_(1.f, 1.f)
{

}

void BackSprite::draw()
{
	win_.draw(getSprite());
}
void BackSprite::setScale(const vec2f& ns)
{
	getSprite().setScale(ns);
}

bool BackSprite::isVisible() const
{
	return visibility_;
}
void BackSprite::setVisibility(bool nv)
{
	visibility_ = nv;
}

vec2f BackSprite::getScale() const
{
	return scale_;
}
