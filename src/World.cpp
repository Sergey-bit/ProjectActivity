#pragma once

#include <World.hpp>

World::World(sf::RenderWindow& win) : map_(win), player(win), win_(win),
<<<<<<< HEAD
serverIp("localhost"), serverPort(57038),
=======
serverIp("25.34.39.164"), serverPort(56213),
>>>>>>> 4b2edb78378e8f024c4274857338fae6f079350c
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
					std::string name;
					int x, y;

					receiveDataPacket >> name;
					receiveDataPacket >> x;
					receiveDataPacket >> y;
						
					player.setName(name);

					player.setX(x * 100);
					player.setY(y * 100);
					player.healthMoves(100.0);

					receiveDataPacket >> s;
					int n;
					receiveDataPacket >> n;
					for (int i = 0; i < n; i++)
					{
						int x, y;
						receiveDataPacket >> x >> y;
						chests.push_back(new Chest(win_, vec2i(x * 100, y * 100)));
						map_[(size_t)(x)][y] = Map::CHEST;
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
<<<<<<< HEAD
		p.move();
		collide({ p.x(), p.y() });
=======
		p.move(map_);
>>>>>>> 4b2edb78378e8f024c4274857338fae6f079350c
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

bool World::collide(const vec2f& pos)
{
	vec2f mapCoord = worldCoord({ (int)pos.x, (int)pos.y });
	return ((4 <= map_[(size_t)(mapCoord.x)][(int)mapCoord.y] <= 2 +
		4 <= map_[(size_t)(mapCoord.x + 1)][(int)mapCoord.y + 1] <= 2) == 2) ;
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