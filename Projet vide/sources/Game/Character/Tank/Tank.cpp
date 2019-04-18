#include "Tank.h"
#include <iostream>
#include "../../Hud/elementHud.h"

Tank::Tank()
{
	//Rectangle/Sprite
	texture.loadFromFile("resources/textures/TankBleu.png");
	sprite.setTexture(texture);
	this->setOrigin(this->getGlobalBounds().width / 2, this->getGlobalBounds().height / 2);

	//Variables//
	///movement
	this->speed = 0;
	this->direction = { 0,0 };
	this->angleRotation = 0;

	///slot aviable for turret
	this->slot_1_Empty = false;
	this->slot_2_Empty = false;
	this->slot_3_Empty = false;
	this->slot_4_Empty = false;
	this->slot_5_Empty = false;

	///Stats
	life = 200;
	//Time//
	this->moveTime.restart();

	//Position//	
	this->setPosition(TANK_START_POSITION);



	///Set turret position by them slot
	for (int indiceTurret = 0; indiceTurret < turretlist.size(); indiceTurret++)
	{
		switch (turretlist[indiceTurret]->getSlot())
		{
		case enums::TurretSlot::SLOT_1:
			turretlist[indiceTurret]->setPosition(this->getGlobalBounds().width / 2, this->getGlobalBounds().height / 2);
			break;
		case enums::TurretSlot::SLOT_2:
			turretlist[indiceTurret]->setPosition(0, 0);
			break;
		case enums::TurretSlot::SLOT_3:
			turretlist[indiceTurret]->setPosition(this->getGlobalBounds().width - turretlist[indiceTurret]->getGlobalBounds().width / 2, 0);
			break;
		case enums::TurretSlot::SLOT_4:
			turretlist[indiceTurret]->setPosition(0, this->getGlobalBounds().height);
			break;
		case enums::TurretSlot::SLOT_5:
			turretlist[indiceTurret]->setPosition(this->getGlobalBounds().width, this->getGlobalBounds().height);
			break;
		default:
			break;
		}
	}

	hud = new elementHud();
	rectLife.setSize(sf::Vector2f(hud->getGlobalBounds().width - 10, hud->getGlobalBounds().height - 7));
	rectLife.setFillColor(sf::Color::Green);
	rectLife.setOrigin(0, rectLife.getGlobalBounds().height);
	rectLife.setPosition(sf::Vector2f(hud->getPosition().x - hud->getGlobalBounds().width / 2 + 5, hud->getPosition().y));

	//debug view
	p_rectShape = new sf::RectangleShape(WINDOW_SIZE);
	p_rectShape->setOrigin(p_rectShape->getGlobalBounds().width / 2, p_rectShape->getGlobalBounds().height / 2);
	p_rectShape->setOutlineThickness(6);
	p_rectShape->setOutlineColor(sf::Color::Red);
	p_rectShape->setFillColor(sf::Color::Transparent);
	p_rectShape->setPosition(this->getPosition());

}

