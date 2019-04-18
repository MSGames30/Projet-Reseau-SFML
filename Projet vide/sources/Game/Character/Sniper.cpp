#include "Sniper.h"

Sniper::Sniper()
{
}

Sniper::Sniper(enums::ennemies_Type pType, sf::Vector2f _pos)
{
	type = pType;
	life = 15;
	spriteSurprise = CreateSpriteFromPath("resources/textures/alert.png");
	spriteSurprise.setOrigin(spriteSurprise.getGlobalBounds().width / 2, spriteSurprise.getGlobalBounds().height / 2);

	sprite = CreateSpriteFromPath("resources/textures/Sniper.jpg");

	origin = { sprite.getGlobalBounds().width / 2, sprite.getGlobalBounds().height / 2 };
	this->setOrigin(origin);

	pos = _pos;
	this->setPosition(pos);
	spriteSurprise.setPosition(pos);

	state_ennemy = enums::STATE_ENNEMY::WALK;

	speed = 55;

	sf::Color colorCercle;

	radiusRUN = 700;
	cercleRUN = new sf::CircleShape();
	cercleRUN->setRadius(radiusRUN);
	cercleRUN->setPosition(pos);
	cercleRUN->setOrigin(radiusRUN, radiusRUN);
	colorCercle = sf::Color::Blue;
	colorCercle.a = 100;
	cercleRUN->setFillColor(colorCercle);

	radiusATTAQUE = 625;
	cercleATTAQUE = new sf::CircleShape();
	cercleATTAQUE->setRadius(radiusATTAQUE);
	cercleATTAQUE->setPosition(pos);
	cercleATTAQUE->setOrigin(radiusATTAQUE, radiusATTAQUE);
	colorCercle = sf::Color::Red;
	colorCercle.a = 100;
	cercleATTAQUE->setFillColor(colorCercle);

	coolDownSuprise = 0.80;
	coolDownShoot = 4;

	isFlee = false;
}


Sniper::~Sniper()
{
}

void Sniper::update()
{
}

void Sniper::update(sf::Vector2f _pos)
{
	posFollow = _pos;

	Ennemy::updateStateEnnemy(type);
	Move();

	if (state_ennemy == enums::STATE_ENNEMY::RUN)
	{
		if (timerShoot.getElapsedTime().asSeconds() > coolDownShoot)
		{
			listBulletEnnemy.push_back(new BulletEnnemy(this->getPosition(), GetDirectionFromAngleDegrees(angle), "Sniper"));

			timerShoot.restart();
		}
	}

	for (int i = 0; i < listBulletEnnemy.size(); i++)
	{
		listBulletEnnemy[i]->update();

		if (listBulletEnnemy[i]->getPosition().x < 0 || listBulletEnnemy[i]->getPosition().x > 1920 || listBulletEnnemy[i]->getPosition().y < 0 || listBulletEnnemy[i]->getPosition().y > 1080)
		{
			listBulletEnnemy.erase(listBulletEnnemy.begin() + i);
		}
	}
}

void Sniper::Move()
{
	if (state_ennemy == enums::STATE_ENNEMY::ATTAQUE)
	{
		angle = RadToDeg(GetAngleRadiansBetweenPoints(pos, posFollow));
		angle_flee = RadToDeg(GetAngleRadiansBetweenPoints(posFollow, pos));
		direction = GetDirectionFromAngleDegrees(angle_flee);
	}
	else
	{
		angle = RadToDeg(GetAngleRadiansBetweenPoints(pos, posFollow));
		direction = GetDirectionFromAngleDegrees(angle);
	}
	this->setRotation(angle);



	float tps = timerGeneral.getElapsedTime().asSeconds();

	pos.x += direction.x * tps * speed;
	pos.y += direction.y * tps * speed;
	this->setPosition(pos);

	spriteSurprise.setPosition(pos);
	cercleRUN->setPosition(pos);
	cercleATTAQUE->setPosition(pos);

	timerGeneral.restart();
}

void Sniper::draw(sf::RenderTarget & target, sf::RenderStates states) const
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

sf::FloatRect Sniper::getGlobalBounds() const
{
	return this->getTransform().transformRect(sprite.getGlobalBounds());
}