#pragma once

#include <Object.hpp>
#include <Profile.hpp>
#include <Vector.hpp>
#include <cmath>

#define PI 3.141592653589793238462643383279502884197

class Player : virtual public Core::GameObject
{
private:
	vec2f pos_, lookdir, size;
	Profile& profile_;

	float angle_ = 0.f, speed = 0.5f;
	sf::RenderWindow& win_;
	sf::RectangleShape player;
	sf::VertexArray line;

public:
	Player(sf::RenderWindow& win, Profile& profile);


	void lookAt(const float& angle);
	const float& getAngle() const;

	void move();
	void lookingAround();
	void tracking();

	virtual void draw();
};