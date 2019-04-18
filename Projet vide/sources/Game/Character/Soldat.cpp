#include "Soldat.h"

Soldat::Soldat()
{
}

Soldat::Soldat(enums::ennemies_Type ptype, sf::Vector2f _pos)
{
	type = ptype;
	life = 20;
	spriteSurprise = CreateSpriteFromPath("resources/textures/alert.png");
	spriteSurprise.setOrigin(spriteSurprise.getGlobalBounds().width/2, spriteSurprise.getGlobalBounds().height/2);

	sprite = CreateSpriteFromPath("resources/textures/Soldat.jpg");

	origin = { sprite.getGlobalBounds().width/2, sprite.getGlobalBounds().height/2 };
	this->setOrigin(origin);

	pos = _pos;
	this->setPosition(pos);
	spriteSurprise.setPosition(pos);

	state_ennemy = enums::STATE_ENNEMY::WALK;

	speed = 70;

	sf::Color colorCercle;

	radiusRUN = 800;
	cercleRUN = new sf::CircleShape();
	cercleRUN->setRadius(radiusRUN);
	cercleRUN->setPosition(pos);
	cercleRUN->setOrigin(radiusRUN, radiusRUN);
	colorCercle = sf::Color::Blue;
	colorCercle.a = 100;
	cercleRUN->setFillColor(colorCercle);

	radiusATTAQUE = 100;
	cercleATTAQUE  = new sf::CircleShape();
	cercleATTAQUE->setRadius(radiusATTAQUE);
	cercleATTAQUE->setPosition(pos);
	cercleATTAQUE->setOrigin(radiusATTAQUE, radiusATTAQUE);
	colorCercle = sf::Color::Red;
	colorCercle.a = 100;
	cercleATTAQUE->setFillColor(colorCercle);

	coolDownSuprise = 0.80;
	coolDownShoot = 1.5;
}

Soldat::~Soldat()
{
}

void Soldat::update()
{
}

void Soldat::update(sf::Vector2f _pos)
{
	posFollow = _pos;

	Ennemy::updateStateEnnemy(type);
	Ennemy::Move();

	if (state_ennemy == enums::STATE_ENNEMY::RUN || state_ennemy == enums::STATE_ENNEMY::ATTAQUE)
	{
		if (timerShoot.getElapsedTime().asSeconds() > coolDownShoot)
		{
			listBulletEnnemy.push_back(new BulletEnnemy(this->getPosition(), direction, "Normal"));

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

void Soldat::Move()
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

void Soldat::draw(sf::RenderTarget & target, sf::RenderStates states) const
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

sf::FloatRect Soldat::getGlobalBounds() const
{
	return this->getTransform().transformRect(sprite.getGlobalBounds());
}
