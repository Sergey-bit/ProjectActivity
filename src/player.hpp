#pragma once

#include <Object.hpp>
#include <BaseDataPlayer.hpp>
#include <Bullet.hpp>
#include <map.hpp>
#include <cmath>
#include <Chest.hpp>
#include <map.hpp>
#define PI 3.141592653589793238462643383279502884197

class Player : virtual public Core::GameObject, virtual public BasePlayerData
{
private:
	vec2f windowSize, spriteOrigin, posToMap;

	double speed = 0.025;
	int ammoSize = 0;
	Core::Eqiupment weapon = Core::SHOTGUN;
	sf::RenderWindow& win_;
	BackSprite player;


public:
	size_t playerInd = 1000;
	std::vector<Bullet> ammo;
	Player(sf::RenderWindow& win);

	void lookAt(const double& angle);
	void move(Map& map);
	void lookingAround();
	void setAmmo(const int& ammo);
	void fire();
	void shooting(Map& map);
	virtual void draw();

	void death();
};