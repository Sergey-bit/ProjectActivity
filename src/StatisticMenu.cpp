#include <StatisticMenu.h>
#include <Widget.hpp>


StatisticMenu::StatisticMenu(sf::RenderWindow& window) :
	Frame(exchangeIF<unsigned int>({ sf::VideoMode::getDesktopMode().width, sf::VideoMode::getDesktopMode().height }), { 0,0 }),
	window(window), back(window)
{
	back.load(TEX_PATH "StatisticMenu\\StatisticMenu.png");
	back.setScale(vec2f(globalskale, globalskale));
	font.loadFromFile(FONT_PATH "Roboto-Bolt.ttf");
	name.setFont(font);
	rank.setFont(font);
	winsPercentage.setFont(font);
	kills.setFont(font);
	favWeapon.setFont(font);
	KDA.setFont(font);
	matchesPlayed.setFont(font);
	averMatchTime.setFont(font);
	name.setPosition({ 300, 20 });
	rank.setPosition({ 1400, 20 });
	winsPercentage.setPosition({ 1400, 255 });
	kills.setPosition({ 1400, 355 });
	favWeapon.setPosition({ 1400, 455 });
	KDA.setPosition({ 1400, 550 });
	matchesPlayed.setPosition({ 1400, 655 });
	averMatchTime.setPosition({ 1400, 765 });
}

const  bool& StatisticMenu::escPressed() const
{
	return isEscPressed;
}

void StatisticMenu::work()
{
	draw();
	isEscPressed = sf::Keyboard::isKeyPressed(sf::Keyboard::Escape);
	if (isEscPressed)
		;//transfer
}

void StatisticMenu::draw()
{
	back.draw();
	window.draw(name);
	window.draw(rank);
	window.draw(winsPercentage);
	window.draw(kills);
	window.draw(favWeapon);
	window.draw(KDA);
	window.draw(matchesPlayed);
	window.draw(averMatchTime);
}
