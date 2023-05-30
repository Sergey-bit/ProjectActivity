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
}

Registration::Registration(sf::RenderWindow& Window, Profile& prof) :
	Frame(exchangeIF<unsigned int>({ sf::VideoMode::getDesktopMode().width, sf::VideoMode::getDesktopMode().height }), { 0,0 }),
	Window(Window),
	back(Window),
	start(Window, 1550 * globalskale, 60 * globalskale),
	exit(Window, 0, 0),
	prof(prof)
	
{	

}	

void Registration::work() {
	draw();

	loginTextBox.input();
	passwordTextBox.input('*');

	if (start.isPressed()) {
		autorize();
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
	q = "username:" + loginTextBox.getText() + ";password:" + passwordTextBox.getText() + "\n";
	TalkToSvr::start(ip::tcp::endpoint(ip::address::from_string("25.34.39.164"), 8001), q);
	service.run();

	const std::string& answer = TalkToSvr::getAnswer();

	std::cout << answer;

	if (answer.length() && answer[0] == '1') {
		isAutorized = true;

		prof.setname("proverka");
		prof.setrank("5");
		prof.setwinsPercentage("");
		prof.setkills("");
		prof.setfavWeapon("");
		prof.setKDA("");
		prof.setmatchesPlayed("");
		prof.setaverMatchTime("");



	}
}
