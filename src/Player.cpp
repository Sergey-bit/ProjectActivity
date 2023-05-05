#include "Player.hpp"

Player::Player(const std::string& name):
	name_(name)
{

}

void Player::setName(const std::string& name) {
	name_ = name;
}

std::string Player::getName() const{
	return name_;
}

void Player::draw() {

}
