#include "SoldatLourd.h"

SoldatLourd::SoldatLourd()
{
}

SoldatLourd::SoldatLourd(enums::ennemies_Type pType, sf::Vector2f _pos)
{
	type = pType;

	spriteSurprise = CreateSpriteFromPath("resources/textures/alert.png");
	spriteSurprise.setOrigin(spriteSurprise.getGlobalBounds().width/2, spriteSurprise.getGlobalBounds().height/2);

	sprite = CreateSpriteFromPath("resources/textures/SoldatLourd.jpg");

	origin = { sprite.getGlobalBounds().width/2, sprite.getGlobalBounds().height/2 };
	this->setOrigin(origin);

	pos = _pos;
	this->setPosition(pos);
	spriteSurprise.setPosition(pos);

	state_ennemy = enums::STATE_ENNEMY::WALK;

	speed = 30;

	sf::Color colorCercle;

	radiusRUN = 700;
	cercleRUN = new sf::CircleShape();
	cercleRUN->setRadius(radiusRUN);
	cercleRUN->setPosition(pos);
	cercleRUN->setOrigin(radiusRUN, radiusRUN);
	colorCercle = sf::Color::Blue;
	colorCercle.a = 100;
	cercleRUN->setFillColor(colorCercle);

	radiusATTAQUE = 120;
	cercleATTAQUE  = new sf::CircleShape();
	cercleATTAQUE->setRadius(radiusATTAQUE);
	cercleATTAQUE->setPosition(pos);
	cercleATTAQUE->setOrigin(radiusATTAQUE, radiusATTAQUE);
	colorCercle = sf::Color::Red;
	colorCercle.a = 100;
	cercleATTAQUE->setFillColor(colorCercle);

	coolDownSuprise = 0.80;
	coolDownShoot = 2;
	coolDownGrenade = 5;
}

SoldatLourd::~SoldatLourd()
{
}

void SoldatLourd::update()
{
}

void SoldatLourd::update(sf::Vector2f _pos)
{
	posFollow = _pos;
	life = 40;
	Ennemy::updateStateEnnemy(type);
	Ennemy::Move();

	if (state_ennemy == enums::STATE_ENNEMY::RUN || state_ennemy == enums::STATE_ENNEMY::ATTAQUE)
	{
		if (timerShoot.getElapsedTime().asSeconds() > coolDownShoot)
		{
			listBulletEnnemy.push_back(new BulletEnnemy(this->getPosition(), direction, "Lourd"));

			timerShoot.restart();
		}


		if (timerShoot_Grenade.getElapsedTime().asSeconds() > coolDownGrenade)
		{
			listBulletEnnemy.push_back(new BulletEnnemy(this->getPosition(), direction, "Grenade"));

			timerShoot_Grenade.restart();
		}
	}

	for (int i = 0; i < listBulletEnnemy.size(); i++)
	{
		listBulletEnnemy[i]->update();

		if (listBulletEnnemy[i]->getPosition().x < 0 || listBulletEnnemy[i]->getPosition().x > 1920 || listBulletEnnemy[i]->getPosition().y < 0 || listBulletEnnemy[i]->getPosition().y > 1080)
		{
			if (listBulletEnnemy[i]->getName() == "Grenade")
			{
				if (listBulletEnnemy[i]->timerDmgZone.getElapsedTime().asSeconds() < listBulletEnnemy[i]->cooldDownZone)
				{
					if (listBulletEnnemy[i]->CollidZoneGrenade(this->getPosition()))
					{
						std::cout << "Player dans l'explosion !" << std::endl;
					}
				}
				else
				{
					listBulletEnnemy.erase(listBulletEnnemy.begin() + i);
				}
			}
			else
			{
				listBulletEnnemy.erase(listBulletEnnemy.begin() + i);
			}
		}

		// Si Collision avec le tank
		/*if (listBulletEnnemy[i]->getName() == "Grenade")
		{
			if (listBulletEnnemy[i]->timerDmgZone.getElapsedTime().asSeconds() < listBulletEnnemy[i]->cooldDownZone)
			{
				if (listBulletEnnemy[i]->CollidZoneGrenade(this->getPosition()))
				{

				}
			}
			else
			{
				listBulletEnnemy.erase(listBulletEnnemy.begin() + i);
			}
		}
		else
		{
		}*/
	}
}

void SoldatLourd::Move()
{
	angle = RadToDeg(GetAngleRadiansBetweenPoints(pos, posFollow));
	this->setRotation(angle);

	direction = GetDirectionFromAngleDegrees(angle);

	float tps = timerGeneral.getElapsedTime().asSeconds();

	pos.x += direction.x * tps * speed;
	pos.y += direction.y * tps * speed;
	this->setPosition(pos);

	spriteSurprise.setPosition(pos);
	cercleRUN->setPosition(pos);
	cercleATTAQUE->setPosition(pos);

	timerGeneral.restart();
}

void SoldatLourd::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	//target.draw(*cercleRUN);
	//target.draw(*cercleATTAQUE);
	target.draw(sprite, this->getTransform());

	if (state_ennemy == enums::STATE_ENNEMY::SURPRISE)
	{
		target.draw(spriteSurprise);
	}

	for (int i = 0; i < listBulletEnnemy.size(); i++)
	{
		target.draw(*listBulletEnnemy[i]);
	}
}

sf::FloatRect SoldatLourd::getGlobalBounds() const
{
	return this->getTransform().transformRect(sprite.getGlobalBounds());
}
