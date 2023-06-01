#pragma once

#include <Object.hpp>
#include <BaseDataPlayer.hpp>
#include <Bullet.hpp>
#include <cmath>
#include <Chest.hpp>
#include <map.hpp>
#define PI 3.141592653589793238462643383279502884197

class Player : virtual public Core::GameObject, virtual public BasePlayerData
{
private:
	vec2f windowSize, spriteOrigin, posToMap;

	double speed = 0.02;
	int ammoSize = 0;
	Core::Eqiupment weapon;
	sf::RenderWindow& win_;
	BackSprite player;
	std::vector<Bullet> ammo;

public:
	Player(sf::RenderWindow& win);

	void lookAt(const double& angle);
	void move(Map& map);
	void lookingAround();
	void setAmmo(const int& ammo);
	void fire();
	void shooting();
	virtual void draw();
	void death();
};