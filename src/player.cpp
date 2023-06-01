#include <player.hpp>

Player::Player(sf::RenderWindow& win) : win_(win), line(sf::Lines, 2), size(win.getSize())
{
	pos.x = win_.getSize().x / 2;
	pos.y = win_.getSize().y / 2;
	player.setFillColor(sf::Color::Magenta);
	player.setSize({50, 30});
	player.setPosition(pos);
}

void Player::lookAt(const double& angle)
{
	this->angle = angle;
}

void Player::lookingAround()
{
	lookdir = exchangeIF(sf::Mouse::getPosition()) - pos;
	angle = atan2(lookdir.y, lookdir.x) * (180 / PI) - 90.0f;
	player.setRotation(angle);
}

void Player::tracking()
{
	float angle = atan2(lookdir.y, lookdir.x);
	line[0].position = pos;
	line[1].position = { pos.x + size.x * cos(angle), pos.y + size.x * sin(angle) };
}

void Player::setAmmo(int ammo)
{
	ammoSize = ammo;
}

void Player::move()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && ((pos.y - speed) > 0))
	{
		pos.y -= speed;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && ((pos.y + speed) < size.y))
	{
		pos.y += speed;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && ((pos.x - speed) > 0))
	{
		pos.x -= speed;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && ((pos.x + speed) < size.x))
	{
		pos.x += speed;
	}
	player.setPosition(pos);
}

void Player::fire()
{
	for (int i = 0; i < ammo.size(); i++)
	{
		ammo[i].object.move(ammo[i].currVelocity);
		win_.draw(ammo[i].object);

		if (ammo[i].object.getPosition().x < 0 || ammo[i].object.getPosition().x > size.x
			|| ammo[i].object.getPosition().y < 0 || ammo[i].object.getPosition().y > size.y)
			ammo.erase(ammo.begin() + i);
	}
}

void Player::shooting()
{
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		lookdirnorm = lookdir / (float)length(lookdir);
		Bullet bullet;
		bullet.object.setRadius(6);
		bullet.pos_ = { pos.x, pos.y + 10 };
		bullet.object.setPosition(bullet.pos_);
		bullet.currVelocity = lookdirnorm * bullet.velocity;
		ammo.push_back(bullet);
		fire();
	}
}

void Player::draw()
{
	win_.draw(player);
	win_.draw(line);
}