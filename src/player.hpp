#pragma once

#include <Object.hpp>
#include <Profile.hpp>
#include <BaseDataPlayer.hpp>
#include <Bullet.hpp>
#include <map.hpp>
#include <cmath>

#define PI 3.141592653589793238462643383279502884197

class Player : virtual public Core::GameObject, virtual public BasePlayerData
{
private:
	vec2f windowSize;

	float speed = 5.0f;
	int ammoSize;
	Core::Eqiupment weapon;
	sf::RenderWindow& win_;
	sf::RectangleShape player;
	std::vector<Bullet> ammo;

public:
	Player(sf::RenderWindow& win);


	void lookAt(const double& angle);
	void move();
	void lookingAround();
	void setAmmo(int ammo);
	void fire();
	void shooting();

	virtual void draw();
};