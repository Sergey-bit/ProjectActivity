#pragma once

#include "Sprite.hpp"
#include "Object.hpp"
#include <optional>

class BackSprite : 
	virtual public Core::GameObject,
	virtual public Sprite
{
private:
	sf::RenderWindow& win_;
	vec2f scale_;
	std::optional<sf::Shader> shader_;

public:
	BackSprite(sf::RenderWindow&);

	virtual void draw() override;

	virtual void setScale(const vec2f&) override;
	virtual void setScale(const float&);
	virtual void setScale(const float&, const float&);

	virtual bool isVisible() const override;
	virtual void setVisibility(bool) override;

	virtual vec2f getScale() const;

	virtual void setShader(sf::Shader& shader);
	virtual void setShader(const std::string& filename);
};

