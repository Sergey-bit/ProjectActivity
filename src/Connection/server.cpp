#include <Connection/server.hpp>

void ShooterServer::broadcast() {
    sf::Packet updatePacket;
    updatePacket << MsgType::ServerUpdate;

    for (auto& [playerId, player] : _players) {
        updatePacket << playerId << player->position().x() << player->position().y() << player->position().z()
            << player->health() << player->angle().y() << player->headAngle() << player->playerNickName();
    }

    for (auto& player : _players) {
        _socket.send(updatePacket, player.first);
    }
}


void ShooterServer::processConnect(sf::Uint16 targetId) {
    sf::Packet sendPacket1, sendPacket2;
    sf::Packet extraPacket;

    // players init
    extraPacket << MsgType::NewClient << targetId;
    sendPacket1 << MsgType::Init << targetId;
    _players.insert({ targetId, std::make_shared<Player>(ObjectNameTag("Player_" + std::to_string(targetId))) });
    for (const auto& [playerId, player] : _players) {
        sendPacket1 << playerId << player->position().x() << player->position().y() << player->position().z()
            << player->health() << player->kills() << player->deaths();
        if (playerId != targetId)
            _socket.sendRely(extraPacket, playerId);
    }
    _socket.sendRely(sendPacket1, targetId);

    // bonuses init
    sendPacket2 << MsgType::Custom << ShooterMsgType::InitBonuses;
    for (auto& [bonusName, bonusInfo] : _bonuses) {
        if (bonusInfo->onTheMap) {
            sendPacket2 << bonusName << bonusInfo->position.x() << bonusInfo->position.y() << bonusInfo->position.z();
        }
    }
    _socket.sendRely(sendPacket2, targetId);

}

void ShooterServer::processClientUpdate(sf::Uint16 senderId, sf::Packet& packet) {
    double x, y, z, angleBody, headAngle;

    std::string playerName;

    packet >> x >> y >> z >> angleBody >> headAngle >> playerName;

    _players.at(senderId)->translateToPoint(vec2i{ x, y, z });
    _players.at(senderId)->rotateToAngle(vec2i{ 0, angleBody, 0 });
    _players.at(senderId)->setHeadAngle(headAngle);
    _players.at(senderId)->setPlayerNickName(playerName);
}

void ShooterServer::processDisconnect(sf::Uint16 senderId) {
    sf::Packet sendPacket;

    sendPacket << MsgType::Disconnect << senderId;
    _players.erase(senderId);
    for (const auto& player : _players) {
        _socket.sendRely(sendPacket, player.first);
    }
}


void ShooterServer::processCustomPacket(sf::Packet& packet, sf::Uint16 senderId) {
    sf::Packet sendPacket;
    double dbuff[10];
    sf::Uint16 targetId;
    double damage;
    std::string tmp;
    double newHealth;
    std::string message;

    ShooterMsgType type;
    packet >> type;

    switch (type) {
    case ShooterMsgType::Damage:
        packet >> targetId >> damage;
        newHealth = _players[targetId]->health() - damage;
        if (newHealth > 0) {
            _players[targetId]->setHealth(newHealth);
        }
        else {
            _players[targetId]->setFullHealth();
            _players[targetId]->setFullAbility();
            _players[targetId]->addDeath();
            _players[senderId]->addKill();

            sendPacket << MsgType::Custom << ShooterMsgType::Kill << targetId << senderId;
            for (auto& player : _players)
                _socket.sendRely(sendPacket, player.first);
        }
        break;
    case ShooterMsgType::FireTrace:
        packet >> dbuff[0] >> dbuff[1] >> dbuff[2] >> dbuff[3] >> dbuff[4] >> dbuff[5];
        sendPacket << MsgType::Custom << ShooterMsgType::FireTrace << dbuff[0] << dbuff[1] << dbuff[2] << dbuff[3]
            << dbuff[4] << dbuff[5];
        for (auto& player : _players) {
            if (player.first != senderId) {
                _socket.send(sendPacket, player.first);
            }
        }

        break;
    case ShooterMsgType::RemoveBonus:
        packet >> tmp;

        if (tmp.find("Bonus_hill") != std::string::npos) {
            _players[senderId]->setFullHealth();
        }
        if (tmp.find("Bonus_ability") != std::string::npos) {
            _players[senderId]->setFullAbility();
        }

        _bonuses[tmp] = std::make_shared<BonusInfo>(BonusInfo{ _bonuses[tmp]->position, Time::time(), false });

        sendPacket << MsgType::Custom << ShooterMsgType::RemoveBonus << tmp;
        for (auto& player : _players) {
            if (player.first != senderId) {
                _socket.sendRely(sendPacket, player.first);
            }
        }
        break;
    case ShooterMsgType::ChangeWeapon:
        packet >> tmp;
        sendPacket << MsgType::Custom << ShooterMsgType::ChangeWeapon << senderId << tmp;

        for (auto& player : _players) {
            if (player.first != senderId) {
                _socket.sendRely(sendPacket, player.first);
            }
        }

        break;
    case ShooterMsgType::newMessage:

        packet >> message;
        sendPacket << MsgType::Custom << ShooterMsgType::newMessage << _players[senderId]->playerNickName() << message;
        if (message.length() == 0)
            break;
        for (auto& player : _players) {
            if (player.first != senderId) {
                _socket.send(sendPacket, player.first);
            }
        }
        break;
    default:
        Log::log("ShooterServer::processCustomPacket: unknown message type " +
            std::to_string(static_cast<int>(type)));
        return;
    }
}

void ShooterServer::processStop() {
    _players.clear();
    _bonuses.clear();
}

void ShooterServer::generateBonuses() {
    
}

void ShooterServer::updateInfo() {

}

ShooterServer::~ShooterServer() {
    processStop();
}