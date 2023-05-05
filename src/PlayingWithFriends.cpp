#include "PlayingWithFriends.hpp"

PlayingWithFriends::PlayingWithFriends(sf::RenderWindow& Window) :
	Frame(exchangeIF<unsigned int>({ sf::VideoMode::getDesktopMode().width, sf::VideoMode::getDesktopMode().height }), { 0,0 }),
	Window(Window),
	back(Window)
{
	back.load(TEX_PATH "MainMenu\\Buttons\\StartGameButton\\Calm.png");
	back.setScale(vec2f(globalskale, globalskale));


}

void PlayingWithFriends::work() {

}

void PlayingWithFriends::draw() {
	back.draw();

}