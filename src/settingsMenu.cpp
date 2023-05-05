#include "settingsMenu.h"

SettingsMenu::SettingsMenu(sf::RenderWindow& window) :
	Frame(exchangeIF<unsigned int>({ sf::VideoMode::getDesktopMode().width, sf::VideoMode::getDesktopMode().height }), { 0,0 }),
	window(window), back(window)
{
	font.loadFromFile("huyna.ttf");
	back.load("settingsBackground.png");
	back.setScale(vec2f(globalskale, globalskale));
}

void SettingsMenu::work()
{
	draw();
	items.push_back(tableitem("Display mode", 0, window, font));
	items.push_back(tableitem("Vertical synchronization", 1, window, font));
	items.push_back(tableitem("Sound effects", 2, window, font));
	items.push_back(tableitem("Music", 3, window, font));
	items.push_back(tableitem("Walking to the right", 4, window, font));
	items.push_back(tableitem("Walking to the left", 5, window, font));
	items.push_back(tableitem("Walking forward", 6, window, font));
	items.push_back(tableitem("Walking backwards", 7, window, font));
	items.push_back(tableitem("Shooting", 8, window, font));
	items.push_back(tableitem("Language", 9, window, font));
	items.push_back(tableitem("Interaction with the subject", 10, window, font));
	items.push_back(tableitem("Mouse sensitivity", 11, window, font));
	items.push_back(tableitem("Recharge", 12, window, font));
	for (auto& item : items)
	{
		item.draw();
	}
}

void SettingsMenu::draw()
{
	back.draw();
}
void SettingsMenu::changePosition()
{
	;
}