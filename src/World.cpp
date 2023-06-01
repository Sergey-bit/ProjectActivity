#pragma once

#include <World.hpp>

World::World(sf::RenderWindow& win) : map_(win), player(win), win_(win),
serverIp("25.34.39.164"), serverPort(6666),
players{Player(win_), Player(win_) ,Player(win_) ,Player(win_) ,Player(win_)}
{
	sf::Thread thread(&World::waitingForGame, this);
	BackSprite loadBack(win_);

	loadBack.load(TEX_PATH "LoadingBacks/Back2.png");
	Params p{ win_, loadBack, started };

	thread.launch();
	loadingWin_(p, vec3f(0.09, 0.09, 1.0));
}

void World::waitingForGame()
{
	client.init();
	client.registerOnServer(serverIp, serverPort, "Jkfbd");

	bool came = false;

	while (started)
	{
		sendDataPacket.clear();
		sendDataPacket << "START";
		client.sendData(sendDataPacket);
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

}

bool World::collide(const vec2f& pos) const
{

}
bool World::isChestNearby() const
{

}

vec2f World::worldCoord(const vec2i& pos) const
{
	return vec2f(pos.x / 100.0, pos.y / 100.0);
}