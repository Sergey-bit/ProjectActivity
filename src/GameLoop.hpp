#pragma once

#include <vector>
#include <SFML/Graphics.hpp>
#include <Transfer.hpp>
#include <loadingwin.hpp>
#include <Profile.hpp>

class GameLoop final
{
public:
	using index = unsigned short int;

private:
	std::vector<Frame*> frames_;
	std::vector<Transfer> transfers_;

	sf::RenderWindow win_;
	index currentFrame_;

	Profile profile_;
	bool run = false;

public:
	GameLoop();
	void init();

	void addTransfer(const Transfer& transfer);
	index addFrame(Frame* frame);

	Profile& getProfile();
	const Profile& getProfile() const;

	sf::RenderWindow& getWindow();
	vec2i getWinSize() const;
	void work();
};

