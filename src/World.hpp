#pragma once

#include <SFML/Graphics.hpp>
#include <player.hpp>
#include <map.hpp>
#include <Vector.hpp>
#include <Connection/Client.hpp>
#include <DynamicObjects.hpp>
#include <loadingwin.hpp>

class World
{
private:
	sf::RenderWindow& win_;
	Map map_;
	Player player;
	DynamicObjects objects;
	std::array<Player, 5> players;
	NetworkClient client;

	sf::Packet sendDataPacket;
	sf::Packet receiveDataPacket;

	sf::IpAddress serverIp;
	sf::Uint16 serverPort;

	bool started = true;

public:
	World(sf::RenderWindow& win);

	void draw();
	
	bool collide(const vec2f& pos) const;
	bool isChestNearby() const;

	vec2f worldCoord(const vec2i& pos) const;

private:
	void waitingForGame();
};