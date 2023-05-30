#define _CRT_SECURE_NO_WARNINGS

#include <SFML/Graphics.hpp>
#include <GameLoop.hpp>
#include <Achivments.hpp>
#include <StatisticMenu.h>
#include <MainMenu.hpp>
#include <iostream>
#include <loadingwin.hpp>
#include <Registration.hpp>
#include <Profile.hpp>

int main()
{
	GameLoop loop;

	MainMenu menu(loop.getWindow());
	Achivments achiv(loop.getWindow());
	StatisticMenu statis(loop.getWindow());
	Registration regis(loop.getWindow(), loop.getProfile());

	GameLoop::index regisIndex = loop.addFrame(&regis);
	GameLoop::index menuIndex = loop.addFrame(&menu);
	GameLoop::index achivIndex = loop.addFrame(&achiv);
	GameLoop::index statisIndex = loop.addFrame(&statis);

	loop.addTransfer({ menuIndex, menu.achivmentsPressed(), achivIndex });
	loop.addTransfer({ menuIndex, menu.statisticsPressed(), statisIndex });
	
	loop.addTransfer({ statisIndex, statis.escPressed(), menuIndex });
	loop.addTransfer({ achivIndex, achiv.exit(), menuIndex});
	loop.addTransfer({ regisIndex, regis.autorized(), menuIndex});

	

		
	loop.work();
	return EXIT_SUCCESS;
}