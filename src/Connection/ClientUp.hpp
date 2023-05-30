#pragma once

#include <player.hpp>


class Client
{
private:
	using vectorOfPlayers = std::vector<std::pair<Player, sf::Uint16>>;
private:
	Client();

public:
	static Client& getInstance();
	const vectorOfPlayers& getPlayers() const;

private:
	vectorOfPlayers players_;


};