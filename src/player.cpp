#include <player.hpp>

Player::Player(sf::RenderWindow& win, Map& map) : win_(win), windowSize(win.getSize()), player(win), map(map)
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

void Player::move(Map& map, bool mode)
{
	if (!mode)
	{
		float s = speed * 100.f * map.getScale();
		const vec2f pSize{ 100.f * map.getScale(), 100.f * map.getScale() };
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && map.checkCollision({ (int)(pos.x - pSize.x / 2.f), (int)(pos.y - s - pSize.y / 2.f) }, pSize))
		{
			map.move(0.0, -speed);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && map.checkCollision({ (int)(pos.x - pSize.x / 2.f), (int)(pos.y + s - pSize.y / 2.f) }, pSize))
		{
			map.move(0.0, speed);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && map.checkCollision({ (int)(pos.x - s - pSize.x / 2.f), (int)(pos.y - pSize.y / 2.f) }, pSize))
		{
			map.move(-speed, 0.0);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && map.checkCollision({ (int)(pos.x + s - pSize.x / 2.f), (int)(pos.y - pSize.y / 2.f) }, pSize))
		{
			map.move(speed, 0.0);
		}
	}
}

void Player::fire()
{
	for (int i = 0; i < ammo.size(); i++)
	{
		float velocity = 100.0;
		if (ammo[i].type == 1)
			velocity = 100.0;
		if (ammo[i].type == 2)
			velocity = 300.f;
		if (ammo[i].type == 3)
			velocity = 300.0f;
		//std::cout << ammo[i].angle << std::endl;
		vec2f currVelocity = { cos(ammo[i].angle) * velocity, sin(ammo[i].angle) * velocity };
		ammo[i].object.move(currVelocity);
		win_.draw(ammo[i].object);
		//std::cout << ammo[i].object.getPosition().x << " " << ammo[i].object.getPosition().y;
		ammo[i].pos = ammo[i].object.getPosition() / 100.0f;
		if (ammo[i].object.getPosition().x < 0 || ammo[i].object.getPosition().x > windowSize.x
			|| ammo[i].object.getPosition().y < 0 || ammo[i].object.getPosition().y > windowSize.y)
			ammo.erase(ammo.begin() + i);
	}
}

void Player::shooting(Map& map)
{
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		ammo.push_back(Bullet());
		Bullet &bullet = ammo.back();
		bullet.object.setFillColor(sf::Color::Magenta);
		bullet.startPos = map.mapCoords({ (int)pos.x, (int)pos.y + 1 });
		bullet.object.setRadius(6);
		bullet.pos = { pos.x, pos.y + 1 };
		bullet.object.setPosition(bullet.pos);
		bullet.pos = bullet.startPos;
		bullet.angle = angle;
		if (weapon == Core::SHOTGUN)
			bullet.type = Core::shotgun;
		if (weapon == Core::RIFLE)
			bullet.type = Core::rifle;
		if (weapon == Core::UZI)
			bullet.type = Core::pistol;
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
	if (map.checkCollision({ (int)x(), (int)y() }, {100.0f, 100.0f}));
	player.draw();
}