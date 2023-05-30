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

Map::Map()
{
	#define FILL(dx, dy, x, y, filling) fillRoom(map_, dx, dy, x, y, filling)

	// BATHROOM
	for (int i = 0; i < 8; i++)
	{
		map_[i][0] = WALL;
	}
	for (int i = 1; i < 17; i++)
	{
		map_[0][i] = WALL;
	}

	for (int i = 0; i < 5; i++)
	{
		map_[7][i + 1] = WALL;
	}
	map_[7][6] = FLOOR3;

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

	map_[6][12] = WALL;
	map_[6][13] = FLOOR3;
	map_[6][14] = FLOOR3;
	map_[6][15] = WALL;

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
			map_[7 + i][11 + j] = FLOOR3
		}
	}
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			map_[8 + i][j + 2] = FLOOR3;
		}
	}

	for (int i = 0; i < 28; i++)
	{
		map_[8 + i][1] = WALL;
	}
	for (int i = 0; i < 28; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			map_[8 + i][2 + j] = FLOOR3;
		}
	}

	map_[15][3] = SHRUB;
	map_[18][3] = SHRUB;
	map_[23][3] = SHRUB;
	map_[26][3] = SHRUB;
	map_[31][4] = SHRUB;

	map_[31][4] = FLOOR3;
	map_[31][4] = FLOOR3;
	map_[31][4] = FLOOR3;

	map_[32][2] = WALL;
	map_[32][3] = WALL;
	map_[32][4] = WALL;

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
	map_[30][6] = WALL;

	for (int i = 0; i < 12; i++)
	{
		map_[30][5] = WALL;
	}

	map_[30][7] = FLOOR3;
	map_[30][8] = FLOOR3;

	map_[30][9] = WALL;
	map_[30][10] = WALL;
	map_[30][11] = WALL;

	for (int i = 0; i < 8; i++)
	{
		map_[13][5 + i] = WALL;
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
		for (int j = 0; j < 7)
		{
			map_[14 + i][5 + j] = FLOOR3;
		}
	}

	FILL(10, 5, 31, 6, FLOOR3);
	FILL(1, 5, 38, 6, WALL);
	FILL(4, 1, 33, 11, WALL);
	FILL(11, 1, 40, 11, WALL);
}