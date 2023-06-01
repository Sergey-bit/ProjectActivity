#include <player.hpp>

Player::Player(sf::RenderWindow& win) : win_(win), windowSize(win.getSize())
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
	
	vec2f lookdir = exchangeIF(sf::Mouse::getPosition()) - pos;
	angle = atan2(lookdir.y, lookdir.x);
	player.setRotation(angle * (180 / PI) - 90.0f);
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
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && ((pos.y + speed) < windowSize.y))
	{
		pos.y += speed;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && ((pos.x - speed) > 0))
	{
		pos.x -= speed;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && ((pos.x + speed) < windowSize.x))
	{
		pos.x += speed;
	}
	player.setPosition(pos);
}

void Player::fire()
{
	for (int i = 0; i < ammo.size(); i++)
	{
		float velocity = 0;
		if (ammo[0].type == 0)
			velocity = 200.0f;
		if (ammo[0].type == 1)
			velocity = 150.0f;
		if (ammo[0].type == 3)
			velocity = 100.0f;
		vec2f currVelocity = { cos(ammo[i].angle) * velocity, sin(ammo[i].angle) * velocity };
		ammo[i].object.move(currVelocity);
		win_.draw(ammo[i].object);
		if (ammo[i].object.getPosition().x < 0 || ammo[i].object.getPosition().x > windowSize.x
			|| ammo[i].object.getPosition().y < 0 || ammo[i].object.getPosition().y > windowSize.y)
			ammo.erase(ammo.begin() + i);
	}
}

void Player::shooting()
{
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		Bullet bullet;
		bullet.object.setRadius(6);
		bullet.pos = { pos.x, pos.y + 10 };
		bullet.object.setPosition(bullet.pos);
		bullet.angle = angle;
		if (weapon == Core::SHOTGUN)
			bullet.type = Core::shotgun;
		if (weapon == Core::RIFLE)
			bullet.type = Core::rifle;
		if (weapon == Core::UZI)
			bullet.type = Core::pistol;
		ammo.push_back(bullet);
		fire();
	}
}

void Player::draw()
{
	win_.draw(player);
}