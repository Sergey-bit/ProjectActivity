#pragma once

#define TXTFIELD_H

#include <string>
#include <SFML/Graphics.hpp>
#include <Frame.hpp>
#include <Object.hpp>
#include <iostream>

const int GUI_TEXT_MAX = 24;
const int GUI_TEXT_BACKSPACE = 8;
const int GUI_TEXT_ESCAPE = 27;

const sf::Color GUI_TEXT_GRAY = sf::Color(105, 105, 105);

class TextField {
public:
	TextField();

	void setPosition(sf::Vector2f vec);
	void input(const char& s='\n');

	void setFont(sf::Font& f);
	const std::string& getText() const;

	void setPlaceholder(std::string str);
	void render(sf::RenderWindow& window);

	void setLength(int arg);
	int getTextLength() const;

	bool isActive() const;
	void open();
	 
	void close();
	void setsize(sf::Vector2f vec);

	sf::Text txt;
	sf::RectangleShape box;
	sf::Vector2f pos;


private:

	sf::Mouse mouse;
	int count = 0;

	int size;
	int length;

	bool renderPlaceholder;
	void setActive(bool arg);

	bool active;
	std::string placeholder;
};
