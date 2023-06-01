#pragma once

#include <Sprite.hpp>
#include <Button\Button.hpp>
#include <BackSprite.hpp>
#include <Widget.hpp>

class Inventory: Core::GameObject
{
private:
	sf::RenderWindow& Window;
	using equip = Core::Eqiupment;

	size_t maxItems = 10;
	size_t maxSpecialItems = 2;
	size_t curItems = 0;
	float globalskale = sf::VideoMode::getDesktopMode().width / 1920.0;

	std::vector<equip> items;
	std::vector<BackSprite*> InventorySlots;

	sf::Mouse mouse;
	sf::Keyboard klava;

	bool flagP = false;
	bool flagE = false;
	size_t gettedItem = 11;

	bool isPressed(BackSprite& sprite, vec2i& pos2);
public:
	Inventory(sf::RenderWindow& Window);
	Core::Eqiupment getItem();
	void setItem(equip e);

	void draw();
	void work();
};

