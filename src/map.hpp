#pragma once

#include <array>
#include <BackSprite.hpp>
#include <Vector.hpp>

#define MAP_TEXTURES "ProjectActivity\\resources\\textures\\MapTextures"

#define N 51
#define M 40

class Map final
{
public:
	enum Textures
	{
		VOID,
		WALL,
		FLOOR1, // Gray version
		FLOOR2, // Wood version
		FLOOR3, // Stone version
		BATH,
		SHRUB, // кустарник
		TABLE,
		BED,
		ANGLE_BED,
		CHAIR,
		ARM_CHAIR,
		SINK,
		TOILET

	};
	using matrix = std::array<std::array<Textures, M>, N>;

public:
	Map(sf::RenderWindow& win);

	void draw();

private:
	matrix map_;
	sf::RenderWindow& win_;

	BackSprite floor3_;
	BackSprite floor2_;
	BackSprite floor_;
	BackSprite wall_;
	BackSprite shrub_;
};