#pragma once
#include "../../Entities/DrawableObject.h"
#include "../../../Tools/Enums.h"
#include "../../../Tools/Defines.h"
#include "../../../Tools/UtilsCpp.h"
#include "Turret.h"

class Tank :
	public DrawableObject
{
public:
	Tank();
	Tank(bool pSkinRed);
	~Tank();

	virtual void update();
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	virtual sf::FloatRect getGlobalBounds() const;

	//Movement Function
	void movement();

	int getLife();
	void applyDamageOnTank(int pDamage);
	void initTurret(enums::TurretType pType, enums::TurretSlot pSlot);
	Turret* getTurret(enums::TurretSlot pSlot);
	std::vector<Turret*> getTurret();

	///Guillaume 17-04-2019
	HUD* getHUD() { return hud; }
	sf::RectangleShape getRectLife() { return rectLife; }
	sf::RectangleShape getRectShield() { return rectShield; }

	std::vector<Turret*> getTurretList() { return turretlist; }

	///Guillaume 17-04-2019 
	//debug view
	sf::RectangleShape* p_rectShape;
private:
	sf::Texture texture;
	sf::Sprite sprite;
	enums::TurretType turretType;
	//movements variables

	sf::Vector2f direction;

	HUD *hud;
	sf::RectangleShape rectLife;
	sf::RectangleShape rectShield;
	float speed;
	float angleRotation;

	sf::Clock moveTime;
	sf::Clock testTime;

	//SlotForTurret
	bool slot_1_Empty;
	bool slot_2_Empty;
	bool slot_3_Empty;
	bool slot_4_Empty;
	bool slot_5_Empty;
	//ObjectPointer
	std::vector<Turret*> turretlist;
	float life;
	float shieldValue;
	bool isSkin_One;
	
};

