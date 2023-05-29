#pragma once

#include <ServerUDP.h>
#include <Vector.hpp>
#include <player.hpp>
#include <Log.h>
#include <map>

class ShooterServer final : public ServerUDP {
private:
    std::map<sf::Uint16, std::shared_ptr<Player>> _players{};
public:
    ShooterServer() = default;

    void broadcast() override;

    void processConnect(sf::Uint16 senderId) override;

    void processClientUpdate(sf::Uint16 senderId, sf::Packet& packet) override;

    void processDisconnect(sf::Uint16 senderId) override;

    void processCustomPacket(sf::Packet& packet, sf::Uint16 senderId) override;

    void processStop() override;

    void generateBonuses();

    void updateInfo() override;

    ~ShooterServer() override;
};