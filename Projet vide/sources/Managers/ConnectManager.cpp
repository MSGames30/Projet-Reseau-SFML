#include "ConnectManager.h"
#define PING_DELAY 1.0f


ConnectManager::ConnectManager()
{
	
}


ConnectManager::~ConnectManager()
{
}

bool ConnectManager::init()
{
	if (mySocket.bind(MY_UDP_PORT) != mySocket.Done)
	{
		return false;
	}
	else
	{
		mySocket.setBlocking(false);
		return true;
	}
}

bool ConnectManager::sendMessage(std::string _stringToSend, sf::IpAddress _destIP)
{
	packetToSend.clear();
	packetToSend << _stringToSend;
	if (mySocket.send(packetToSend, _destIP, MY_UDP_PORT) != sf::Socket::Done)
	{
		///DEBUG
		std::string tempString;
		packetToSend >> tempString;
		std::cout << "Commande non envoye : " << tempString << std::endl;
		///END DEBUG
		return false;
	}
	else
	{
		///DEBUG
		std::string tempString;
		packetToSend >> tempString;
		std::cout << "Commande envoyee : " << tempString << std::endl;
		///END DEBUG
		return true;
	}
	pingDelay.restart();
}

bool ConnectManager::sendMessage(bool _isInGame, bool _isHost, std::string _playerName, sf::IpAddress _destIP)
{
	packetToSend.clear();
	packetToSend << _playerName << _isInGame << _isHost;
	if (mySocket.send(packetToSend, _destIP, MY_UDP_PORT) != sf::Socket::Done)
	{
		///DEBUG
		std::string tempString;
		packetToSend >> tempString;
		std::cout << "Donnees non envoyees" << std::endl;
		///END DEBUG
		return false;
	}
	else
	{
		///DEBUG
		std::string tempString;
		packetToSend >> tempString;
		std::cout << "Donnees envoyees : " << tempString << std::endl;
		///END DEBUG
		return true;
	}
}

bool ConnectManager::receiveMessage(Player& _myPlayer)
{
	//mySocket.setBlocking(false);
	packetToReceive.clear();
	bool tmpIsInGame;
	bool tmpIsHost;
	std::string tmpPlayerName;
	sf::IpAddress tmpPlayerIP;
	unsigned short tmpPlayerPort;
	//std::cout << "IN RECV" << std::endl;
	if (mySocket.receive(packetToReceive, tmpPlayerIP, tmpPlayerPort) != sf::Socket::Done)
	{
		//std::cout << "OUT RECV" << std::endl;
		return false;
	}
	else
	{
		bool isAlreadyInList = false;
		std::string command;
		packetToReceive >> command;
		//std::cout << "Packet name recv : " << command << std::endl;
		//if (tmpPlayerIP != sf::IpAddress::getLocalAddress())
		//{
			if (command == "-hello")
			{
				//std::cout << "Envoie de mes donnees" << std::endl;
				ConnectManager::Instance()->sendMessage(_myPlayer.getIsInGame(), _myPlayer.getIsHost(), _myPlayer.getPlayerName(), tmpPlayerIP);
				return false;
			}
			else if (command == "-echo")
			{
				ConnectManager::Instance()->sendMessage("-echoOK", tmpPlayerIP);
			}
			else if (command == "-echoOK")
			{
				std::cout << "-echoOk recieved" << std::endl;
				for (int i = 0; i < connectedPlayers.size(); i++)
				{
					if (connectedPlayers[i]->getPlayerIP() == tmpPlayerIP)
					{
						connectedPlayers[i]->setAsReplyied(true);
					}
				}
			}
			else if (command != "-hello")
			{
				tmpPlayerName = command;
				packetToReceive >> tmpIsInGame >> tmpIsHost ;
				for (int i = 0; i < connectedPlayers.size(); i++)
				{
					if (connectedPlayers[i]->getPlayerIP() == tmpPlayerIP)
					{
						//if (connectedPlayers[i]->getIsHost() || connectedPlayers[i]->getIsInGame())
						//{
						//	inGamePlayers.push_back(connectedPlayers[i]);
						//	connectedPlayers.erase(connectedPlayers.begin() + i);
						//}
						isAlreadyInList = true;
						break;
					}
				}
				if (!isAlreadyInList)
				{
					connectedPlayers.push_back(new Player(tmpIsInGame, tmpIsHost, tmpPlayerName, tmpPlayerIP, tmpPlayerPort));
					std::cout << "Player : " << tmpPlayerName << " is added" << std::endl;
					return true;
				}
			}
		//}
	}
	//std::cout << "OUT RECV" << std::endl;
	if (pingDelay.getElapsedTime().asSeconds() > PING_DELAY)
	{
		for (int i = 0; i < connectedPlayers.size(); i++)
		{
			if (!connectedPlayers[i]->getAsBeenPinged())
			{
				connectedPlayers[i]->setAsBeenPinged(true);
				ConnectManager::Instance()->sendMessage("-echo", connectedPlayers[i]->getPlayerIP());
			}
		}
		pingDelay.restart();
	}
	for (int i = 0; i < connectedPlayers.size(); i++)
	{
		connectedPlayers[i]->update();
	}
	for (int i = 0; i < connectedPlayers.size(); i++)
	{
		if (connectedPlayers[i]->getIsDisconnected())
		{
			connectedPlayers.erase(connectedPlayers.begin() + i);
			break;
		}
	}
	//for (int i = 0; i < inGamePlayers.size(); i++)
	//{
	//	inGamePlayers[i]->update();
	//}
	//for (int i = 0; i < inGamePlayers.size(); i++)
	//{
	//	if (inGamePlayers[i]->getIsDisconnected())
	//	{
	//		inGamePlayers.erase(connectedPlayers.begin() + i);
	//		break;
	//	}
	//}
}

std::vector<Player*>& ConnectManager::getConnectedPlayers()
{
	return connectedPlayers;
}

std::vector<Player*>& ConnectManager::getInGamePlayers()
{
	return inGamePlayers;
}
