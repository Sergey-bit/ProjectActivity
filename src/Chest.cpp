#include "Chest.hpp"

Chest::Chest(sf::RenderWindow& Window, const vec2i& pos) :
	Window(Window),
	chestIcon(Window)
{
	position = pos;
	chestIcon.load(TEX_PATH "chest\\chest.png");
	//chestIcon.setScale(vec2f(globalskale, globalskale ));

	for (int i = 0; i < maxItems; i++) {
		chestSlots.push_back(new BackSprite(Window));
	}

	generateItems();
	loadSlots();
}

void Chest::work(Map& map) {
	const auto& pos3 = sf::VideoMode::getDesktopMode();
	vec2f pos2 = (exchangeIF<int>(position) - map.getPos()) * 100.0f * map.getScale();
	chestIcon.setScale(map.getScale());
	if (pos3.width >= pos2.x >= 0 && pos3.height >= pos2.y >= 0)
	{
		chestIcon.setPosition({ (int)pos2.x, (int)pos2.y });
		draw();
	}

	sf::Vector2i pos(mouse.getPosition());

	if (isPressed(chestIcon, pos) && flagP == false) {
		flagE = !flagE;
		flagP = true;
	}
	else if (flagP && !isPressed(chestIcon, pos)) {
		flagP = false;
	}


	if (flagE) {

		for (int i = 0; i < maxItems; i++) {
			chestSlots[i]->draw();
		}

		if (mouse.isButtonPressed(sf::Mouse::Left)) {

			sf::Vector2i pos2(mouse.getPosition());

			if (isPressed(*chestSlots[0], pos2)) gettedItem = 0;
			else if (isPressed(*chestSlots[1], pos2)) gettedItem = 1;
			else if (isPressed(*chestSlots[2], pos2)) gettedItem = 2;
			else if (isPressed(*chestSlots[3], pos2)) gettedItem = 3;
			else if (isPressed(*chestSlots[4], pos2)) gettedItem = 4;

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
		chestSlots[i]->setScale(vec2f(globalskale * 1.15, globalskale * 1.15));
	}

	if (curItems < maxItems) {
		for (int i = curItems; i < maxItems; i++) {
			chestSlots[i]->load(TEX_PATH "chest\\slot.png");
			chestSlots[i]->setScale(vec2f(globalskale * 1.15, globalskale * 1.15));
		}
	}

	setPosition();

}

void Chest::generateItems() {

	curItems = rand() % (maxItems - 1) + 2;

	for (int i = curItems ; i > 0; i--) {

		size_t buff = rand() % 9;
		items.push_back((equip)buff);

	}
	
}

bool Chest::isPressed(BackSprite& sprite, sf::Vector2i pos2) {
	if (mouse.isButtonPressed(sf::Mouse::Left)){
		vec2f pos1 = sprite.getPosition();
		vec2u size = sprite.getSize();
		if (((pos1.x < pos2.x) && (pos1.x + size.x > pos2.x)) && ((pos1.y < pos2.y) && (pos1.y + size.y > pos2.y))) return true;
	}
	return false;
}

Core::Eqiupment Chest::getItem() {

	if (gettedItem < maxItems) {
		equip buff = items[gettedItem];
		items[gettedItem] = equip::VOID;
		chestSlots[gettedItem]->load(TEX_PATH "chest\\slot.png");
		gettedItem = 5;
		return buff;
	}
	else return Core::Eqiupment::VOID;
}

std::string Chest::toStrData() const {
	std::string str = "chest:";// +std::to_string(id) + ",";
	for (int i = 0; i < items.size() - 1; i++) {
		str += std::to_string(items[i]) + ",";
	}
	str += std::to_string(items[items.size() - 1]);
	return str;
}

void Chest::setScale(float x) {
	scale = x;
	chestIcon.setScale(scale);

}

float Chest::getScale() {
	return scale;
}

void Chest::setPosition() {
	for (int i = 0; i < chestSlots.size(); i++) {
		chestSlots[i]->setPosition(vec2i((1300 + i * 110) * globalskale, 0));
	}
}

bool Chest::isOpened() const{
	return flagE;
}