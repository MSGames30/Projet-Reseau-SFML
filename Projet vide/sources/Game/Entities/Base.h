#pragma once
#include "..\Entities\DrawableObject.h"
#include "../../Tools/UtilsCpp.h"


class Base : public DrawableObject
{
public:
	Base();
	Base(sf::Vector2f _pos, int _type);
	~Base();

	void update();
	void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	sf::FloatRect getGlobalBounds() const;

	bool SpawnEnnemy();

	sf::Vector2f posSpawn;
private:
	sf::Sprite sprite;
	sf::Vector2f pos;
	sf::Vector2f origin;

	// Timer Spawn
	sf::Clock timerSpawn;
	float coolDownSpawn;
};

