#pragma once

#include <string>
#include <vector>
#include <Bullet.hpp>
#include <Chest.hpp>
#include <BaseDataPlayer.hpp>

struct DynamicObjects
{
	std::vector<Bullet> bullets;
	std::vector<Chest> chests;

	std::string toStrData() const;
};