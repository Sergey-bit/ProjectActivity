#pragma once
#include "Transfer.hpp"
#include "Vector.hpp"
#include "tableitem.h"

class SettingsMenu: public Frame
{
private:
	sf::RenderWindow& window;
	BackSprite back;
	sf::Font font;
	std::vector<tableitem> items;
	float globalskale = sf::VideoMode::getDesktopMode().width / 1920.0;
public:
	SettingsMenu(sf::RenderWindow& window);
	virtual void work();
	virtual void draw();
	void changePosition();
};

