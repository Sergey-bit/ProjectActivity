#include "Client.hpp"

NetworkClient::NetworkClient()
{
}

Status NetworkClient::init(unsigned short preferablePort)
{
	Status status = dataSocket.bind(preferablePort);

	if (status == Status::Done)
	{
		std::cout << "init(): Successfully binded to port: " << dataSocket.getLocalPort() << std::endl;
		return Status::Done;
	}
	else
	{
		std::cout << "(!)init(): Failed to bind passed preferred port\n";
		do
		{
			unsigned short newPort = sf::Socket::AnyPort;
			std::cout << "init(): Trying to bind other port - " << newPort << std::endl;
			status = dataSocket.bind(newPort);
			if (status != Status::Done)
				std::cout << "(!)init(): Failed to bind other port. Retrying...\n";

		} while (status != Status::Done);

		std::cout << "init(): Successfully binded to other port - " << dataSocket.getLocalPort() << std::endl;
		return Status::Done;
	}
}
Status NetworkClient::registerOnServer(sf::IpAddress serverIp, unsigned short serverRegPort, std::string clientName)
{
	if (connectRegTcpSocket(serverIp, serverRegPort) != Status::Done)
		return Status::Error;

	if (sendClientRecipientData(clientName) != Status::Done)
		return Status::Error;

	if (recieveDedicatedDataServerPort() != Status::Done)
		return Status::Error;

}
Status NetworkClient::blockReceiveData(sf::Packet& dataPacket, sf::IpAddress S_Ip, unsigned short S_dataPort)
{
	if (!dataSocket.isBlocking())dataSocket.setBlocking(true);
	Status s = dataSocket.receive(dataPacket, S_Ip, S_dataPort);
	if (s == Status::Done)
	{
		if (dataPacket.getDataSize() > 0)
		{
			//cout << "receiveData(): Data received\n";
			return Status::Done;
		}
		else
		{
			std::cout << "(!)receiveData(): Received packet is empty\n";
			return Status::Error;
		}
	}
	return Status::NotReady;
}
Status NetworkClient::receiveData(sf::Packet& dataPacket, sf::IpAddress S_Ip, unsigned short S_dataPor)
{
	if (dataSocket.isBlocking())dataSocket.setBlocking(false);
	Status s = dataSocket.receive(dataPacket, S_Ip, S_dataPort);
	if (s == Status::Done)
	{
		if (dataPacket.getDataSize() > 0)
		{
			//cout << "receiveData(): Data received\n";
			return Status::Done;
		}
		else
		{
			std::cout << "(!)receiveData(): Received packet is empty\n";
			return Status::Error;
		}
	}
	return Status::NotReady;
}
Status NetworkClient::sendData(sf::Packet dataPacket)
{
	if (sendRateTimer.getElapsedTime().asMilliseconds() > sendRate)
	{
		if (dataSocket.isBlocking())dataSocket.setBlocking(false);

		if (sendPacket.getDataSize() == 0) sendPacket = dataPacket;

		sf::IpAddress tempIp = S_Ip;
		unsigned short tempDataPort = S_dataPort;
		if (dataSocket.send(sendPacket, tempIp, tempDataPort) == Status::Done)
		{
			sendPacket.clear();
			sendRateTimer.restart();
			return Status::Done;
		}
		else return Status::NotReady;
	}
	else return Status::NotReady;
}

void NetworkClient::setSendFreq(sf::Int32 milliseconds)
{
	sendRate = milliseconds;
}
Status NetworkClient::connectRegTcpSocket(sf::IpAddress serverIp, unsigned short serverRegPort)
{
	if (!regSocket.isBlocking()) regSocket.setBlocking(true);

	if (regSocket.connect(serverIp, serverRegPort, sf::seconds(10)) == Status::Done)
	{
		std::cout << "connectRegTcpSocket(): Connected to server\n";
		S_Ip = serverIp;
		S_dataPort = serverRegPort;
		return Status::Done;
	}
	else
	{
		std::cout << "(!)connectRegTcpSocket(): Error connecting to server!\n";
		return Status::Error;
	}
}

Status NetworkClient::sendClientRecipientData(std::string clientName)
{
	if (!regSocket.isBlocking()) regSocket.setBlocking(true);

	sf::Packet tempPacket;
	tempPacket << clientName << static_cast<sf::Uint16>(dataSocket.getLocalPort());
	if (regSocket.send(tempPacket) == Status::Done)
	{
		std::cout << "sendClientRecipientData(): Successfully sent client recipient data\n";
		return Status::Done;
	}
	else
	{
		std::cout << "(!)sendClientRecipientData(): Failed to send client recipient data\n";
		return Status::Error;
	}
}
Status NetworkClient::recieveDedicatedDataServerPort()
{
	if (!regSocket.isBlocking()) regSocket.setBlocking(true);

	sf::Packet tempPacket;

	if (regSocket.receive(tempPacket) == Status::Done)
	{
		if (tempPacket.getDataSize() > 0)
		{
			if (tempPacket.getDataSize() == sizeof(sf::Uint16))
			{
				if (tempPacket >> S_dataPort)
				{
					std::cout << "recieveDedicatedDataServerPort(): Successfully received data client-dedicated port of a server - " << S_dataPort << std::endl;
					return Status::Done;
				}
				else std::cout << "(!)recieveDedicatedDataServerPort(): Failed to read from received packet\n";
			}
			else std::cout << "(!)recieveDedicatedDataServerPort(): Invalid packet size, ensure that server sends only Uint16 var\n";
		}
		else std::cout << "(!)recieveDedicatedDataServerPort(): Received packet is empty\n";
	}
	else std::cout << "(!)recieveDedicatedDataServerPort(): Failed to receive client-dedicated port of a server\n";

	return Status::Error;
}