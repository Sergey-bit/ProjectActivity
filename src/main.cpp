#define _CRT_SECURE_NO_WARNINGS

#include <SFML/Graphics.hpp>
#include <GameLoop.hpp>
#include <Achivments.hpp>
#include <StatisticMenu.h>
#include <MainMenu.hpp>
#include <iostream>
#include <loadingwin.hpp>
#include <PlayingWithFriends.hpp>
#include <Registration.hpp>

int main()
{
	GameLoop loop;

	MainMenu menu(loop.getWindow());
	Achivments achiv(loop.getWindow());
	StatisticMenu statis(loop.getWindow());
	PlayingWithFriends PWF(loop.getWindow());
	Registration regis(loop.getWindow());

	GameLoop::index menuIndex = loop.addFrame(&menu);
	GameLoop::index achivIndex = loop.addFrame(&achiv);
	GameLoop::index statisIndex = loop.addFrame(&statis);	
	GameLoop::index PWFIndex = loop.addFrame(&PWF);
	GameLoop::index regisIndex = loop.addFrame(&regis);

	loop.addTransfer({ menuIndex, menu.achivmentsPressed(), achivIndex });
	loop.addTransfer({ menuIndex, menu.statisticsPressed(), statisIndex });
	loop.addTransfer({ menuIndex, menu.multiplayerPressed(), PWFIndex});
	loop.addTransfer({ menuIndex, menu.startPressed(), regisIndex});

	loop.addTransfer({ statisIndex, statis.escPressed(), menuIndex });
	loop.addTransfer({ achivIndex, achiv.exit(), menuIndex});
	loop.addTransfer({ PWFIndex, PWF.exit(), menuIndex});
	
	loop.work();
	return EXIT_SUCCESS;
}