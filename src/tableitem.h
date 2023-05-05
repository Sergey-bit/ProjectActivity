#pragma once
#include <SFML/Graphics.hpp>
#include "BackSprite.hpp"


class tableitem
{
private:
	sf::Text title;
	sf::RectangleShape option;
	sf::RectangleShape item;
	sf::RenderWindow &window;
public:
	tableitem(const std::string& title, const int& n, sf::RenderWindow& window, const sf::Font& font);
	void draw();
	void scale();
};

