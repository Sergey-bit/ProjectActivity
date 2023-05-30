#pragma once

#include <Frame.hpp>
#include <Sprite.hpp>
#include <Button\Button.hpp>
#include <BackSprite.hpp>
#include <Widget.hpp>
#include <ctime>

class Chest: public Core::GameObject
{
public:

	Chest(sf::RenderWindow& Window, const vec2i& pos);
	Core::Eqiupment getItem();

	void draw();
	void work();
	std::string toStrData() const;

private:

	sf::RenderWindow& Window;
	using equip = Core::Eqiupment;

	vec2i position;
	size_t maxItems = 5;
	size_t curItems;
	float globalskale = sf::VideoMode::getDesktopMode().width / 1920.0;

	std::vector<equip> items;
	std::vector<BackSprite*> chestSlots;

	BackSprite chestIcon;
	BackSprite chestEmptySlot;

	sf::Mouse mouse;
	sf::Keyboard klava;

	bool flag = false;
	size_t gettedItem = 5;

	bool isPressed(BackSprite& sprite, vec2i& pos2);
	void generateItems();
	void loadSlots();
};