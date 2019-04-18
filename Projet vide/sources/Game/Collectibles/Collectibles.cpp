#include "Collectibles.h"



Collectibles::Collectibles()
{
	if (rand() % 2 - 1 == 0)
	{
		texture.loadFromFile("resources/textures/Shield");
		type = enums::Collectibles::SHIELD;
	}
	else
	{
		texture.loadFromFile("resources/textures/Life");
		type = enums::Collectibles::LIFE;
	}
	sprite.setTexture(texture);
}

Collectibles::Collectibles(sf::Vector2f pPos)
{
	if (rand() % 2 - 1 == 0)
	{
		texture.loadFromFile("resources/textures/Shield");
		type = enums::Collectibles::SHIELD;
	}
	else
	{
		texture.loadFromFile("resources/textures/Life");
		type = enums::Collectibles::LIFE;
	}
	sprite.setTexture(texture);
	this->setPosition(pPos);
}

Collectibles::~Collectibles()
{
}

void Collectibles::update()
{
	
}

void Collectibles::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	target.draw(sprite, this->getTransform());
}

sf::FloatRect Collectibles::getGlobalBounds() const
{
	return this->getTransform().transformRect(sprite.getGlobalBounds());
}
