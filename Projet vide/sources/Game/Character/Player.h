#pragma once
#include "../Entities/DrawableObject.h"
#include <SFML\Network.hpp>
#include "../../Game/Entities/HostedGame.h"

class Player :
	public DrawableObject
{
public:
	Player();
	Player(bool _isInGame,bool _isHost,std::string _playerName,sf::IpAddress _playerIP,unsigned short _playerPort);
	~Player();
	void setPlayerIdentity( std::string _playerIP, unsigned short _playerPort);
	virtual void update();
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	virtual sf::FloatRect getGlobalBounds() const;
	void setPlayerName(std::string _playerName);
	sf::IpAddress getPlayerIP();
	bool getIsHost();
	bool getIsInGame();
	std::string getPlayerName();

	void setAsBeenPinged(bool _state);
	bool getAsBeenPinged();
	bool getIsDisconnected();

	void setAsReplyied(bool _state);
	void setHostedGame(HostedGame& _hostedGame);
private:
	std::string playerName;
	sf::IpAddress playerIP;
	unsigned short playerPort;
	//bool isLogged;
	bool isinGame;
	bool isHost;

	bool asBeenPinged;
	bool asReplyied;
	bool isDisconnected;
	sf::Clock replyDelay;

	HostedGame* myHostedGame;
};

