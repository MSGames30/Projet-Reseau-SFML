#pragma once
#include "../Entities/DrawableObject.h"
#include "../../Tools/Enums.h"
#include "../../Tools/Defines.h"
class Bullet :
	public DrawableObject
{
public:
	Bullet();
	Bullet(enums::TurretType pType, enums::TurretSlot pSlot, sf::Vector2f pDirection, sf::RenderStates prenderState);
	~Bullet();

	virtual void update();
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	virtual sf::FloatRect getGlobalBounds() const;

	void movement();
	void action();
	enums::BulletState getState();
	void setState(enums::BulletState pstate);
	float getDamage();
private:
	sf::CircleShape circle;
	enums::TurretType type;
	enums::TurretSlot slot;
	sf::Clock moveTime;
	sf::Vector2f direction;
	enums::BulletState state;

	mutable sf::RenderStates renderState;
	float damage;
};

