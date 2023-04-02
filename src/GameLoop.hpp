#pragma once

#include <vector>
#include <SFML/Graphics.hpp>
#include "Transfer.hpp"

class GameLoop final
{
public:
	using index = unsigned short int;

private:
	std::vector<Frame*> frames_;
	std::vector<Transfer> transfers_;

	sf::RenderWindow win_;
	index currentFrame_;

public:
	GameLoop();

	void addTransfer(const Transfer& transfer);
	index addFrame(Frame* frame);

	sf::RenderWindow& getWindow();
	vec2i getWinSize() const;
	void work();
};

