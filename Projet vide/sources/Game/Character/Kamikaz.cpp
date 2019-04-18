#include "Kamikaz.h"



Kamikaz::Kamikaz()
{
}

Kamikaz::Kamikaz(enums::ennemies_Type ptype, sf::Vector2f _pos)
{
	type = ptype;
	life = 20;
	spriteSurprise = CreateSpriteFromPath("resources/textures/alert.png");
	spriteSurprise.setOrigin(spriteSurprise.getGlobalBounds().width / 2, spriteSurprise.getGlobalBounds().height / 2);

	sprite = CreateSpriteFromPath("resources/textures/Kamikaz.jpg");

	origin = { sprite.getGlobalBounds().width / 2, sprite.getGlobalBounds().height / 2 };
	this->setOrigin(origin);

	pos = _pos;
	this->setPosition(pos);
	spriteSurprise.setPosition(pos);

	state_ennemy = enums::STATE_ENNEMY::WALK;

	speed = 85;

	sf::Color colorCercle;

	radiusRUN = 800;
	cercleRUN = new sf::CircleShape();
	cercleRUN->setRadius(radiusRUN);
	cercleRUN->setPosition(pos);
	cercleRUN->setOrigin(radiusRUN, radiusRUN);
	colorCercle = sf::Color::Blue;
	colorCercle.a = 100;
	cercleRUN->setFillColor(colorCercle);

	radiusATTAQUE = 30;
	cercleATTAQUE = new sf::CircleShape();
	cercleATTAQUE->setRadius(radiusATTAQUE);
	cercleATTAQUE->setPosition(pos);
	cercleATTAQUE->setOrigin(radiusATTAQUE, radiusATTAQUE);
	colorCercle = sf::Color::Red;
	colorCercle.a = 100;
	cercleATTAQUE->setFillColor(colorCercle);

	coolDownSuprise = 0.80;
}

Kamikaz::~Kamikaz()
{
}

void Kamikaz::update()
{
}

void Kamikaz::update(sf::Vector2f _pos)
{
	posFollow = _pos;

	Ennemy::updateStateEnnemy(type);
	Ennemy::Move();

	if (state_ennemy == enums::STATE_ENNEMY::ATTAQUE)
	{
		// BOOOOOM
	}
}

void Kamikaz::Move()
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

void Kamikaz::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	//target.draw(*cercleRUN);
	//target.draw(*cercleATTAQUE);
	target.draw(sprite, this->getTransform());

	if (state_ennemy == enums::STATE_ENNEMY::SURPRISE)
	{
		target.draw(spriteSurprise);
	}
}

sf::FloatRect Kamikaz::getGlobalBounds() const
{
	return this->getTransform().transformRect(sprite.getGlobalBounds());
}