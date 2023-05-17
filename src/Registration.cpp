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
	loginTextBox.setPlaceholder("enret login");
	loginTextBox.setPosition(vec2f(5, 5));
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
	isStartPressed = start.isPressed();
}

void Registration::draw() {
	back.draw();
	start.draw();
	loginTextBox.render(Window);
}

const bool& Registration::startPressed() const {
	return isStartPressed;
}