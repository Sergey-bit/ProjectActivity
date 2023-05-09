#include <BackSprite.hpp>

BackSprite::BackSprite(sf::RenderWindow& window) :
	win_(window), scale_(1.f, 1.f)
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
void BackSprite::setScale(const float& factor)
{
	getSprite().setScale(factor, factor);
}
void BackSprite::setScale(const float& factorX, const float& factorY)
{
	getSprite().setScale(factorX, factorY);
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

void BackSprite::setShader(sf::Shader& shader)
{
	;
}

void BackSprite::setShader(const std::string& shader)
{
	;
}