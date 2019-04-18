#pragma once
#include "../Character/Ennemy.h"
#include "../Entities/BulletEnnemy.h"

class Sniper : public Ennemy
{
public:
	Sniper();
	Sniper(enums::ennemies_Type pType, sf::Vector2f _pos);
	~Sniper();

	void update();
	void update(sf::Vector2f _pos);
	void Move();
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	sf::FloatRect getGlobalBounds() const;

private:
	float angle_flee;
	bool isFlee;

};

