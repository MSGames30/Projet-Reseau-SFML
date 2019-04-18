#pragma once
#include "../../Entities/DrawableObject.h"
#include "../../../Tools/Enums.h"
#include "../../../Tools/UtilsCpp.h"
#include "../../Bullet/Bullet.h"
#include "../../Hud/HUD.h"
#include <string>
class Turret :
	public DrawableObject
{
public:
	Turret();
	Turret(enums::TurretType pType, enums::TurretSlot pSlot);
	~Turret();

	virtual void update();
	virtual void update(enums::TurretSlot pPlayerSlot);
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	virtual sf::FloatRect getGlobalBounds() const;

	void shoot();
	void movement();
	void deleteBullet();

	//Accessor / Mutator
	enums::TurretType getType();
	enums::TurretSlot getSlot();
	void setScore(int pScore);
	int getScore();
	void setTankPos(sf::Vector2f pPos);
	std::vector<Bullet*> getBulletList();
	float getDamage();

	HUD* getHUD() { return hud; };
private:
	sf::Texture texture;
	sf::Sprite sprite;
	enums::TurretType type;
	enums::TurretSlot slot;

	HUD* hud;

	float angle;

	bool pressed_Space;

	std::vector<Bullet*> bulletList;
	sf::Clock cooldownShoot;
	mutable sf::RenderStates renderState;

	int score;
	sf::Vector2f tankPos;
	float damage;
};

