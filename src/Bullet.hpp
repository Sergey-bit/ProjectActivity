#pragma once

#include <Vector.hpp>
#include <Widget.hpp>
#include <SFML/Graphics.hpp>

struct Bullet
{
	float angle, maxTravelLen;
	vec2f pos, startPos;
	sf::CircleShape object;
	sf::Uint8 playerIndex;

	Core::BulletType type;
	std::string toStrData() const;
};
