#include "BaseChestData.h"

vec2i BaseChestData::getPos()
{
	return position;
}

std::vector<Core::Eqiupment> BaseChestData::getItems() {
	return items;
}

void BaseChestData::setItems(std::vector<Core::Eqiupment> items)
{
	this->items = items;
}

void BaseChestData::setPos(vec2i position)
{
	this->position = position;
}