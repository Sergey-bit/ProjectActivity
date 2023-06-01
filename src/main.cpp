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
#include <map.hpp>
#include <Chest.hpp>

#define SPEED 0.5
#define SCALE_SPEED 0.05

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

//int main() {
//	sf::RenderWindow window(sf::VideoMode::getDesktopMode(), "map", sf::Style::Fullscreen);
//	Map map(window);
//
//	Chest chest(window,{0,0});
//	chest.toStrData();
//	
//	while (window.isOpen())
//	{
//		sf::Event event;
//		while (window.pollEvent(event))
//		{
//			if (event.type == sf::Event::Closed)
//			{
//				window.close();
//			}
//			if (event.type == sf::Event::MouseWheelScrolled)
//			{
//				map.setScale(map.getScale() + ((event.mouseWheelScroll.delta > 0) ? 1 : -1) * SCALE_SPEED);
//			}
//			if (event.type == sf::Event::KeyPressed)
//			{
//				if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
//				{
//					map.move(-SPEED, 0.0);
//				}
//				if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
//				{
//					map.move(0.0, -SPEED);
//				}
//				if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
//				{
//					map.move(0.0, SPEED);
//				}
//				if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
//				{
//					map.move(SPEED, 0.0);
//				}
//				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
//				{
//					window.close();
//				}
//			}
//
//		}
//
//		window.clear();
//		map.draw();
//		window.display();
//	}
//
//	return 0;
//}