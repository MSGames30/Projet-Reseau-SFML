#pragma once
#include "../Entities/DrawableObject.h"
#include <SFML\Network.hpp>
#include "Tank/Turret.h"
//#include "../../Tools/Enums.h"
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

	void initTurret(enums::TurretType ptype, enums::TurretSlot pslot);

	enums::TurretType getType();
	enums::TurretSlot getSlot();

	void setTurret(Turret *pturret);

private:
	std::string playerName;
	sf::IpAddress playerIP;
	unsigned short playerPort;
	//bool isLogged;
	bool isinGame;
	bool isHost;


	enums::TurretType type;
	enums::TurretSlot slot;
	Turret *turret;
};

