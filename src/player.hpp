#pragma once

#include <Object.hpp>
#include <Profile.hpp>
#include <Vector.hpp>
#include <BaseDataPlayer.hpp>
#include <cmath>

#define PI 3.141592653589793238462643383279502884197

class Player : virtual public Core::GameObject, virtual public BasePlayerData
{
private:
	vec2f lookdir, lookdirnorm, size;

	float speed = 5.0f;
	int ammoSize;
	sf::RenderWindow& win_;
	sf::RectangleShape player;
	sf::VertexArray line;

	struct Bullet
	{
		vec2f pos_, currVelocity;
		float velocity = 60;
		sf::CircleShape object;
	};
	std::vector<Bullet> ammo;

public:
	Player(sf::RenderWindow& win);


	void lookAt(const double& angle);
	void move();
	void lookingAround();
	void tracking();
	void setAmmo(int ammo);
	void fire();
	void shooting();
	void collide();

	virtual void draw();
};