#include "Sprite.hpp"

Sprite::Sprite() : texture(nullptr)
{

}
Sprite::~Sprite()
{
	if (texture)
	{
		delete texture;
	}
}

void Sprite::load(const sf::Sprite& sprite)
{
	texture = new sf::Texture(*sprite.getTexture());
	this->sprite.setTexture(*texture);
}
void Sprite::load(const sf::Image& sprite)
{
	texture = new sf::Texture();
	
	if (!texture->loadFromImage(sprite))
	{
		std::cout << "Failed to load an image\n";
	}

	this->sprite.setTexture(*texture);
}
void Sprite::load(const sf::Texture& sprite)
{
	texture = new sf::Texture(sprite);
	this->sprite.setTexture(*texture);
}
void Sprite::load(const std::string& filename)
{
	texture = new sf::Texture();
	
	if (!texture->loadFromFile(filename))
	{
		std::cout << "Failed to load the file \"" << filename << "\"\n";
	}

	sprite.setTexture(*texture);
}

const sf::Sprite& Sprite::getSprite() const
{
	return sprite;
}
sf::Sprite& Sprite::getSprite()
{
	return sprite;
}

void Sprite::setPosition(const vec2i& npos)
{
	sprite.setPosition(exchangeIF<int>(npos));
}
vec2u Sprite::getSize() const
{
	return texture->getSize();
}