#pragma once

#include <World.hpp>

World::World(sf::RenderWindow& win) : map_(win), player(win), win_(win),
serverIp("localhost"), serverPort(51784),
players{Player(win_)}
{
}

void World::waitingForGame()
{
	client.init();
	client.registerOnServer(serverIp, serverPort, "Jkfbd");

	//bool came = false;

	while (started)
	{
		sendDataPacket.clear();
		if (client.receiveData(receiveDataPacket, serverIp, serverPort) == Status::Done)
		{
			std::string s;
			if (receiveDataPacket >> s)
			{
				if (s == "START")
				{
					started = false;

					for (auto& p : players)
					{
	
						std::string name;
						int x, y;

						receiveDataPacket >> name;
						receiveDataPacket >> x;
						receiveDataPacket >> y;
						
						p.setName(name);

						p.setX(x * 100);
						p.setY(y * 100);
						p.healthMoves(100.0);

						if (name == player.getName())
						{
							player.setX(p.x());
							player.setY(p.y());
						}
					}
				}
			}
		}
	}
}
void World::draw()
{
	map_.draw();
	for (auto& p : players)
	{
		p.draw();
		p.lookingAround();
		p.move();
	}
}
void World::work()
{
	draw();
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
	{
		closed = true;
	}
}
void World::init()
{
	sf::Thread thread(&World::waitingForGame, this);
	BackSprite loadBack(win_);

	loadBack.load(TEX_PATH "LoadingBacks/Back2.png");
	Params p{ win_, loadBack, started };

	thread.launch();
	loadingWin_(p, vec3f(0.09, 0.09, 1.0));
}

bool World::collide(const vec2f& pos) const
{
	vec2f mapCoord = worldCoord({ (int)pos.x, (int)pos.y });
	return (4 <= map_[(size_t)(mapCoord.x)][(int)mapCoord.y] <= 2 +
		4 <= map_[(size_t)(mapCoord.x + 1)][(int)mapCoord.y + 1] <= 2);
}
bool World::isChestNearby()
{
	vec2i xy = exchangeIF<float>(worldCoord({ (int)player.x(), (int)player.y() }));
	bool there = false;

	for (int i = -1; i <= 1; i++)
	{
		for (int j = -1; j <= 1; j++)
		{
			if (i && j && map_[(size_t)(xy.x + i)][xy.y + j] == Map::CHEST)
			{
				there = true;
				break;
			}
		}
		if (there)
		{
			break;
		}
	}
	return there;
}
vec2f World::worldCoord(const vec2i& pos) const
{
	return vec2f(pos.x / 100.0, pos.y / 100.0);
}
bool World::isClosed() const
{
	bool res = closed;
	return res;
}