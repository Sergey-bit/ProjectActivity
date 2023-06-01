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
		SHRUB, // кустарник
		SHRUB2, // кустарник
		WALL_VERT,
		RAKOVINA,
		CHEST

	};
	using matrix = std::array<std::array<Textures, M>, N>;

public:
	Map(sf::RenderWindow& win);

	void draw();
	void move(float dx, float dy);

	void setScale(float x);
	float getScale() const;

	std::array<Textures, M>& operator[](size_t i);

private:
	matrix map_;
	sf::RenderWindow& win_;

	BackSprite floor3_;
	BackSprite floor2_;
	BackSprite floor_;
	BackSprite wall_;
	BackSprite shrub_;
	BackSprite wall_vert_;
	BackSprite rakovina_;

	vec2f pos_;
	float scale_ = 1.0;
};