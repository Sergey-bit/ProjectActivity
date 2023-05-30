#pragma once

#include <Frame.hpp>
#include <BackSprite.hpp>
#include <Button/Button.hpp>
#include <TextField.hpp>
#include <Profile.hpp>

class Registration: public Frame
{
private:
	float globalskale = sf::VideoMode::getDesktopMode().width / 1920.0;
	sf::RenderWindow& Window;
	BackSprite back;
	Button start;
	Button exit;

	Profile & prof;
	bool isAutorized = false;
	
	void autorize();	

	sf::Font font;

	TextField loginTextBox;
	TextField passwordTextBox;

	Core::Settings qwe;

	sf::Mouse m;
	sf::Vector2f pos;

	sf::Keyboard k;
	std::string q;
public:
	Registration(sf::RenderWindow& Window, Profile& prof);
	virtual void work();
	virtual void init();
	virtual void draw();
	virtual const bool& autorized() const;

};

