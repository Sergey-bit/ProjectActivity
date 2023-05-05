#define _CRT_SECURE_NO_WARNINGS

#include <SFML/Graphics.hpp>
#include <GameLoop.hpp>
#include <Achivments.hpp>
#include <StatisticMenu.h>
#include <MainMenu.hpp>
#include <iostream>

int main()
{
	GameLoop loop;

	Achivments achiv(loop.getWindow());
	StatisticMenu statis(loop.getWindow());
	MainMenu menu(loop.getWindow());

	GameLoop::index achivIndex = loop.addFrame(&achiv);
	GameLoop::index statisIndex = loop.addFrame(&statis);
	GameLoop::index menuIndex = loop.addFrame(&menu);

	loop.addTransfer({ menuIndex, menu.achivmentsPressed(), achivIndex });
	loop.addTransfer({ achivIndex, menu.statisticsPressed(), statisIndex });

	loop.addTransfer({ menuIndex, menu.statisticsPressed(), statisIndex });
	loop.addTransfer({ statisIndex, statis.escPressed(), menuIndex });

	return EXIT_SUCCESS;
}