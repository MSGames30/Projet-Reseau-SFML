#pragma once
#include "..\Entities\DrawableObject.h"
#include "..\..\Tools\UtilsCpp.h"

enum TYPE_BULLET
{
	NORMAL = 0,
	LOURD,
	GRENADE,
	SNIPER
};

class BulletEnnemy :
	public DrawableObject
{
public:
	BulletEnnemy();
	BulletEnnemy(sf::Vector2f _pos, sf::Vector2f _direction, std::string _name);
	~BulletEnnemy();
	virtual void update();
	void Move();
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	virtual sf::FloatRect getGlobalBounds() const;
	std::string getName();
	bool CollidZoneGrenade(sf::Vector2f _pos);

	bool isExplode;
	sf::Clock timerDmgZone;
	float cooldDownZone;
protected :
	sf::Sprite sprite;
	sf::Vector2f pos;
	sf::Vector2f origin;
	sf::Vector2f direction;
	float speed;

	sf::Clock timerGeneral;

	TYPE_BULLET type_bullet;
	std::string name;

	float raduisZone;
};

