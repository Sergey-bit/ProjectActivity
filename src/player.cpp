#include <player.hpp>

Player::Player(sf::RenderWindow& win, Profile& profile) : win_(win), profile_(profile), line(sf::Lines, 2), size(win.getSize())
{
	pos_.x = win_.getSize().x / 2;
	pos_.y = win_.getSize().y / 2;
	player.setFillColor(sf::Color::Magenta);
	player.setSize({50, 30});
	player.setPosition(pos_);
}

void Player::lookAt(const float& angle)
{
	angle_ = angle;
}

void Player::lookingAround()
{
	lookdir = exchangeIF(sf::Mouse::getPosition()) - pos_;
	angle_ = atan2(lookdir.y, lookdir.x) * (180 / PI) - 90.0f;
	player.setRotation(angle_);
}

void Player::tracking()
{
	float angle = atan2(lookdir.y, lookdir.x);
	line[0].position = pos_;
	line[1].position = { pos_.x + size.x * cos(angle), pos_.y + size.x * sin(angle) };
}

void Player::move()
{
	float cos_a(cos(angle_)), sin_a(sin(angle_));
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && ((pos_.y - speed) > 0))
	{
		pos_.y -= speed;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && ((pos_.y + speed) < size.y))
	{
		pos_.y += speed;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && ((pos_.x - speed) > 0))
	{
		pos_.x -= speed;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && ((pos_.x + speed) < size.x))
	{
		pos_.x += speed;
	}
	player.setPosition(pos_);
}

const float& Player::getAngle() const
{
	return angle_;
}

void Player::draw()
{
	win_.draw(player);
	win_.draw(line);
}