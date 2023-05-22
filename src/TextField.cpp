#include <string>

#include <SFML/Graphics.hpp>

#include <TextField.hpp>


TextField::TextField() {
	active = false;
	box.setFillColor(sf::Color::Transparent);
	box.setOutlineColor(sf::Color::Transparent);
	box.setOutlineThickness(3);

	renderPlaceholder = false;
	placeholder = "";

	txt.setFillColor(sf::Color(237, 197, 197));

	size = GUI_TEXT_MAX;

	length = 0;
}

void TextField::setPosition(sf::Vector2f vec) {
	box.setPosition(vec);
	txt.setPosition(vec + sf::Vector2f(7, 10));
}

void TextField::setsize(sf::Vector2f vec) {
	box.setSize(vec);

	txt.setCharacterSize(30);
}

void TextField::input(const char& s) {

	if (sf::Event::MouseButtonReleased) {
		sf::Vector2f pos(mouse.getPosition());
		if (box.getGlobalBounds().contains(pos)) {
			setActive(true);
		}
		else {
			setActive(false);
		}
	}

	if (active && Core::Settings::entered && (count%5 == 0 )) {
		
		sf::String str = txt.getString();

		if (Core::Settings::entered == GUI_TEXT_BACKSPACE) {
			if (str.getSize() > 0) {
				length--;
				str = str.substring(0, str.getSize() - 1);
			}
		}
		else if (Core::Settings::entered == GUI_TEXT_ESCAPE) {
			setActive(false);
		}
		else {
			sf::String sfstr = "";
			sfstr += Core::Settings::entered;
			str += sfstr.toAnsiString();
		}

		if (str.getSize() == size) return;

		std::string asterics;
		if (s == '*')
		{
			for (const char& c : str)
			{
				asterics += "*";
			}
		}
		else
		{
			asterics = str;
		}

		txt.setString(asterics);
		length++;

	}
	count += 1;
}


void TextField::setFont(sf::Font& f) {
	txt.setFont(f);
	txt.setCharacterSize(24);

	box.setSize(sf::Vector2f((txt.getCharacterSize() * (size / 2 + 1)) + 10, txt.getCharacterSize() + 10));
}

const std::string& TextField::getText() const {
	return txt.getString();
}

void TextField::render(sf::RenderWindow& window) {
	window.draw(box);
	window.draw(txt);
}

void TextField::setActive(bool arg) {
	active = arg;
	if (active) {
		box.setOutlineColor(sf::Color::Red);
	}
	else {
		box.setOutlineColor(sf::Color::Transparent);
	}

	if (renderPlaceholder && arg) {
		renderPlaceholder = false;
		txt.setString("");
		txt.setFillColor(sf::Color::Transparent);
	}
}

void TextField::setPlaceholder(std::string str) {
	placeholder = str;
	renderPlaceholder = true;
	txt.setFillColor(GUI_TEXT_GRAY);
	txt.setString(placeholder);
	setActive(false);
}

void TextField::setLength(int arg) {
	size = arg;

	box.setSize(sf::Vector2f((txt.getCharacterSize() * (size / 2 + 1)) + 10, txt.getCharacterSize() + 10));
}

int TextField::getTextLength() const {
	return length;
}

bool TextField::isActive() const {
	return active;
}

void TextField::open() {
	setActive(true);
}

void TextField::close() {
	setActive(false);
}

