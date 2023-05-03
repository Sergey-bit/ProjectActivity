#pragma once
#include "Frame.hpp"
#include "Sprite.hpp"
#include "Button.hpp"
#include "BackSprite.hpp"
#include <CTime>
#include <vector>

class Achivments : public Frame {
private:
	float globalskale = sf::VideoMode::getDesktopMode().width / 1920.0;
	sf::RenderWindow& Window;
	BackSprite back;

	BackSprite rectAchive1_;
	BackSprite rectAchive2_;
	BackSprite rectAchive3_;
	BackSprite rectAchive4_;
	BackSprite rectAchive5_;
	BackSprite rectAchive6_;

	sf::Font font;
	sf::Text text1_;
	sf::Text text2_;
	sf::Text text3_;
	sf::Text text4_;
	sf::Text text5_;
	sf::Text text6_;
	
	bool ex = false;
	bool achives[6] = { 0 };
public:
	enum achivki {
		KAMIKADZE,
		PAKUDA,
		VIZHIT,
		SVYATOY,
		ORYZHEYNIK,
		KILLER,
	};
	Achivments(sf::RenderWindow& Window);
	virtual void work();
	virtual const bool& exit() const;	
	virtual	void setAchiveVisible(const achivki & qwe, const bool & asd);
	virtual void oknadraw();

};