Tank::Tank(bool pSkinRed)
{
	//Rectangle/Sprite
	if (pSkinRed)
		texture.loadFromFile("resources/textures/TankRouge.png");
	else
		texture.loadFromFile("resources/textures/TankBleu.png");

	sprite.setTexture(texture);
	this->setOrigin(this->getGlobalBounds().width / 2, this->getGlobalBounds().height / 2);

	//Variables//
	///movement
	this->speed = 0;
	this->direction = { 0,0 };
	this->angleRotation = 0;

	///slot aviable for turret
	this->slot_1_Empty = false;
	this->slot_2_Empty = false;
	this->slot_3_Empty = false;
	this->slot_4_Empty = false;
	this->slot_5_Empty = false;

	///Stats
	life = TANK_MAXLIFE;
	shieldValue = TANK_MAXLIFE;
	//Time//
	this->moveTime.restart();

	//Position//	
	this->setPosition(TANK_START_POSITION);



	///Set turret position by them slot
	for (int indiceTurret = 0; indiceTurret < turretlist.size(); indiceTurret++)
	{
		switch (turretlist[indiceTurret]->getSlot())
		{
		case enums::TurretSlot::SLOT_1:
			turretlist[indiceTurret]->setPosition(this->getGlobalBounds().width / 2, this->getGlobalBounds().height / 2);
			break;
		case enums::TurretSlot::SLOT_2:
			turretlist[indiceTurret]->setPosition(0, 0);
			break;
		case enums::TurretSlot::SLOT_3:
			turretlist[indiceTurret]->setPosition(this->getGlobalBounds().width - turretlist[indiceTurret]->getGlobalBounds().width / 2, 0);
			break;
		case enums::TurretSlot::SLOT_4:
			turretlist[indiceTurret]->setPosition(0, this->getGlobalBounds().height);
			break;
		case enums::TurretSlot::SLOT_5:
			turretlist[indiceTurret]->setPosition(this->getGlobalBounds().width, this->getGlobalBounds().height);
			break;
		default:
			break;
		}
	}

	hud = new elementHud();
	rectLife.setSize(sf::Vector2f(hud->getGlobalBounds().width - 10, hud->getGlobalBounds().height - 7));
	rectLife.setFillColor(sf::Color::Green);
	rectLife.setOrigin(0, rectLife.getGlobalBounds().height);
	rectLife.setPosition(sf::Vector2f(hud->getPosition().x - hud->getGlobalBounds().width / 2 + 5, hud->getPosition().y));

	rectShield.setSize(sf::Vector2f(hud->getGlobalBounds().width - 10, hud->getGlobalBounds().height - 7));
	rectShield.setFillColor(sf::Color::Blue);
	rectShield.setOrigin(0, rectLife.getGlobalBounds().height);
	rectShield.setPosition(sf::Vector2f(hud->getPosition().x - hud->getGlobalBounds().width / 2 + 5, hud->getPosition().y));

	//debug view
	p_rectShape = new sf::RectangleShape(WINDOW_SIZE);
	p_rectShape->setOrigin(p_rectShape->getGlobalBounds().width / 2, p_rectShape->getGlobalBounds().height / 2);
	p_rectShape->setOutlineThickness(6);
	p_rectShape->setOutlineColor(sf::Color::Red);
	p_rectShape->setFillColor(sf::Color::Transparent);
	p_rectShape->setPosition(this->getPosition());

	std::cout << "size: " << rectLife.getSize().x << std::endl;
}


Tank::~Tank()
{
}

void Tank::update()
{
	if (testTime.getElapsedTime().asSeconds() > 0.1)
	{
		testTime.restart();
		applyDamageOnTank(1);
	}

	float sizeX = (float)481 / TANK_MAXLIFE;
	if (life > 0)
		rectLife.setSize(sf::Vector2f(sizeX * life, rectLife.getSize().y));
	else
	{
		rectLife.setSize(sf::Vector2f(0, rectLife.getSize().y));
	}

	float sizeShield = (float)481 / TANK_MAXLIFE;
	if (shieldValue > 0)
		rectShield.setSize(sf::Vector2f(shieldValue*sizeShield, rectShield.getSize().y));
	else
	{
		rectShield.setSize(sf::Vector2f(0, rectShield.getSize().y));
	}

	this->movement();
	this->moveTime.restart();

	for (int indiceTurret = 0; indiceTurret < turretlist.size(); indiceTurret++)
	{
		turretlist[indiceTurret]->setTankPos(this->getPosition());
	}

	///Guillaume 17-04-2019
	//debug view
	if (p_rectShape != NULL)
	{
		p_rectShape->setPosition(this->getPosition());
	}
}

void Tank::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	///Display tank
	target.draw(sprite, this->getTransform());

	///Display turret
	for (int indiceTurret = 0; indiceTurret < turretlist.size(); indiceTurret++)
	{
		target.draw(*turretlist[indiceTurret], this->getTransform());
	}
	//target.draw(rectLife);
	//target.draw(rectShield);
	//target.draw(*hud);
}

sf::FloatRect Tank::getGlobalBounds() const
{
	return this->getTransform().transformRect(sprite.getGlobalBounds());
}

