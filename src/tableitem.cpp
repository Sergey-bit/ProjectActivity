#include "tableitem.h"

tableitem::tableitem(const std::string& title, const int& n, sf::RenderWindow& window, const sf::Font& font):
	window(window)
{
	this->title.setString(title);
	this->title.setFont(font);
	this->title.setCharacterSize(60);
	this->title.setPosition({ 200.0f, n * 94.0f });
	option.setSize({ 794.0f,90.0f });
	option.setPosition({1050.0f, n*94.0f});
	option.setFillColor(sf::Color::White);
	item.setSize({ 2000.0f, 100.0f });
	item.setPosition({0.0f, n*94.0f});
	item.setFillColor(sf::Color::Black);
}

void tableitem::draw()
{
	window.draw(item);
	window.draw(option);
	window.draw(title);
}

void tableitem::scale()
{
	
}