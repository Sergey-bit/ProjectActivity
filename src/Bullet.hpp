#pragma once

#include <Vector.hpp>
#include <Widget.hpp>
#include <SFML/Graphics.hpp>

struct Bullet
{
	float angle;
	vec2f pos;;
	sf::CircleShape object;

	Core::BulletType type;
	std::string toStrData() const;
};
