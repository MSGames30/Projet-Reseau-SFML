#pragma once
#include "DrawableObject.h"
#include <SFML\Network.hpp>
#include <iostream>
#include "../../Tools/Enums.h"

class HostedGame :
	public DrawableObject
{
public:
	HostedGame();
	HostedGame(std::string _gameName,bool _isSkin_one,enums::TurretType _turretType);
	~HostedGame();
	virtual void update();
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	virtual sf::FloatRect getGlobalBounds() const;
	sf::UdpSocket& getSocket();
	unsigned short getPort();
	sf::IpAddress& getHostIp();
private:
	std::string gameName;
	int emptySlots;
	unsigned short port;
	sf::IpAddress hostIp;
	sf::UdpSocket newGameSocket;

	sf::RectangleShape gameBox;
	sf::Font* font;
	sf::Text gameNameText;
	sf::Text emptySlotsText;
	sf::Text portUsed;


	bool isSkin_one;
	enums::TurretType turretType;

	bool isSlot2avaible;
	bool isSlot3avaible;
	bool isSlot4avaible;
	bool isSlot5avaible;

};

