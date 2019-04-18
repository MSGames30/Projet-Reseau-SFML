#include "Player.h"
//#include "../../Managers/ConnectManager.h"


Player::Player()
{
	isinGame = false;
	isHost = false;
	//ConnectManager::Instance()->sendMessage("hello", sf::IpAddress::Broadcast);
}

Player::Player(bool _isInGame, bool _isHost, std::string _playerName, sf::IpAddress _playerIP, unsigned short _playerPort)
{
	isinGame = _isInGame;
	isHost = _isHost;
	playerName = _playerName;
	playerIP = _playerIP;
	playerPort = _playerPort;
	
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
	if (turret != nullptr)
		turret->update(slot);

	//std::cout << "update player" << std::endl;
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

void Player::initTurret(enums::TurretType ptype, enums::TurretSlot pslot)
{
	slot = pslot;
	type = ptype;
}

enums::TurretType Player::getType()
{
	return type;
}

enums::TurretSlot Player::getSlot()
{
	return slot;
}

void Player::setTurret(Turret * pturret)
{
	turret = pturret;
}
