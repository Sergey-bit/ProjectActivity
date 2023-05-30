#pragma once

#include <array>
#include <BackSprite.hpp>

#define N 51
#define M 40

class Map final
{
public:
	enum Textures
	{
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
		TOILET,
		VOID

	};
	using matrix = std::array<std::array<Textures, M>, N>;

public:
	Map();

private:
	matrix map_
};