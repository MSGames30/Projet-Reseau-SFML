#pragma once
#include "..\Character\Ennemy.h"
class Kamikaz : public Ennemy
{
public:
	Kamikaz();
	Kamikaz(enums::ennemies_Type ptype, sf::Vector2f _pos);
	~Kamikaz();

	void update();
	void update(sf::Vector2f _pos);
	void Move();
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	sf::FloatRect getGlobalBounds() const;
private:

	float radiusBoom;
	sf::CircleShape* cercleBoom;
};

