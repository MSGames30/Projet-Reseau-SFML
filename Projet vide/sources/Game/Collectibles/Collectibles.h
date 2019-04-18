#pragma once
#include "../Entities/DrawableObject.h"
#include "../../Tools/Enums.h"
class Collectibles :
	public DrawableObject
{
public:
	Collectibles();
	Collectibles(sf::Vector2f pPos);
	~Collectibles();

	void update();
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	sf::FloatRect getGlobalBounds() const;

private:

	sf::Texture texture;
	sf::Sprite sprite;

	enums::Collectibles type;
};

