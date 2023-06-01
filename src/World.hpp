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
	std::array<Player, 1> players;
	NetworkClient client;

	sf::Packet sendDataPacket;
	sf::Packet receiveDataPacket;

	sf::IpAddress serverIp;
	sf::Uint16 serverPort;

	bool started = true;
	bool closed = false;

public:
	World(sf::RenderWindow& win);

	virtual void work();
	virtual void init();

	void draw();
	bool isClosed() const;
	
	bool collide(const vec2f& pos);
	bool isChestNearby();

	vec2f worldCoord(const vec2i& pos) const;

private:
	void waitingForGame();
};