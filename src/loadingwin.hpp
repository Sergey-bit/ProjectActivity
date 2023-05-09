#pragma once

#include <SFML/Graphics.hpp>
#include <Vector.hpp>
#include <BackSprite.hpp>

struct Params
{
	sf::RenderWindow& win;
	BackSprite& background;
	bool& run;
};

void loadingWin_(Params& p);