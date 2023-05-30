#pragma once

#include <SFML/Graphics.hpp>
#include <player.hpp>
#include <map.hpp>
#include <Vector.hpp>

class World
{
private:
	sf::RenderWindow& win_;
	Map map_;

public:
	World(sf::RenderWindow& win);
	
	bool collide(const vec2f& pos) const;
	bool isChest() const;

	vec2f worldCoord(const vec2i& pos) const;
};