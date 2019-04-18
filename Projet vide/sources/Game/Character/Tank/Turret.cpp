#include "Turret.h"
#include <iostream>
#include "../../../Managers/GameManager.h"
#include "../../Hud/elementHud.h"
Turret::Turret()
{


}

Turret::Turret(enums::TurretType pType, enums::TurretSlot pSlot)
{
	slot = pSlot;
	type = pType;

	switch (type)
	{
	case enums::TurretType::INCENDIARY:
		texture.loadFromFile("resources/textures/turretIncendiary.png");
		sprite.setTexture(texture);
		sprite.setOrigin(this->getGlobalBounds().width / 2, 40);
		damage = 1;
		break;
	case enums::TurretType::SUBMACHINE:
		texture.loadFromFile("resources/textures/submachine.png");
		sprite.setTexture(texture);
		sprite.setOrigin(this->getGlobalBounds().width / 2, 60);
		damage = 5;
		break;
	case enums::TurretType::MAIN_CANON_SIMPLE:
		texture.loadFromFile("resources/textures/canonSimple.png");
		sprite.setTexture(texture);
		sprite.setOrigin(this->getGlobalBounds().width / 2, 110);
		damage = 15;
		break;
	case enums::TurretType::MAIN_CANON_TRIPLE:
		texture.loadFromFile("resources/textures/canonTriple.png");
		sprite.setTexture(texture);
		sprite.setOrigin(this->getGlobalBounds().width / 2, 40);
		damage = 5;
		break;
	case enums::TurretType::NONE:
		break;
	default:
		break;
	}

	switch (slot)
	{
	case enums::TurretSlot::SLOT_1:
		break;
	case enums::TurretSlot::SLOT_2:
		break;
	case enums::TurretSlot::SLOT_3:
		break;
	case enums::TurretSlot::SLOT_4:
		this->setRotation(180);
		break;
	case enums::TurretSlot::SLOT_5:
		this->setRotation(180);
		break;
	default:
		break;
	}


	//Variables//
	///Keyboard pressed
	pressed_Space = false;

	///Rotation
	angle = 0;

	hud = new elementHud(slot, type, "yanis");
	score = 150;
	std::cout << "i'm new turret" << std::endl;
}

Turret::~Turret()
{
}

void Turret::update()
{

	if (this->type != enums::TurretType::NONE)
	{
		shoot();
		deleteBullet();
		movement();
		for (int indiceBullet = 0; indiceBullet < bulletList.size(); indiceBullet++)
		{
			bulletList[indiceBullet]->update();
		}
	}
}

void Turret::update(enums::TurretSlot pPlayerSlot)
{
	//std::cout << "update turret" << std::endl;
	if (this->type != enums::TurretType::NONE)
	{
		if (slot == pPlayerSlot)
		{
			shoot();
			deleteBullet();
			movement();
			for (int indiceBullet = 0; indiceBullet < bulletList.size(); indiceBullet++)
			{
				bulletList[indiceBullet]->update();
			}
		}
	}

	if (hud != nullptr)
	{
		hud->setStringScore(std::to_string(150));
	}
}

void Turret::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	for (int indiceBullet = 0; indiceBullet < bulletList.size(); indiceBullet++)
	{
		target.draw(*bulletList[indiceBullet], this->getTransform());
	}

	states.transform *= this->getTransform();
	target.draw(sprite, states.transform);

	renderState.transform = states.transform;

	//target.draw(*hud);
	//std::cout << "draw X: " << this->getPosition().x << " , " << this->getPosition().y << std::endl;
}

sf::FloatRect Turret::getGlobalBounds() const
{
	return this->getTransform().transformRect(sprite.getGlobalBounds());
}

