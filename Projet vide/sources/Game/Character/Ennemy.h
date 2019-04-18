#pragma once
#include "../Entities/DrawableObject.h"
#include "../Entities/BulletEnnemy.h"
#include "../../Tools/UtilsCpp.h"
#include "../../Tools/Enums.h"


class Ennemy :
	public DrawableObject
{
public:
	Ennemy();
	~Ennemy();

	virtual void update()=0;
	virtual void update(sf::Vector2f _pos)=0;
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	void Move();
	virtual sf::FloatRect getGlobalBounds() const=0;
	enums::ennemies_Type getType();
	void updateStateEnnemy(enums::ennemies_Type  _typeEnnemy);
	enums::STATE_ENNEMY getState_ennemy();

	void setState(enums::STATE_ENNEMY pState);
	void applyDamage(float Damage);
protected:

	sf::Sprite spriteSurprise;
	sf::Sprite sprite;
	sf::Vector2f pos;
	sf::Vector2f origin;
	sf::Vector2f direction;
	float angle;
	float speed;
	float life;

	sf::Vector2f posFollow;

	sf::Clock timerGeneral;

	enums::STATE_ENNEMY state_ennemy;
	enums::ennemies_Type type;
	float radiusRUN;
	float radiusATTAQUE;
	sf::CircleShape* cercleRUN;
	sf::CircleShape* cercleATTAQUE;

	// Timer Etat Surprise
	sf::Clock timerSurprise;
	float coolDownSuprise;

	// Timer Shoot
	sf::Clock timerShoot;
	float coolDownShoot;

	std::vector<BulletEnnemy*> listBulletEnnemy;
};

