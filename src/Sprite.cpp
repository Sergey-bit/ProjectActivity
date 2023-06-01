#include <Sprite.hpp>

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

const vec2f& Sprite::getPosition() const
{
	return sprite.getPosition();
}
void Sprite::setSize(const vec2i& nsize)
{
	sprite.setScale(nsize / exchangeIF<unsigned>(getSize()));
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
	if (texture)
	{
		delete texture;
	}
	texture = new sf::Texture(sprite);
	this->sprite.setTexture(*texture);
}
void Sprite::load(const std::string& filename)
{
	if (texture)
	{
		delete texture;
	}
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

void Sprite::setRotation(vec2f origin, float angle)
{
	sprite.setOrigin(origin);
	sprite.setRotation(angle);
}

//void Sprite::scale(const double& f)
//{
//	sprite.scale({ f, f });
//}