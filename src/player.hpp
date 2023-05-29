#pragma once

#include <Object.hpp>
#include <Profile.hpp>
#include <Vector.hpp>
#include <cmath>

#define PI 3.141592653589793238462643383279502884197

class Player : virtual public Core::GameObject
{
private:
	vec2f pos_, lookdir, lookdirnorm, size;
	Profile& profile_;

	float angle_ = 0.f, speed = 5.0f;
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
	Player(sf::RenderWindow& win, Profile& profile);


	void lookAt(const float& angle);
	const float& getAngle() const;

	void move();
	void lookingAround();
	void tracking();
	void setAmmo(int ammo);
	void fire();
	void shooting();
	void collide();

	virtual void draw();
};