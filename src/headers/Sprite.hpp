#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>

#include "Vector.hpp"

class Sprite
{
private:
	sf::Texture* texture;
	sf::Sprite sprite;

public:
	Sprite();
	~Sprite();

	void load(const sf::Sprite& sprite);
	void load(const sf::Image& sprite);
	void load(const sf::Texture& sprite);
	void load(const std::string& filename);

	const sf::Sprite& getSprite() const;
	sf::Sprite& getSprite();

	void setPosition(const vec2i& npos);
};