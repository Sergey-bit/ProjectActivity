#pragma once

#include <Connection/ClientUp.hpp>

Client& Client::getInstance()
{
	static Client client = Client();
	return client;
}
const Client::vectorOfPlayers& Client::getPlayers() const
{
	return players_;
}