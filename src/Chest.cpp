#include "Chest.hpp"

Chest::Chest(sf::RenderWindow& Window, const vec2i& pos) :
	Window(Window),
	chestIcon(Window),
	chestEmptySlot(Window)
{
	BaseChestData::setPos(pos);
	chestIcon.load(TEX_PATH "chest\\chest.png");
	chestIcon.setScale(vec2f(globalskale, globalskale));

	chestEmptySlot.load(TEX_PATH "chest\\slot.png");
	chestEmptySlot.setScale(vec2f(globalskale, globalskale));

	position = pos;
	chestIcon.setPosition(position);

	for (int i = 0; i < maxItems; i++) {
		chestSlots.push_back(new BackSprite(Window));
	}

	generateItems();
	loadSlots();
}

void Chest::work() {

	draw();
	gettedItem = 5;

	if(mouse.isButtonPressed(sf::Mouse::Left)){

		sf::Vector2i pos(mouse.getPosition());
		
		if(isPressed(chestIcon, pos) || flag){

			flag = true;

			for (int i = 0; i < maxItems; i++) {
				chestSlots[i]->draw();
			}

			if (mouse.isButtonPressed(sf::Mouse::Left)) {

				if (isPressed(*chestSlots[0], pos)) gettedItem = 0;
				if (isPressed(*chestSlots[1], pos)) gettedItem = 1;
				if (isPressed(*chestSlots[2], pos)) gettedItem = 2;
				if (isPressed(*chestSlots[3], pos)) gettedItem = 3;
				if (isPressed(*chestSlots[4], pos)) gettedItem = 4;

			}

			if (klava.isKeyPressed(sf::Keyboard::BackSpace)) flag = false;

		}
	}	
}

void Chest::draw() {
	chestIcon.draw();
}

void Chest::loadSlots() {

	for (int i = 0; i < curItems; i++) { 

		if (items[i] == 0) chestSlots[i]->load(TEX_PATH "chest\\BIG_HEAL.png");
		if (items[i] == 1) chestSlots[i]->load(TEX_PATH "chest\\SMALL_HEAL.png");
		if (items[i] == 2) chestSlots[i]->load(TEX_PATH "chest\\ARMOR1.png");
		if (items[i] == 3) chestSlots[i]->load(TEX_PATH "chest\\SNIPER.png");
		if (items[i] == 4) chestSlots[i]->load(TEX_PATH "chest\\SOFF_SHOTGUN.png");
		if (items[i] == 5) chestSlots[i]->load(TEX_PATH "chest\\SHOTGUN.png");
		if (items[i] == 6) chestSlots[i]->load(TEX_PATH "chest\\MINIGUN.png");
		if (items[i] == 7) chestSlots[i]->load(TEX_PATH "chest\\UZI.png");
		if (items[i] == 8) chestSlots[i]->load(TEX_PATH "chest\\RIFLE.png");
		chestSlots[i]->setScale(vec2f(globalskale, globalskale));
	}

	if (curItems < maxItems) {
		for (int i = curItems; i < maxItems; i++) {
			chestSlots[i]->load(TEX_PATH "chest\\slot.png");
			chestSlots[i]->setScale(vec2f(globalskale, globalskale));
		}
	}

	for (int i = 0; i < maxItems; i++) {
		//chestSlots[i]->setPosition(vec2i((1000 + i * 150) * globalskale, 0));
	}

}

void Chest::generateItems() {

	curItems = rand() % (maxItems - 1) + 2;

	for (int i = curItems ; i > 0; i--) {

		size_t buff = rand() % 9;
		items.push_back((equip)buff);
	}
	BaseChestData::setItems(items);
}

bool Chest::isPressed(BackSprite& sprite, vec2i& pos2) {

	vec2f pos1 = sprite.getPosition();
	vec2u size = sprite.getSize();
	if (((pos1.x < pos2.x) && (pos1.x + size.x < pos2.x)) && ((pos1.y < pos2.y) && (pos1.y + size.y < pos2.y))) return true;
	else return false;

}

Core::Eqiupment Chest::getItem() {

	if (gettedItem < 5) {
		items.erase(items.begin() + gettedItem);
		return items[gettedItem];
	}
	BaseChestData::setItems(items);
}

std::string Chest::toStrData() const {
	std::string str = "chest:";
	for (int i = 0; i < items.size() - 1; i++) {
		str += std::to_string(items[i]) + ",";
	}
	str += std::to_string(items[items.size() - 1]);
	return str;
}
//BIG_HEAL 0 +
//SMALL_HEAL 1
//ARMOR1 2
//SNIPER 3 +
//SOFF_SHOTGUN 4 +
//SHOTGUN 5 +
//MINIGUN 6 +
//UZI 7 +
//RIFLE 8 +