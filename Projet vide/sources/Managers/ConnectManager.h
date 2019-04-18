#pragma once
#include "../Templates/Singleton.h"
#include <SFML\Network.hpp>
#include <string>
#include <vector>
#include "../Game/Character/Player.h"

#define MY_UDP_PORT (unsigned short)9600 
//constexpr auto MY_UDP_PORT = (unsigned short)9600;



class ConnectManager :
	public Singleton <ConnectManager>
{
public:
	ConnectManager();
	~ConnectManager();
	bool init();
	bool sendMessage(std::string _stringToSend,sf::IpAddress _destIP);
	bool sendMessage(bool _isInGame, bool _isHost, std::string _playerName, sf::IpAddress _destIP);
	bool receiveMessage(Player& _myPlayer);
	std::vector<Player*>& getConnectedPlayers();
	std::vector<Player*>& getInGamePlayers();

private:
	sf::UdpSocket mySocket;
	sf::Packet packetToSend;
	sf::Packet packetToReceive;
	std::vector<Player*> connectedPlayers;
	std::vector<Player*> inGamePlayers;
	sf::Clock pingDelay;
};

