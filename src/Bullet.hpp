#pragma once

#include <Vector.hpp>

struct Bullet
{
	float angle;
	vec2f pos;

	sf::Uint8 type;
	std::string toStrData() const;
};