void Turret::shoot()
{
	sf::Vector2f tmpDirection;
	switch (type)
	{
	case enums::TurretType::INCENDIARY:
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && !pressed_Space)
		{
			pressed_Space = true;
		}
		else if (!sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && pressed_Space)
		{
			pressed_Space = false;
			if (cooldownShoot.getElapsedTime().asSeconds() > 3)
			{
				cooldownShoot.restart();
				tmpDirection = GetDirectionFromAngleDegrees(sprite.getRotation() - 90);
				bulletList.push_back(new Bullet(type, slot, tmpDirection, renderState));
			}
		}
		break;
	case enums::TurretType::SUBMACHINE:
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
		{
			if (cooldownShoot.getElapsedTime().asSeconds() > 0.3)
			{
				cooldownShoot.restart();
				tmpDirection = GetDirectionFromAngleDegrees(sprite.getRotation() - 90);

				bulletList.push_back(new Bullet(type, slot, tmpDirection, renderState));
			}
		}
		break;
	case enums::TurretType::MAIN_CANON_SIMPLE:
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && !pressed_Space)
		{
			pressed_Space = true;
		}
		else if (!sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && pressed_Space)
		{
			pressed_Space = false;
			if (cooldownShoot.getElapsedTime().asSeconds() > 1)
			{
				cooldownShoot.restart();
				tmpDirection = GetDirectionFromAngleDegrees(sprite.getRotation() - 90);

				bulletList.push_back(new Bullet(type, slot, tmpDirection, renderState));
			}
		}
		break;
	case enums::TurretType::MAIN_CANON_TRIPLE:
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && !pressed_Space)
		{
			pressed_Space = true;
		}
		else if (!sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && pressed_Space)
		{
			pressed_Space = false;
			if (cooldownShoot.getElapsedTime().asSeconds() > 2)
			{
				cooldownShoot.restart();
				tmpDirection = GetDirectionFromAngleDegrees(sprite.getRotation() - 90);
				bulletList.push_back(new Bullet(type, slot, tmpDirection, renderState));
				tmpDirection.x = tmpDirection.x - 1;
				bulletList.push_back(new Bullet(type, slot, tmpDirection, renderState));
				tmpDirection.x = tmpDirection.x + 2;
				bulletList.push_back(new Bullet(type, slot, tmpDirection, renderState));
			}
		}
		break;
	case enums::TurretType::NONE:

		break;
	default:
		break;
	}
}

void Turret::movement()
{

	if (this->slot != enums::TurretSlot::SLOT_1)
	{
		//std::cout << tmpMouseAngle << std::endl;
	}

	switch (slot)
	{
	case enums::TurretSlot::SLOT_1:
		break;
	case enums::TurretSlot::SLOT_2:

		if (angle <= 0 && angle >= -90)
		{
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad7))
				angle -= 1;
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad9))
				angle += 1;
		}
		if (angle < -90)
			angle = -90;
		else if (angle > 0)
			angle = 0;

		break;
	case enums::TurretSlot::SLOT_3:
		if (angle <= 90 && angle >= 0)
		{
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad7))
				angle -= 1;
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad9))
				angle += 1;

			if (angle < 0)
				angle = 0;
			else if (angle > 90)
				angle = 90;

		}
		break;
	case enums::TurretSlot::SLOT_4:
		if (angle <= 90 && angle >= 0)
		{
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad7))
				angle -= 1;
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad9))
				angle += 1;
		}

		if (angle < 0)
			angle = 0;
		else if (angle > 90)
			angle = 90;

		break;
	case enums::TurretSlot::SLOT_5:
		if (angle <= 0 && angle >= -90)
		{
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad7))
				angle -= 1;
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad9))
				angle += 1;
		}

		if (angle < -90)
			angle = -90;
		else if (angle > 0)
			angle = 0;
		break;
	default:
		break;
	}
	sprite.setRotation(angle);
}

void Turret::deleteBullet()
{
	for (int indiceBullet = 0; indiceBullet < bulletList.size(); indiceBullet++)
	{
		if (bulletList[indiceBullet]->getState() == enums::BulletState::TO_DELETE)
		{
			delete bulletList[indiceBullet];
			bulletList.erase(bulletList.begin() + indiceBullet);
			break;
		}
	}
}

enums::TurretType Turret::getType()
{
	return type;
}

enums::TurretSlot Turret::getSlot()
{
	return slot;
}

void Turret::setScore(int pScore)
{
	score = pScore;
}

int Turret::getScore()
{
	return score;
}

void Turret::setTankPos(sf::Vector2f pPos)
{
	 tankPos = pPos;
}

std::vector<Bullet*> Turret::getBulletList()
{
	return bulletList;
}

float Turret::getDamage()
{
	return damage;
}
