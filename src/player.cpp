#include <player.hpp>

Player::Player(sf::RenderWindow& win) : win_(win), windowSize(win.getSize()), player(win)
{
	player.load(TEX_PATH "player/player.png");
	spriteOrigin = { player.getSize().x / 2.0f ,player.getSize().y / 2.0f };
	pos = {windowSize.x / 2 , windowSize.y / 2 };
	player.setPosition(exchangeIF(pos));
	player.setScale(0.4);
	posToMap = { floor(pos.x / 100), floor(pos.y / 100) };
}

void Player::lookAt(const double& angle)
{
	this->angle = angle;
}

void Player::lookingAround()
{
	
	vec2f lookdir = exchangeIF(sf::Mouse::getPosition()) - pos;
	angle = atan2(lookdir.y, lookdir.x);
	player.setRotation(spriteOrigin, (angle * (180 / PI) + 90.0f));
}

void Player::setAmmo(const int& ammo)
{
	ammoSize = ammo;
}

void Player::move(Map& map)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && 7 > map[round(posToMap.x)][floor(posToMap.y - speed)] && map[round(posToMap.x)][floor(posToMap.y - speed)] > 1)
	{
		map.move(0.0, -speed);
		posToMap.y -=speed;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && 7 > map[round(posToMap.x)][ceil(posToMap.y + speed)] && map[round(posToMap.x)][ceil(posToMap.y + speed)] > 1)
	{
		map.move(0.0, speed);
		posToMap.y += speed;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && 7 > map[floor(posToMap.x - speed)][round(posToMap.y)] && map[floor(posToMap.x - speed)][round(posToMap.y)] > 1)
	{
		map.move(-speed, 0.0);
		posToMap.x -= speed;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && 7 > map[ceil(posToMap.x + speed)][round(posToMap.y)] && map[ceil(posToMap.x + speed)][round(posToMap.y)] > 1)
	{
		map.move(speed, 0.0);
		posToMap.x += speed;
	}
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

void Player::death()
{
	if (BasePlayerData::getHealth() <= 0)
	{
		player.setVisibility(false);
		Chest chest(win_, { (int)round(posToMap.x * 100), (int)round(posToMap.y * 100) });
		chest.draw();
	}
}

void Player::draw()
{
	player.draw();
}