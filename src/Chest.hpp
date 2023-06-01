#pragma once

#include <Frame.hpp>
#include <Sprite.hpp>
#include <BackSprite.hpp>
#include <BaseChestData.h>
#include <ctime>
#include <map.hpp>

class Chest:public BaseChestData, public Core::GameObject
{
public:

	Chest(sf::RenderWindow& Window, const vec2i& pos);
	Core::Eqiupment getItem();

	void draw();
	void work(Map& map);
	std::string toStrData() const;
	float id;

	void setScale(float x);
	float getScale();

	bool isOpened() const;

private:

	sf::RenderWindow& Window;
	using equip = Core::Eqiupment;

	size_t maxItems = 5;
	size_t curItems;
	float globalskale = sf::VideoMode::getDesktopMode().width / 1920.0;

	float scale;

	std::vector<equip> items;
	std::vector<BackSprite*> chestSlots;

	BackSprite chestIcon;

	sf::Mouse mouse;
	sf::Keyboard klava;

	void setPosition();

	bool flagP = false;
	bool flagE = false;
	size_t gettedItem = 5;

	bool isPressed(BackSprite& sprite, sf::Vector2i pos2);
	void generateItems();
	void loadSlots();
};