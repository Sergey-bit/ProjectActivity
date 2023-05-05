#include <Achivments.hpp>

#define COUNT_IMG 6

Achivments::Achivments(sf::RenderWindow& Window) :
	Frame(exchangeIF<unsigned int>({ sf::VideoMode::getDesktopMode().width, sf::VideoMode::getDesktopMode().height }), { 0,0 }),
	Window(Window),
	back(Window),
	rectAchive1_(Window),
	rectAchive2_(Window),
	rectAchive3_(Window),
	rectAchive4_(Window),
	rectAchive5_(Window),
	rectAchive6_(Window)
{
	back.load(TEX_PATH "AchivmentsMenu\\Background\\achivmentsMenu.png");
	back.setScale(vec2f(globalskale, globalskale));

	rectAchive1_.load(TEX_PATH "AchivmentsMenu\\Images\\okno1.png");
	rectAchive2_.load(TEX_PATH "AchivmentsMenu\\Images\\okno2.png");
	rectAchive3_.load(TEX_PATH "AchivmentsMenu\\Images\\okno3.png");
	rectAchive4_.load(TEX_PATH "AchivmentsMenu\\Images\\okno4.png");
	rectAchive5_.load(TEX_PATH "AchivmentsMenu\\Images\\okno5.png");
	rectAchive6_.load(TEX_PATH "AchivmentsMenu\\Images\\okno6.png");
	
	rectAchive1_.setScale(vec2f(globalskale , globalskale ));
	rectAchive2_.setScale(vec2f(globalskale , globalskale ));
	rectAchive3_.setScale(vec2f(globalskale , globalskale ));
	rectAchive4_.setScale(vec2f(globalskale , globalskale ));
	rectAchive5_.setScale(vec2f(globalskale , globalskale ));
	rectAchive6_.setScale(vec2f(globalskale , globalskale ));

	rectAchive1_.setPosition(vec2i(50 * globalskale , 120 * globalskale));
	rectAchive2_.setPosition(vec2i(675 * globalskale , 80 * globalskale));
	rectAchive3_.setPosition(vec2i(1300 * globalskale , 120 * globalskale));
	rectAchive4_.setPosition(vec2i(50 * globalskale , 620 * globalskale));
	rectAchive5_.setPosition(vec2i(675 * globalskale , 580 * globalskale));
	rectAchive6_.setPosition(vec2i(1300 * globalskale , 620 * globalskale));
	
	font.loadFromFile(FONT_PATH "Roboto-Bolt.ttf");

	text1_.setScale(vec2f(globalskale, globalskale));
	text1_.setPosition({ vec2f(105 * globalskale, 225 * globalskale ) });
	text1_.setFont(font);
	text1_.setFillColor(sf::Color::Red);
	text1_.setOutlineThickness(2.5);
	text1_.setOutlineColor(sf::Color::Black);
	text1_.setString("Survival is \nabove all:\nwin 5 times \nin a row");

	text2_.setScale(vec2f(globalskale, globalskale));
	text2_.setPosition({ vec2f(730 * globalskale, 185 * globalskale) });
	text2_.setFont(font);
	text2_.setFillColor(sf::Color::Red);
	text2_.setOutlineThickness(2.5);
	text2_.setOutlineColor(sf::Color::Black);
	text2_.setString("Kamikadze:\ntake 3 more\nplayers to the\ngrave with you");

	text3_.setScale(vec2f(globalskale, globalskale));
	text3_.setPosition({ vec2f(1355 * globalskale , 225 * globalskale) });
	text3_.setFont(font);
	text3_.setFillColor(sf::Color::Red);
	text3_.setOutlineThickness(2.5);
	text3_.setOutlineColor(sf::Color::Black);
	text3_.setString("As long as I\nneed you:\nplay 5 times\nwith friends");

	text4_.setScale(vec2f(globalskale, globalskale));
	text4_.setPosition({ vec2f(105 * globalskale , 725 * globalskale) });
	text4_.setFont(font);
	text4_.setFillColor(sf::Color::Red);
	text4_.setOutlineThickness(2.5);
	text4_.setOutlineColor(sf::Color::Black);
	text4_.setString("Saint: don't \nkill others \n3 matches \nin a row");

	text5_.setScale(vec2f(globalskale, globalskale));
	text5_.setPosition({ vec2f(730 * globalskale , 685 * globalskale) });
	text5_.setFont(font);
	text5_.setFillColor(sf::Color::Red);
	text5_.setOutlineThickness(2.5);
	text5_.setOutlineColor(sf::Color::Black);
	text5_.setString("Gunsmith: try \nall kinds \nof weapons");

	text6_.setScale(vec2f(globalskale, globalskale));
	text6_.setPosition({ vec2f(1355 * globalskale , 725 * globalskale) });
	text6_.setFont(font);
	text6_.setFillColor(sf::Color::Red);
	text6_.setOutlineThickness(2.5);
	text6_.setOutlineColor(sf::Color::Black);
	text6_.setString("Killer: kill \nall players \nin the match");
}

void Achivments::work() {

	oknadraw();
	
	ex = sf::Keyboard::isKeyPressed(sf::Keyboard::Escape);
}

const bool& Achivments::exit() const {
	return ex;
}

void Achivments::setAchiveVisible(const achivki& qwe, const bool& asd) {
	//poka ne trogal
}

void Achivments::oknadraw() {
	back.draw();
	rectAchive1_.draw();
	rectAchive2_.draw();
	rectAchive3_.draw();
	rectAchive4_.draw();
	rectAchive5_.draw();
	rectAchive6_.draw();

	Window.draw(text1_);
	Window.draw(text2_);
	Window.draw(text3_);
	Window.draw(text4_);
	Window.draw(text5_);
	Window.draw(text6_);
}