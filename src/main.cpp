#define _CRT_SECURE_NO_WARNINGS

#include <SFML/Graphics.hpp>
#include <GameLoop.hpp>
#include <Achivments.hpp>
#include <StatisticMenu.h>
#include <MainMenu.hpp>
#include <iostream>
#include <loadingwin.hpp>

int main()
{
	GameLoop loop;
	loop.getWindow().setActive(false);

	BackSprite loadBack(loop.getWindow());
	loadBack.load(TEX_PATH "LoadingBacks/Back1.png");

	bool run = false;
	Params p = { loop.getWindow(), loadBack, run};

	sf::Thread load_(&loadingWin_, p);
	load_.launch();

	MainMenu menu(loop.getWindow());
	Achivments achiv(loop.getWindow());
	StatisticMenu statis(loop.getWindow());

	GameLoop::index menuIndex = loop.addFrame(&menu);
	GameLoop::index achivIndex = loop.addFrame(&achiv);
	GameLoop::index statisIndex = loop.addFrame(&statis);	

	loop.addTransfer({ menuIndex, menu.achivmentsPressed(), achivIndex });
	loop.addTransfer({ menuIndex, menu.statisticsPressed(), statisIndex });

	loop.addTransfer({ menuIndex, menu.statisticsPressed(), statisIndex });
	loop.addTransfer({ statisIndex, statis.escPressed(), menuIndex });
	loop.addTransfer({ achivIndex, achiv.exit(), menuIndex});

	run = true;
	load_.wait();
	loop.getWindow().setActive(true);
	
	loop.work();

	return EXIT_SUCCESS;
}