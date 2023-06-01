#pragma once

#include <map.hpp>

void fillRoom(Map::matrix& map, int dx, int dy, int offX, int offY, Map::Textures filling)
{
	for (int i = 0; i < dx; i++)
	{
		for (int j = 0; j < dy; j++)
		{
			map[offX + i][offY + j] = filling;
		}
	}
}

void Map::move(float dx, float dy) {
	pos_.x += dx;
	pos_.y += dy;
}

void Map::setScale(float x) {
	scale_ = x;
	wall_.setScale(scale_);
	floor3_.setScale(scale_);
	floor2_.setScale(scale_);
	floor_.setScale(scale_);
	shrub_.setScale(scale_);
	wall_vert_.setScale(scale_);
	rakovina_.setScale(scale_);
}

float Map::getScale() const{
	return scale_;
}
std::array<Map::Textures, M>& Map::operator[](size_t i)
{
	return map_[i];
}

Map::Map(sf::RenderWindow& win) : win_(win), floor3_(win), wall_(win), 
floor2_(win), floor_(win), shrub_(win), wall_vert_(win), rakovina_(win)
{
	#define FILL(dx, dy, x, y, filling) fillRoom(map_, dx, dy, x, y, filling)

	floor3_.load(MAP_TEXTURES "\\floor_stone.png");
	floor2_.load(MAP_TEXTURES "\\floor_wood.png");
	floor_.load(MAP_TEXTURES "\\floor_gray.png");
	wall_.load(MAP_TEXTURES "\\wall.png");
	shrub_.load(MAP_TEXTURES "\\cust.png");
	wall_vert_.load(MAP_TEXTURES "\\wall_vert.png");
	rakovina_.load(MAP_TEXTURES "\\rakovina.png");

	// BATHROOM
	for (int i = 0; i < 8; i++)
	{
		map_[i][0] = WALL;
	}
	for (int i = 1; i < 17; i++)
	{
		map_[0][i] = WALL_VERT;
	}

	for (int i = 0; i < 4; i++)
	{
		map_[7][i + 1] = WALL_VERT;
	}
	map_[7][6] = FLOOR3;
	map_[7][5] = FLOOR3;

	for (int i = 1; i < 8; i++)
	{
		map_[i][7] = WALL;
	}
	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			map_[i + 1][1 + j] = FLOOR3;
		}
	}

	// TOILET
	for (int i = 0; i < 6; i++)
	{
		map_[1 + i][11] = WALL;
	}

	map_[6][12] = WALL_VERT;
	map_[6][13] = FLOOR3;
	map_[6][14] = FLOOR3;
	map_[6][15] = WALL_VERT;

	for (int i = 0; i < 20; i++)
	{
		map_[1 + i][16] = WALL;
	}
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			map_[1 + i][12 + j] = FLOOR3;
		}
	}

	// HALL
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			map_[1 + i][j + 8] = FLOOR3;
		}
	}

	map_[10][10] = FLOOR3;
	map_[11][10] = FLOOR3;
	map_[12][10] = FLOOR3;

	map_[10][9] = WALL;
	map_[11][9] = WALL;
	map_[12][9] = WALL;

	map_[10][8] = FLOOR3;
	map_[11][8] = FLOOR3;
	map_[12][8] = FLOOR3;

	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			map_[7 + i][11 + j] = FLOOR3;
		}
	}
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			map_[8 + i][j + 2] = FLOOR3;
		}
	}

	for (int i = 0; i < 27; i++)
	{
		map_[8 + i][1] = WALL;
	}
	for (int i = 0; i < 27; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			map_[8 + i][2 + j] = FLOOR3;
		}
	}

	map_[21][4] = FLOOR3;
	map_[22][4] = FLOOR3;
	map_[27][4] = FLOOR3;
	map_[28][4] = FLOOR3;

	map_[31][4] = FLOOR3;
	map_[32][4] = FLOOR3;
	map_[33][4] = FLOOR3;

	map_[15][3] = SHRUB;
	map_[18][3] = SHRUB;
	map_[23][3] = SHRUB;
	map_[26][3] = SHRUB;
	map_[31][4] = SHRUB;


	map_[34][2] = WALL_VERT;
	map_[34][3] = WALL_VERT;
	map_[34][4] = WALL_VERT;

	for (int i = 0; i < 8; i++)
	{
		map_[13 + i][4] = WALL;
	}
	for (int i = 0; i < 4; i++)
	{
		map_[23 + i][4] = WALL;
	}

	map_[29][4] = WALL;
	map_[30][4] = WALL;
	map_[30][5] = WALL_VERT;
	map_[30][6] = WALL_VERT;

	for (int i = 0; i < 10; i++)
	{
		map_[31+i][5] = WALL;
	}

	map_[30][7] = FLOOR3;
	map_[30][8] = FLOOR3;

	map_[30][9] = WALL_VERT;
	map_[30][10] = WALL_VERT;
	map_[30][11] = WALL_VERT;

	for (int i = 0; i < 8; i++)
	{
		map_[13][5 + i] = WALL_VERT;
	}

	map_[14][12] = WALL;
	map_[15][12] = WALL;

	map_[16][12] = FLOOR3;
	map_[17][12] = FLOOR3;

	for (int i = 0; i < 13; i++)
	{
		map_[18 + i][12] = WALL;
	}
	for (int i = 0; i < 16; i++)
	{
		for (int j = 0; j < 7; j++)
		{
			map_[14 + i][5 + j] = FLOOR3;
		}
	}

	FILL(9, 5, 31, 6, FLOOR3);
	FILL(1, 5, 40, 6, WALL_VERT);
	FILL(11, 1, 38, 11, WALL);
	FILL(3, 1, 33, 11, WALL);
	FILL(4, 7, 36, 12, FLOOR3);
	FILL(2, 1, 36, 11, FLOOR3);
	FILL(1, 4, 40, 12, WALL_VERT);
	FILL(1, 7, 48, 12, WALL_VERT);
	FILL(7, 7, 41, 12, FLOOR3);
	FILL(1, 2, 40, 16, FLOOR3);
	FILL(8, 1, 41, 19, WALL);
	FILL(1, 7, 35, 12, WALL_VERT);
	FILL(1, 9, 40, 18, WALL_VERT);
	FILL(1, 4, 36, 19, WALL_VERT);
	FILL(3, 4, 37, 19, FLOOR3);
	FILL(4, 4, 36, 23, FLOOR3);
	FILL(3, 1, 33, 19, WALL);
	FILL(12, 1, 32, 27, WALL);
	FILL(18, 3, 13, 13, FLOOR2);
	FILL(2, 1, 31, 11, FLOOR2);
	FILL(4, 4, 31, 12, FLOOR2);
	FILL(8, 1, 24, 16, WALL);
	FILL(10, 2, 25, 17, FLOOR2);
	FILL(3, 1, 32, 16, FLOOR2);
	FILL(1, 8, 24, 17, WALL_VERT);
	FILL(1, 8, 20, 17, WALL_VERT);
	FILL(8, 10, 25, 17, FLOOR2);
	FILL(3, 7, 33, 20, FLOOR2);
	FILL(3, 9, 21, 16, FLOOR2);
	FILL(8, 1, 12, 20, WALL);
	FILL(1, 7, 12, 21, WALL_VERT);
	FILL(7, 4, 13, 21, FLOOR2);
	FILL(16, 1, 13, 27, WALL);
	FILL(12, 2, 13, 25, FLOOR2);
	FILL(1, 11, 13, 28, WALL_VERT);
	FILL(1, 3, 25, 28, WALL_VERT);
	FILL(1, 2, 25, 33, WALL_VERT);
	FILL(11, 7, 14, 28, FLOOR1);
	FILL(1, 2, 25, 31, FLOOR1);
	FILL(7, 3, 14, 35, FLOOR1);
	FILL(9, 1, 13, 38, WALL);
	FILL(1, 3, 21, 35, WALL_VERT);
	FILL(14, 1, 22, 35, WALL);
	FILL(3, 1, 31, 31, WALL);
	FILL(1, 4, 36, 28, WALL_VERT);
	FILL(1, 4, 36, 35, WALL_VERT);
	FILL(1, 3, 31, 32, WALL_VERT);
	FILL(3, 1, 29, 27, FLOOR2);
	FILL(8, 3, 26, 28, FLOOR2);
	FILL(5, 4, 26, 31, FLOOR2);
	FILL(2, 7, 34, 28, FLOOR2);
	FILL(2, 3, 32, 32, FLOOR2);
	FILL(1, 12, 44, 27, WALL_VERT);
	FILL(7, 1, 37, 38, WALL);
	FILL(7, 10, 37, 28, FLOOR1);
	FILL(1, 3, 36, 32, FLOOR1);

	map_[38][10] = SHRUB;
	map_[35][10] = SHRUB;
	map_[41][18] = SHRUB;
	map_[25][13] = SHRUB;
	map_[14][13] = SHRUB;
	map_[32][32] = SHRUB;
	map_[30][34] = SHRUB;
	map_[5][1] = RAKOVINA;
	map_[4][12] = RAKOVINA;
}
void Map::draw()
{
	for (int i = 0; i < map_.size(); i++)
	{
		for (int j = 0; j < map_[i].size(); j++)
		{
			vec2i pos((int)((i - pos_.x) * 100 * scale_), (int)((j - pos_.y) * 100 * scale_));
			switch (map_[i][j])
			{
			case FLOOR3:
				floor3_.setPosition(pos);
				floor3_.draw();
				continue;
			case FLOOR2:
				floor2_.setPosition(pos);
				floor2_.draw();
				continue;
			case FLOOR1:
				floor_.setPosition(pos);
				floor_.draw();
				continue;
			case WALL:
				wall_.setPosition(pos);
				wall_.draw();
				continue;
			case SHRUB:
				floor_.setPosition(pos);
				floor_.draw();
				shrub_.setPosition(pos);
				shrub_.draw();
				continue;
			case WALL_VERT:
				wall_vert_.setPosition(pos);
				wall_vert_.draw();
				continue;
			case RAKOVINA:
				rakovina_.setPosition(pos);
				rakovina_.draw();
				continue;
			}
		}
	}
}

vec2f Map::getPos() const
{
	return pos_;
}