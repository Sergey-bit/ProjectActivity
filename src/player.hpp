#pragma once

#include <Object.hpp>
#include <Profile.hpp>
#include <Vector.hpp>
#include <cmath>

#define PI 3.141592653589793238462643383279502884197

class Player : virtual public Core::GameObject
{
private:
	vec2i pos_;
	Profile& profile_;

	float angle_ = 0.f;
	sf::RenderWindow& win_;

public:
	Player(sf::RenderWindow& win, Profile& profile);

	void lookAt(const float& angle);
	const float& getAngle() const;

	void move();
	void lookingAround();

	virtual void draw();
};