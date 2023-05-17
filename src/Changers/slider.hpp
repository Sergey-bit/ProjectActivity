#pragma once

#include <Changers/changer.hpp>
#include <BackSprite.hpp>

class HorizontalSlider : virtual public Changer
{
private:
	sf::RenderWindow& win_;

	sf::Sprite sprite_;
	float value_;

public:
	HorizontalSlider(sf::RenderWindow& win, const vec2i& pos = { 0, 0 }, const vec2i& size = { 1, 1 }, const int& value = 0);
	~HorizontalSlider();

	virtual void draw();
	virtual float getValue() const;

	virtual void setFrShader(const std::string& filename);
};