void Tank::movement()
{
	//Rotation
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
	{
		this->angleRotation -= 1;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		this->angleRotation += 1;
	}
	this->setRotation(this->angleRotation);

	//Direction
	this->direction = GetDirectionFromAngleDegrees(this->angleRotation + 90);

	//Foward - Retreat
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
	{
		this->speed = -TANK_SPEED;
		///Move with time
		this->move(this->direction*this->speed*this->moveTime.getElapsedTime().asSeconds());
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		this->speed = TANK_SPEED;
		///Move with time
		this->move(this->direction*this->speed*this->moveTime.getElapsedTime().asSeconds());
	}
	else
	{
		this->speed = 0;
	}

	//Left - Right
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad4))
	{
		this->speed = TANK_SPEED;
		this->direction = -GetDirectionFromAngleDegrees(this->angleRotation);
		this->move(this->direction*this->speed*this->moveTime.getElapsedTime().asSeconds());
		this->direction = -GetDirectionFromAngleDegrees(this->angleRotation + 90);

	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad6))
	{
		this->speed = TANK_SPEED;
		this->direction = GetDirectionFromAngleDegrees(this->angleRotation);
		this->move(this->direction*this->speed*this->moveTime.getElapsedTime().asSeconds());
		this->direction = -GetDirectionFromAngleDegrees(this->angleRotation + 90);
	}
	else
	{
		this->speed = 0;
	}

	///std::cout << "direction: "<< direction.x <<" , "<< direction.y << std::endl;
	///std::cout << "speed: "<< speed<< std::endl;
	///std::cout << "------------------------------------------------"<< std::endl;
}

void Tank::initTurret(enums::TurretType pType, enums::TurretSlot pSlot)
{
	//Turret
	///Add turret on aviable slot
	///Set turret position by them slot
	std::cout << "[TANK]initTurret" << (int)pType << " ; " << (int)pSlot << std::endl;
	switch (pSlot)
	{
	case enums::TurretSlot::SLOT_1:
		if (!this->slot_1_Empty)
		{
			turretlist.push_back(new Turret(pType, pSlot));
			this->slot_1_Empty = true;
		}
		break;
	case enums::TurretSlot::SLOT_2:
		std::cout << "[TANK]PushBack 2" << (int)pType << " ; " << (int)pSlot << std::endl;
		if (!this->slot_2_Empty)
		{
			turretlist.push_back(new Turret(pType, pSlot));
			this->slot_2_Empty = true;
		}
		break;
	case enums::TurretSlot::SLOT_3:
		if (!this->slot_3_Empty)
		{
			turretlist.push_back(new Turret(pType, pSlot));
			this->slot_3_Empty = true;
		}
		break;
	case enums::TurretSlot::SLOT_4:
		if (!this->slot_4_Empty)
		{
			turretlist.push_back(new Turret(pType, pSlot));
			this->slot_4_Empty = true;
		}
		break;
	case enums::TurretSlot::SLOT_5:
		if (!this->slot_5_Empty)
		{
			turretlist.push_back(new Turret(pType, pSlot));
			this->slot_5_Empty = true;
		}
		break;
	default:
		break;
	}

	for (int indiceTurret = 0; indiceTurret < turretlist.size(); indiceTurret++)
	{
		switch (turretlist[indiceTurret]->getSlot())
		{
		case enums::TurretSlot::SLOT_1:
			turretlist[indiceTurret]->setPosition(this->getGlobalBounds().width / 2, this->getGlobalBounds().height / 2);
			break;
		case enums::TurretSlot::SLOT_2:
			turretlist[indiceTurret]->setPosition(35, 35);
			break;
		case enums::TurretSlot::SLOT_3:

			turretlist[indiceTurret]->setPosition(135, 35);
			break;
		case enums::TurretSlot::SLOT_4:
			turretlist[indiceTurret]->setPosition(35, 160);
			break;
		case enums::TurretSlot::SLOT_5:
			turretlist[indiceTurret]->setPosition(135, 160);
			break;
		default:
			break;
		}
	}
}

Turret* Tank::getTurret(enums::TurretSlot pSlot)
{
	for (int indiceTurret = 0; indiceTurret < turretlist.size(); indiceTurret++)
	{
		if (turretlist[indiceTurret]->getSlot() == pSlot)
		{
			return turretlist[indiceTurret];
		}
	}
	return 0;
}

std::vector<Turret*> Tank::getTurret()
{
	return turretlist;	
}


int Tank::getLife()
{
	return life;
}

void Tank::applyDamageOnTank(int pDamage)
{
	int tmpDamageToShield;
	int tmpDamageToLife;

	if (shieldValue > pDamage)
	{
		shieldValue -= pDamage;
		//std::cout << "shieldValue: " << shieldValue << std::endl;
		//std::cout << "life: " << life << std::endl;
	}
	else
	{
		tmpDamageToLife = shieldValue - pDamage;
		shieldValue = 0;
		life += tmpDamageToLife;
	}
}

