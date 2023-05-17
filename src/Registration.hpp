#pragma once

#include <Frame.hpp>
#include <BackSprite.hpp>
#include <Button/Button.hpp>
#include <TextField.hpp>

class Registration: public Frame
{
private:
	float globalskale = sf::VideoMode::getDesktopMode().width / 1920.0;
	sf::RenderWindow& Window;
	BackSprite back;
	Button start;
	Button exit;

	//sf::String loginInput;
	//sf::Text loginText;

	//sf::String passwordInput;
	//sf::Text passwordText;

	bool isStartPressed = false;
	
	//std::string login;
	//std::string password;

	sf::Font font;

	sf::RectangleShape inputTextRect1;

	TextField loginTextBox;
	TextField passwordTextBox;
	

public:
	Registration(sf::RenderWindow& Window);
	virtual void work();
	virtual void init();
	virtual void draw();
	virtual const bool& startPressed() const;



};

