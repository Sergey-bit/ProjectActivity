#pragma once

#include <SFML/Graphics.hpp>
#include <player.hpp>
#include <map.hpp>
#include <Vector.hpp>
#include <Connection/Client.hpp>
#include <DynamicObjects.hpp>
#include <loadingwin.hpp>
#include <Frame.hpp>

class World final
{
private:
	sf::RenderWindow& win_;
	Map map_;
	Player player;
	std::vector<Chest*> chests;
	std::array<Player, 2> players;
	NetworkClient client;

	sf::Packet sendDataPacket;
	sf::Packet receiveDataPacket;

	sf::IpAddress serverIp;
	sf::Uint16 serverPort;

	bool started = true;
	bool closed = false;

	size_t playerInd = 100;

public:
	using Uint = unsigned int;

	World(sf::RenderWindow& win);

	virtual void work();
	virtual void init();

	void draw();
	bool isClosed() const;
	void setClosed(bool);
	
	bool isChestNearby();

	vec2f worldCoord(const vec2i& pos) const;

private:
	void waitingForGame();
};