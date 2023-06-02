#pragma once

#include <World.hpp>
#include <chrono>
#include <thread>

World::World(sf::RenderWindow& win) : map_(win), player(win), win_(win),
serverIp("localhost"), serverPort(6666),
players{Player(win_), Player(win_)}
{
}

void World::waitingForGame()
{
	client.init();
	std::string name = "rtg";
	client.registerOnServer(serverIp, serverPort, name);

	bool came = false;

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
					came = true;
					std::string name;
					float x, y;

					receiveDataPacket >> name;
					receiveDataPacket >> x;
					receiveDataPacket >> y;

					player.setName(name);
					map_.move(x, y);
					player.healthMoves(100.0);


				}
				if (s == "CHEST" && came)
				{
					int n;
					started = false;
					receiveDataPacket >> n;
					for (int i = 0; i < n; i++)
					{
						int x, y;
						receiveDataPacket >> x >> y;
						chests.push_back(new Chest(win_, vec2i(x, y)));
						map_[(size_t)(x)][y] = Map::CHEST;
					}
				}
				if (s == "WAITING")
				{
					int x;
					receiveDataPacket >> x;
					continue;
				}
			}
		}
	}
}
void World::draw()
{
	map_.draw();
	player.draw();
	for (auto& p : players)
	{
		if (p.playerInd != player.playerInd)
		{
			if (p.getHealth() > 0) p.draw();
			else p.death();
		}
	}
	for (auto& chest : chests)
	{
		chest->draw();
		chest->work(map_);
	}
}
void World::setClosed(bool)
{
	closed = false;
}
void World::work()
{
	draw();
	sendDataPacket.clear();

	player.shooting(map_);
	player.fire();
	player.lookingAround();
	player.move(map_);

	for (auto& c : chests)
	{
		c->work(map_);
		c->getItem();
	}

	sendDataPacket << "POS";
	sendDataPacket << map_.getPos().x + player.x() / 100.f << map_.getPos().y + player.y() / 100.f << player.getAngle() << player.getHealth();
	if (player.ammo.size() > 0)
	{
		sendDataPacket << "BULLETS";
		sendDataPacket << player.ammo.size();
		for (const auto& bull : player.ammo)
		{
			sendDataPacket << bull.angle << bull.startPos.x << bull.startPos.y << bull.type <<
				bull.playerIndex << bull.pos.x << bull.pos.y;
		}
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape) || !player.getHealth())
	{
		sendDataPacket.clear();
		sendDataPacket << "DEAD" << player.x() << player.y();
		sendDataPacket << "DISCONNECT";
		if (client.sendData(sendDataPacket) == Status::Done)
		{
			sendDataPacket.clear();
			closed = true;
			started = true;
			map_.move(-map_.getPos().x, -map_.getPos().y);
			client.dataSocket.unbind();
			client.regSocket.disconnect();
		}
		return;
	}
	if (client.sendData(sendDataPacket) == Status::Done)
	{
		;
	}

	receiveDataPacket.clear();
	sendDataPacket.clear();

	if (client.receiveData(receiveDataPacket, serverIp, serverPort) == Status::Done)
	{
		std::string cmd;
		if (receiveDataPacket.getDataSize() > 0 && receiveDataPacket >> cmd)
		{
			std::cout << cmd << std::endl;
			if (cmd == "DEAD")
			{
				int n;
				receiveDataPacket >> n;

				players[n].healthMoves(-100);
			};
			if (cmd == "PLAYERS")
			{
				for (auto& p : players)
				{
					float x, y, angle, health;
					receiveDataPacket >> x;
					receiveDataPacket >> y;
					receiveDataPacket >> angle;
					receiveDataPacket >> health;

					std::cout << x << " " << y << " " << angle << std::endl;

					p.setX(x);
					p.setY(y);
					p.lookAt(angle);
					p.healthMoves(health);
				}
			}
			if (cmd == "BULLETS")
			{
				int n;

				receiveDataPacket >> n;
				vec2f p = map_.getPos() + vec2f(1.f * player.x(), 1.f * player.y());
				for (int i = 0; i < n; i++)
				{
					Bullet bull;
					int f;

					receiveDataPacket >> bull.angle >> bull.startPos.x >> bull.startPos.y >>
						f >> bull.playerIndex >> bull.pos.x >> bull.pos.y;
					bull.type = (Core::BulletType)f;
					if (bull.pos.x >= p.x - 0.5 && bull.pos.x <= p.x + 0.5 && bull.pos.y >= p.y - 0.5 &&
						bull.pos.y <= p.y + 0.5)
					{
						player.healthMoves(-5.0);
					}
					else
					{
						bull.object.setFillColor(sf::Color::Magenta);
						bull.object.setRadius(2.f);
						bull.object.setPosition(
							vec2f(map_.getScale() * 100.f * bull.pos.x, map_.getScale() * 100.f * bull.pos.y)
						);
						win_.draw(bull.object);
					}
				}
			}
		}
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