#pragma once
#include "Transfer.hpp"
#include "Vector.hpp"
#include <SFML/Graphics.hpp>
#include "BackSprite.hpp"




class StatisticMenu: public Frame {
	sf::RenderWindow& window;
	BackSprite back;
	sf::Text name;
	sf::Text rank;
	sf::Font font;
	sf::Text winsPercentage;
	sf::Text kills;
	sf::Text favWeapon;
	sf::Text KDA;
	sf::Text matchesPlayed;
	sf::Text averMatchTime;
	float globalskale = sf::VideoMode::getDesktopMode().width / 1920.0;
	bool isEscPressed = false;
public:
	StatisticMenu(sf::RenderWindow& window);
	virtual void work();

	virtual void draw();
	const bool& escPressed() const;
};

