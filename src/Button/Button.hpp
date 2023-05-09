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
	Button(sf::RenderWindow& win, const int& x=0, const int& y=0);

	virtual void draw();

	inline virtual bool isVisible() const;
	inline virtual void setVisibility(bool);

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

	inline virtual vec2f getScale() const;

	inline virtual bool isHovered() const;
	inline virtual bool isPressed() const;

	inline virtual void setScale(const float& scale);
	inline virtual void setScale(const float& xs, const float& ys);
	inline virtual void setScale(const vec2f& scale) override;

	inline virtual void scale(const float& scale_);
	inline virtual void scale(const float& xs, const float& ys);
	inline  void scale(const vec2f& scale_);
};
