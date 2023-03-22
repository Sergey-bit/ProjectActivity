#include "Button.hpp"

Button::Button(sf::RenderWindow& window, const vec2i& pos) : win_(window), position_(pos),
scale_(Core::Settings::getInstance().getGlobalScale())
{
	sprites_.push_back(nullptr);
	sprites_.push_back(nullptr);
	sprites_.push_back(nullptr);
}

Sprite* Button::loadSprite(const std::string& filename)
{
	Sprite* sprite = new Sprite();
	sprite->load(filename);
	sprite->setPosition(position_);
	return sprite;
}
Sprite* Button::loadSprite(const sf::Image& image)
{
	Sprite* sprite = new Sprite();
	sprite->load(image);
	sprite->setPosition(position_);
	return sprite;
}
Sprite* Button::loadSprite(const sf::Sprite& sprite)
{
	Sprite* s = new Sprite();
	s->load(sprite);
	s->setPosition(position_);
	return s;
}
Sprite* Button::loadSprite(const sf::Texture& texture)
{
	Sprite* s = new Sprite();
	s->load(texture);
	s->setPosition(position_);
	return s;
}

void Button::setScale(const float& scale)
{
	scale_.x = scale;
	scale_.y = scale;
}
void Button::setScale(const float& xs, const float& ys)
{
	scale_.x = xs;
	scale_.y = ys;
}
void Button::setScale(const vec2f& scale)
{
	scale_ = std::move(scale);
}

vec2f Button::getScale() const
{
	return scale_;
}
vec2i Button::getPosition() const
{
	return position_;
}

void Button::setPosition(const vec2i& newPosition)
{
	position_ = newPosition;

	for (Sprite* s : sprites_)
	{
		if (s)
		{
			s->setPosition(newPosition);
		}
	}
}

std::optional<sf::Sprite> Button::getHoverSprite() const
{
	std::optional<sf::Sprite> sprite(std::nullopt);

	if (sprites_.at(1))
	{
		sprite.value() = sprites_[1]->getSprite();
	}
	
	return sprite;
}
std::optional<sf::Sprite> Button::getPressedSprite() const
{
	std::optional<sf::Sprite> sprite(std::nullopt);

	if (sprites_.at(2))
	{
		sprite.value() = sprites_[2]->getSprite();
	}

	return sprite;
}
std::optional<sf::Sprite> Button::getCalmSprite() const
{
	std::optional<sf::Sprite> sprite(std::nullopt);

	if (sprites_.at(0))
	{
		sprite.value() = sprites_[0]->getSprite();
	}

	return sprite;
}

void Button::setCalmTexture(const std::string& filename)
{
	sprites_.at(0) = loadSprite(filename);
}
void Button::setCalmTexture(const sf::Texture& texture)
{
	sprites_.at(0) = loadSprite(texture);
}
void Button::setCalmTexture(const sf::Image& image)
{
	sprites_.at(0) = loadSprite(image);
}
void Button::setCalmTexture(sf::Sprite& sprite)
{
	sprites_.at(0) = loadSprite(sprite);
}

void Button::setPressedTexture(const std::string& filename)
{
	sprites_.at(2) = loadSprite(filename);
}
void Button::setPressedTexture(const sf::Texture& texture)
{
	sprites_.at(2) = loadSprite(texture);
}
void Button::setPressedTexture(const sf::Image& image)
{
	sprites_.at(2) = loadSprite(image);
}
void Button::setPressedTexture(sf::Sprite& sprite)
{
	sprites_.at(2) = loadSprite(sprite);
}

void Button::setHoverTexture(const std::string& filename)
{
	sprites_.at(1) = loadSprite(filename);
}
void Button::setHoverTexture(const sf::Texture& texture)
{
	sprites_.at(1) = loadSprite(texture);
}
void Button::setHoverTexture(const sf::Image& image)
{
	sprites_.at(1) = loadSprite(image);
}
void Button::setHoverTexture(sf::Sprite& sprite)
{
	sprites_.at(1) = loadSprite(sprite);
}

void Button::draw()
{
	hover();
	pressed();

	if (sprites_.at(currentSprite_))
	{
		Sprite* sp = sprites_.at(currentSprite_);
		win_.draw(sp->getSprite());

	}
}
void Button::pressed()
{
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && currentSprite_ == 1)
	{
		currentSprite_ = 2;
	}
	else if (currentSprite_ == 2)
	{
		currentSprite_ = 0;
	}
}
void Button::hover()
{		
	if(sprites_.at(currentSprite_))
	{
		vec2i mousePos = sf::Mouse::getPosition(win_);
		vec2u spSize = sprites_.at(currentSprite_)->getSprite().getTexture()->getSize();

		if (position_.x <= mousePos.x && position_.y <= mousePos.y &&
			position_.x + spSize.x >= mousePos.x && position_.y + spSize.y >= mousePos.y)
		{
			currentSprite_ = 1;
		}
		else if (currentSprite_ == 1)
		{
			currentSprite_ = 0;
		}
	}
}

bool Button::isHovered() const
{
	return currentSprite_ != 0;
}
bool Button::isPressed() const
{
	return currentSprite_ == 2;
}

bool Button::isVisible() const
{
	return visibility_;
}
void Button::setVisibility(bool nv)
{
	visibility_ = nv;
}