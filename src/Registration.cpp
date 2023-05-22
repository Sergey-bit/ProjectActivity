#include <Registration.hpp>

void Registration::init() {
	font.loadFromFile(FONT_PATH "Roboto-Bolt.ttf");

	back.load(TEX_PATH "RegistrationMenu\\back.png");
	back.setScale(vec2f(globalskale, globalskale));

	start.setCalmTexture(TEX_PATH "RegistrationMenu\\start.png");
	start.setHoverTexture(TEX_PATH "RegistrationMenu\\start.png");
	start.setPressedTexture(TEX_PATH "RegistrationMenu\\start.png");
	start.setScale(vec2f(globalskale, globalskale));

	exit.setCalmTexture(TEX_PATH "RegistrationMenu\\exit.png");
	exit.setHoverTexture(TEX_PATH "RegistrationMenu\\exit.png");
	exit.setPressedTexture(TEX_PATH "RegistrationMenu\\exit.png");
	exit.setScale(vec2f(globalskale, globalskale));
	
	loginTextBox.setFont(font);
	loginTextBox.setLength(20);
	loginTextBox.setPosition(vec2f(666, 135) * globalskale);
	loginTextBox.setsize(vec2f(642, 69) * globalskale);
	passwordTextBox.setFont(font);
	passwordTextBox.setLength(20);
	passwordTextBox.setPosition(vec2f(666, 258) * globalskale);
	passwordTextBox.setsize(vec2f(642, 69) * globalskale);
	//sd.Left
}

Registration::Registration(sf::RenderWindow& Window) :
	Frame(exchangeIF<unsigned int>({ sf::VideoMode::getDesktopMode().width, sf::VideoMode::getDesktopMode().height }), { 0,0 }),
	Window(Window),
	back(Window),
	start(Window, 1550 * globalskale, 60 * globalskale),
	exit(Window, 0, 0)

{	
}

void Registration::work() {
	draw();

	loginTextBox.input();
	passwordTextBox.input('*');

	if (start.isPressed()) {
		autorize()
	}
}

void Registration::draw() {
	back.draw();
	start.draw();
	loginTextBox.render(Window);
	passwordTextBox.render(Window);
}

const bool& Registration::autorized() const {
	return isAutorized;
}

void Registration::autorize() {

}
