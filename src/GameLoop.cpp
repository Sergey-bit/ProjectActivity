#include "GameLoop.hpp"
#include <iostream>

GameLoop::GameLoop() : 
	win_(sf::VideoMode::getDesktopMode(), "BattleRoyal", sf::Style::Fullscreen),
	currentFrame_(0)
{

}

void GameLoop::addTransfer(const Transfer& transfer)
{
	transfers_.push_back(transfer);
}
GameLoop::index GameLoop::addFrame(Frame* frame)
{
	frames_.push_back(frame);
	return frames_.size() - 1;
}

void GameLoop::work()
{
	while (win_.isOpen())
	{
		sf::Event event;
		while (win_.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				win_.close();
			}
		}

		win_.clear();
		for (const auto& transfer : transfers_)
		{

			if (transfer.a == currentFrame_ && transfer.condition)
			{
				currentFrame_ = transfer.b;
				break;
			}
		}

		if (currentFrame_ < frames_.size())
		{
			frames_[currentFrame_]->work();
		}

		win_.display();
	}
}
sf::RenderWindow& GameLoop::getWindow()
{
	return win_;
}

vec2i GameLoop::getWinSize() const
{
	return exchangeIF<unsigned>(win_.getSize());
}
