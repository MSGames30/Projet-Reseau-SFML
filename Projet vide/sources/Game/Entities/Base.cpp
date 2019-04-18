#include "Base.h"



Base::Base()
{
}

Base::Base(sf::Vector2f _pos, int _type)
{
	sprite = CreateSpriteFromPath("resources/textures/Base.png");
	
	origin = { sprite.getGlobalBounds().width, sprite.getGlobalBounds().height };
	this->setOrigin(origin);

	pos = _pos;
	this->setPosition(pos);

	posSpawn = pos;
	posSpawn.y -= 20;


	// Timer Spawn
	coolDownSpawn = 1;
}


Base::~Base()
{
}

void Base::update()
{
}

void Base::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	target.draw(sprite,this->getTransform());
}

sf::FloatRect Base::getGlobalBounds() const
{
	return this->getTransform().transformRect(sprite.getGlobalBounds());
}

bool Base::SpawnEnnemy()
{
	if (timerSpawn.getElapsedTime().asSeconds() > coolDownSpawn)
	{
		timerSpawn.restart();
		return true;
	}

	return false;
}