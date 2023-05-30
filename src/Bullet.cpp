#pragma once

#include <Bullet.hpp>

std::string Bullet::toStrData() const
{
	return "angle:" + std::to_string(angle) + ";type:" +
		std::to_string(type) + ";x:" + std::to_string(pos.x) +
		";y:" + std::to_string(pos.y);
}
