#pragma once

#include <Frame.hpp>
#include <Sprite.hpp>
#include <Button\Button.hpp>
#include <BackSprite.hpp>
#include <Widget.hpp>

class Chest: Core::GameObject
{
public:
	Chest();
	void setItem();

private:
	using equip = Core::Eqiupment;
	vec2i position;
	size_t maxItems;
	size_t curItems;
	Sprite sprite;

	std::vector<equip> items;

};