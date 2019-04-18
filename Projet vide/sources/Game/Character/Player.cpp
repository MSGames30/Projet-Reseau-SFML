#include "Player.h"
#include "../../Managers/ConnectManager.h"
#define DISCONNECT_DELAY 3.0f

Player::Player()
{
	isinGame = false;
	isHost = false;
	//ConnectManager::Instance()->sendMessage("-hello", sf::IpAddress::Broadcast);
	asBeenPinged = false;
	asReplyied = false;
	replyDelay.restart();
	isDisconnected = false;
}

Player::Player(bool _isInGame, bool _isHost, std::string _playerName, sf::IpAddress _playerIP, unsigned short _playerPort)
{
	isinGame = _isInGame;
	isHost = _isHost;
	playerName = _playerName;
	playerIP = _playerIP;
	playerPort = _playerPort;
	asBeenPinged = false;
	asReplyied = false;
	replyDelay.restart();
	isDisconnected = false;
}


Player::~Player()
{
}

void Player::setPlayerIdentity(std::string _playerIP, unsigned short _playerPort)
{
	playerIP = _playerIP;
	playerPort = _playerPort;
}

void Player::update()
{
	if (asBeenPinged)
	{
		if (replyDelay.getElapsedTime().asSeconds() > DISCONNECT_DELAY)
		{
			std::cout << "Timer depasse" << std::endl;
			if (asReplyied)
			{
				std::cout << "A repondu" << std::endl;
				asBeenPinged = false;
				isDisconnected = false;
				asReplyied = false;
			}
			else
			{
				std::cout << "N'a pas repondu" << std::endl;
				asBeenPinged = false;
				isDisconnected = true;
				asReplyied = false;
			}
		}
	}
}

void Player::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
}

sf::FloatRect Player::getGlobalBounds() const
{
	return sf::FloatRect();
}

void Player::setPlayerName(std::string _playerName)
{
	playerName = _playerName;
}

sf::IpAddress Player::getPlayerIP()
{
	return playerIP;
}

bool Player::getIsHost()
{
	return isHost;
}

bool Player::getIsInGame()
{
	if (isinGame == true)
	{
		std::cout << "IN" << std::endl;
	}
	return isinGame;
}

std::string Player::getPlayerName()
{
	return playerName;
}

void Player::setAsBeenPinged(bool _state)
{
	asBeenPinged = _state;
	if (_state)
	{
		replyDelay.restart();
	}
}

bool Player::getAsBeenPinged()
{
	return asBeenPinged;
}

bool Player::getIsDisconnected()
{
	return isDisconnected;
}

void Player::setAsReplyied(bool _state)
{
	asReplyied = _state;
}

void Player::setHostedGame(HostedGame & _hostedGame)
{
	isHost = true;
	isinGame = true;
	myHostedGame = &_hostedGame;
}
