#pragma once

#include "AbstractButton.hpp"

#include <optional>
#include <iostream>

class Button :
	virtual public Core::AbstractButton,
	virtual public Core::GameObject
{
protected:
	using index = short unsigned int;

	std::vector<Sprite*> sprites_;
	sf::RenderWindow& win_;

	index currentSprite_ = 0;
	vec2i position_;

	vec2f scale_;

	virtual void pressed();
	virtual void hover();

	Sprite* loadSprite(const std::string& filename);
	Sprite* loadSprite(const sf::Sprite& sprite);
	Sprite* loadSprite(const sf::Texture& texture);
	Sprite* loadSprite(const sf::Image& image);

public:
	Button(sf::RenderWindow& win, const vec2i& pos=vec2i(0, 0));

	virtual void draw();

	virtual bool isVisible() const;
	virtual void setVisibility(bool);

	virtual void setHoverTexture(const std::string& filename);
	virtual void setHoverTexture(const sf::Texture& texture);
	virtual void setHoverTexture(const sf::Image& image);
	virtual void setHoverTexture(sf::Sprite& sprite);

	virtual void setPressedTexture(const std::string& filename);
	virtual void setPressedTexture(const sf::Texture& texture);
	virtual void setPressedTexture(const sf::Image& image);
	virtual void setPressedTexture(sf::Sprite& sprite);

	virtual void setCalmTexture(const std::string& filename);
	virtual void setCalmTexture(const sf::Texture& texture);
	virtual void setCalmTexture(const sf::Image& image);
	virtual void setCalmTexture(sf::Sprite& sprite);

	virtual vec2i getPosition() const;
	virtual void setPosition(const vec2i& newPosition);

	virtual std::optional<sf::Sprite> getHoverSprite() const;
	virtual std::optional<sf::Sprite> getPressedSprite() const;
	virtual std::optional<sf::Sprite> getCalmSprite() const;

	virtual vec2f getScale() const;

	virtual bool isHovered() const;
	virtual bool isPressed() const;

	virtual void setScale(const float& scale);
	virtual void setScale(const float& xs, const float& ys);
	virtual void setScale(const vec2f& scale) override;

	virtual void scale(const float& scale_);
	virtual void scale(const float& xs, const float& ys);
	virtual void scale(const vec2f& scale_);
};
