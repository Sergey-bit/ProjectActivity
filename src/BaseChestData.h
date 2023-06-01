#pragma once

#include <Vector.hpp>
#include <Widget.hpp>
class BaseChestData
{
private:
	vec2i position;
	std::vector<Core::Eqiupment> items;
public:
	std::vector<Core::Eqiupment> getItems();
	vec2i getPos();
	void setItems(std::vector<Core::Eqiupment> items);
	void setPos(vec2i position);
};

