#pragma once

#include "Sprite.hpp"
#include "Object.hpp"

class BackSprite : 
	virtual public Core::GameObject,
	virtual public Sprite
{
private:
	sf::RenderWindow& win_;
	vec2f scale_;

public:
	BackSprite(sf::RenderWindow&);

	virtual void draw() override;
	virtual void setScale(const vec2f&) override;

	virtual bool isVisible() const override;
	virtual void setVisibility(bool) override;

	virtual vec2f getScale() const;
};

