#include "BulletEnnemy.h"


BulletEnnemy::BulletEnnemy()
{

}

BulletEnnemy::BulletEnnemy(sf::Vector2f _pos, sf::Vector2f _direction, std::string _name)
{
	name = _name;

	sprite = CreateSpriteFromPath("resources/textures/BalleEnnmy_" + name + ".png");

	if (name == "Normal")
	{
		type_bullet = NORMAL;
		speed = 500;
		raduisZone = 0;
		cooldDownZone = 0;
	}
	else if (name == "Lourd")
	{
		type_bullet = LOURD;
		speed = 500;
		raduisZone = 0;
		cooldDownZone = 0;
	}
	else if (name == "Grenade")
	{
		type_bullet = GRENADE;
		speed = 250;
		raduisZone = 30;
		cooldDownZone = 1;
	}
	else if (name == "Sniper")
	{
		type_bullet = SNIPER;
		speed = 600;
		raduisZone = 0;
		cooldDownZone = 0;
	}
	
	
	origin = { sprite.getGlobalBounds().width / 2, sprite.getGlobalBounds().height / 2 };
	this->setOrigin(origin);

	pos = _pos;
	this->setPosition(pos);

	direction = _direction;

	isExplode = false;
}

BulletEnnemy::~BulletEnnemy()
{
}

void BulletEnnemy::update()
{
	Move();
}

void BulletEnnemy::Move()
{
	float tps = timerGeneral.getElapsedTime().asSeconds();

	pos.x += direction.x * tps * speed;
	pos.y += direction.y * tps * speed;
	this->setPosition(pos);

	timerGeneral.restart();
}

void BulletEnnemy::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	target.draw(sprite, this->getTransform());
}

sf::FloatRect BulletEnnemy::getGlobalBounds() const
{
	return this->getTransform().transformRect(sprite.getGlobalBounds());
}

std::string BulletEnnemy::getName()
{
	return name;
}

bool BulletEnnemy::CollidZoneGrenade(sf::Vector2f _pos)
{
	if (Magnitude({ _pos - this->getPosition() }) < raduisZone)
	{
		return true;
	}

	return false;
}