#pragma once

#include <Frame.hpp>
#include <Sprite.hpp>
#include <Button/Button.hpp>
#include <BackSprite.hpp>
#include <Player.hpp>


class PlayingWithFriends: public Frame
{
private:
	float globalskale = sf::VideoMode::getDesktopMode().width / 1920.0;
	sf::RenderWindow& Window;
	BackSprite back;

	//Player 

	//Button next;
	//Button exit;



public:
	PlayingWithFriends(sf::RenderWindow& Window);
	virtual void work();
	virtual void draw();
	
};

