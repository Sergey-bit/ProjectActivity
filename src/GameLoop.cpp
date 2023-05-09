#include <GameLoop.hpp>
#include <iostream>
#include <thread>

GameLoop::GameLoop() : 
	win_(sf::VideoMode::getDesktopMode(), "BattleRoyal", sf::Style::Fullscreen),
	currentFrame_(0)
{

}

void GameLoop::init()
{
	for (auto& frame : frames_)
	{
		frame->init();
	}
	run = false;
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
	sf::Thread thread(&GameLoop::init, this);

	BackSprite loadBack(win_);
	loadBack.load(TEX_PATH "LoadingBacks/Back1.png");

	Params p{ win_, loadBack, run };
	run = true;

	thread.launch();
	loadingWin_(p, vec3f(1, 0.09, 0.09));

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
