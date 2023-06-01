#include "Inventory.hpp"
Inventory::Inventory(sf::RenderWindow& Window) :
	Window(Window)
{
	for (int i = 0; i < maxItems; i++) {
		InventorySlots.push_back(new BackSprite(Window));
		items.push_back(equip::VOID);
	}

	for (int i = 0; i < maxItems; i++) {
		InventorySlots[i]->load(TEX_PATH "chest\\slot.png");
		InventorySlots[i]->setScale(vec2f(globalskale * 1.15, globalskale * 1.15));
		InventorySlots[i]->setPosition(vec2i((0 + i * 110) * globalskale, 0));
	}



}

void Inventory::draw() {
	for (int i = 0; i < maxItems; i++) {
		InventorySlots[i]->draw();
	}
}

void Inventory::work() {

	if (klava.isKeyPressed(klava.I) && flagP == false) {
		flagE = !flagE;
		flagP = true;
		}
	else if(flagP && !klava.isKeyPressed(klava.I)) {
		flagP = false;
	}

	if (flagE) {
		draw();

		sf::Vector2i pos(mouse.getPosition());
		//std::cout << InventorySlots[0]->getPosition().x << " " << InventorySlots[0]->getPosition().x << " " << InventorySlots[0]->getSize().x << " " << InventorySlots[0]->getSize().y << std::endl;

		if (mouse.isButtonPressed(sf::Mouse::Left)) {

			sf::Vector2i pos2(mouse.getPosition());

			if (isPressed(*InventorySlots[0], pos2)) gettedItem = 0;
			else if (isPressed(*InventorySlots[1], pos2)) gettedItem = 1;
			else if (isPressed(*InventorySlots[2], pos2)) gettedItem = 2;
			else if (isPressed(*InventorySlots[3], pos2)) gettedItem = 3;
			else if (isPressed(*InventorySlots[4], pos2)) gettedItem = 4;
			else if (isPressed(*InventorySlots[5], pos2)) gettedItem = 5;
			else if (isPressed(*InventorySlots[6], pos2)) gettedItem = 6;
			else if (isPressed(*InventorySlots[7], pos2)) gettedItem = 7;
			else if (isPressed(*InventorySlots[8], pos2)) gettedItem = 8;
			else if (isPressed(*InventorySlots[9], pos2)) gettedItem = 9;

		}

	}
}

bool Inventory::isPressed(BackSprite& sprite, vec2i& pos2) {

	vec2f pos1 = sprite.getPosition();
	vec2u size = sprite.getSize();
	if (((pos1.x < pos2.x) && (pos1.x + size.x > pos2.x)) && ((pos1.y < pos2.y) && (pos1.y + size.y > pos2.y))) return true;
	else return false;

}

Core::Eqiupment Inventory::getItem() {

	if (gettedItem < maxItems) {
		curItems--;
		equip buff = items[gettedItem];
		items[gettedItem] = equip::VOID;
		InventorySlots[gettedItem]->load(TEX_PATH "chest\\slot.png");
		gettedItem = 11;
		return buff;
	}

}

void Inventory::setItem(equip e) {
	if (curItems < maxItems && e < equip::VOID) {
		for (int i = 0; i < maxItems; i++) {
			if (items[i] == equip::VOID) {
				items[i] = e;
				if (items[i] == 0) { InventorySlots[i]->load(TEX_PATH "chest\\BIG_HEAL.png"); curItems++; }
				else if (items[i] == 1) { InventorySlots[i]->load(TEX_PATH "chest\\SMALL_HEAL.png"); curItems++; }
				else if (items[i] == 2) { InventorySlots[i]->load(TEX_PATH "chest\\ARMOR1.png"); curItems++; }
				else if (items[i] == 3) { InventorySlots[i]->load(TEX_PATH "chest\\SNIPER.png"); curItems++; }
				else if (items[i] == 4) { InventorySlots[i]->load(TEX_PATH "chest\\SOFF_SHOTGUN.png"); curItems++; }
				else if (items[i] == 5) { InventorySlots[i]->load(TEX_PATH "chest\\SHOTGUN.png"); curItems++; }
				else if (items[i] == 6) { InventorySlots[i]->load(TEX_PATH "chest\\MINIGUN.png"); curItems++; }
				else if (items[i] == 7) { InventorySlots[i]->load(TEX_PATH "chest\\UZI.png"); curItems++; }
				else if (items[i] == 8) { InventorySlots[i]->load(TEX_PATH "chest\\RIFLE.png"); curItems++; }
				break;
			}
		}
	}
}