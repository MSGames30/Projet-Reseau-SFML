#pragma once
#include "../Character/Ennemy.h"

class Soldat : public Ennemy
{
public:
	Soldat();
	Soldat(enums::ennemies_Type ptype, sf::Vector2f _pos);
	~Soldat();

	void update(sf::Vector2f _pos);
	void update();
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	sf::FloatRect getGlobalBounds() const;

	void Move();
private:

};