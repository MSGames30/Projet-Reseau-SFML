#include "Bullet.h"
#include <iostream>


Bullet::Bullet()
{

}

Bullet::Bullet(enums::TurretType pType, enums::TurretSlot pSlot, sf::Vector2f pDirection, sf::RenderStates prenderState)
{
	this->slot = pSlot;
	this->type = pType;
	this->direction = pDirection;
	this->moveTime.restart();
	this->state = enums::BulletState::MOVING;

	switch (type)
	{
	case enums::TurretType::INCENDIARY:
		circle.setRadius(15);
		circle.setFillColor(sf::Color::Red);
		damage = 1;
		break;
	case enums::TurretType::SUBMACHINE:
		circle.setRadius(10);
		circle.setFillColor(sf::Color::Yellow);
		damage = 5;
		break;
	case enums::TurretType::MAIN_CANON_SIMPLE:
		circle.setRadius(30);
		circle.setFillColor(sf::Color::Blue);
		damage = 15;
		break;
	case enums::TurretType::MAIN_CANON_TRIPLE:
		circle.setRadius(20);
		circle.setFillColor(sf::Color::Cyan);
		damage = 5;
		break;
	case enums::TurretType::NONE:
		break;
	default:
		break;
	}
	circle.setOrigin(this->getGlobalBounds().width / 2, this->getGlobalBounds().height / 2);
	//setPosition(pStartPos);
	renderState = prenderState;

	std::cout << "new bullet " << this->getPosition().x << " , " << this->getPosition().y << std::endl;
}

Bullet::~Bullet()
{

}

void Bullet::update()
{
	this->movement();
	this->action();
	//std::cout << "time " << moveTime.getElapsedTime().asSeconds() << std::endl;
	this->moveTime.restart();
}

void Bullet::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	renderState.transform *= this->getTransform();
	target.draw(circle, renderState);
}

sf::FloatRect Bullet::getGlobalBounds() const
{
	return this->getTransform().transformRect(circle.getGlobalBounds());
}

void Bullet::movement()
{
	if (this->state != enums::BulletState::ON_COLLIDER && this->state != enums::BulletState::TO_DELETE)
		move(this->direction.x*this->moveTime.getElapsedTime().asSeconds()*BULLET_SPEED, this->direction.y*this->moveTime.getElapsedTime().asSeconds()*BULLET_SPEED);
}

void Bullet::action()
{

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::G))
	{
		this->state = enums::BulletState::ON_COLLIDER;
	}

	switch (type)
	{
	case enums::TurretType::INCENDIARY:
		if (this->state == enums::BulletState::ON_COLLIDER)
		{
			this->circle.setRadius(circle.getRadius() + 5);
			circle.setOrigin(this->getGlobalBounds().width / 2, this->getGlobalBounds().height / 2);
		}

		if (this->circle.getRadius() >= BULLET_INCENDIARY_MAXSIZE)
			this->state = enums::BulletState::TO_DELETE;

		
		break;
	case enums::TurretType::SUBMACHINE:
		if (this->state == enums::BulletState::ON_COLLIDER)
			this->state = enums::BulletState::TO_DELETE;
		break;
	case enums::TurretType::MAIN_CANON_SIMPLE:
		if (this->state == enums::BulletState::ON_COLLIDER)
			this->state = enums::BulletState::TO_DELETE;

		break;
	case enums::TurretType::MAIN_CANON_TRIPLE:
		if (this->state == enums::BulletState::ON_COLLIDER)
			this->state = enums::BulletState::TO_DELETE;

		break;
	case enums::TurretType::NONE:
		break;
	default:
		break;
	}
}

enums::BulletState Bullet::getState()
{
	return state;
}

void Bullet::setState(enums::BulletState pstate)
{
	state = pstate;
}

float Bullet::getDamage()
{
	return damage;
}
