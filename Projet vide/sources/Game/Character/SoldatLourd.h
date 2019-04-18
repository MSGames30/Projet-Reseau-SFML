#pragma once
#include "../Character/Ennemy.h"


class SoldatLourd : public Ennemy
{
public:
	SoldatLourd();
	SoldatLourd(enums::ennemies_Type pType, sf::Vector2f _pos);
	~SoldatLourd();

	void update();
	void update(sf::Vector2f _pos);
	void Move();
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	sf::FloatRect getGlobalBounds() const;

private:

	sf::Clock timerShoot_Grenade;
	float coolDownGrenade;

};