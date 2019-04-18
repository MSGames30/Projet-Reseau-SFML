#include "Ennemy.h"



Ennemy::Ennemy()
{
	
}


Ennemy::~Ennemy()
{
}

void Ennemy::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	target.draw(sprite, this->getTransform());
}

void Ennemy::Move()
{
	/*if (state_ennemy == WALK)
	{
		if (angle_add <= 0)
		{
			angle_min = angle - 20;
			angle_max = angle + 20;

			angle_add = rand() % int(angle_max) + int(angle_min) - int(angle_min);

			if (rand() % 2 == 1)
			{
				if (angle_add < 0)
				{
					angle_add *= -1;
				}
			}
			else
			{
				if (angle_add > 0)
				{
					angle_add *= -1;
				}
			}

			std::cout << "Angle Add : " << angle_add << std::endl;
			angle_new = angle_add + angle;
		}

		if (angle != angle_new)
		{
			if (angle_add < 0)
			{
				angle -= 1;
			}
			else
			{
				angle += 1;
			}
		}
		else
		{

			angle_add = 0;
		}
	}
	else
	{
		std::cout << "Reset Angle Add" << std::endl;*/
		angle = RadToDeg(GetAngleRadiansBetweenPoints(pos, posFollow));
	//}

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

enums::ennemies_Type Ennemy::getType()
{
	return type;
}

void Ennemy::updateStateEnnemy(enums::ennemies_Type _typeEnnemy)
{
	switch (state_ennemy)
	{
	case enums::STATE_ENNEMY::WALK:
		//Entre en zone Run
		if (Magnitude(pos - posFollow) < radiusRUN)
		{
			state_ennemy = enums::STATE_ENNEMY::SURPRISE;
			speed = 0;

			timerSurprise.restart();
		}
		break;

	case enums::STATE_ENNEMY::SURPRISE:
		if (timerSurprise.getElapsedTime().asSeconds() > coolDownSuprise)
		{
			state_ennemy = enums::STATE_ENNEMY::RUN;

			if (_typeEnnemy == enums::ennemies_Type::SOLDAT)
				speed = 100;
			else if (_typeEnnemy == enums::ennemies_Type::SOLDAT_LOURD)
				speed = 50;
			else if (_typeEnnemy == enums::ennemies_Type::SNIPER)
				speed = 0;
			else if (_typeEnnemy == enums::ennemies_Type::KAMIKAZ)
				speed = 130;
		}
		break;

	case enums::STATE_ENNEMY::RUN:
		//Entre en zone Attaque
		if (Magnitude(pos - posFollow) < radiusATTAQUE)
		{
			state_ennemy = enums::STATE_ENNEMY::ATTAQUE;
			if (_typeEnnemy == enums::ennemies_Type::SNIPER)
				speed = 75;
			else
				speed = 0;
		}

		//Sort de la zone Run
		if (Magnitude(pos - posFollow) > radiusRUN)
		{		
			state_ennemy = enums::STATE_ENNEMY::WALK;

			if (_typeEnnemy == enums::ennemies_Type::SOLDAT)
				speed = 70;
			else if (_typeEnnemy == enums::ennemies_Type::SOLDAT_LOURD)
				speed = 35;
			else if (_typeEnnemy == enums::ennemies_Type::SNIPER)
				speed = 55;
			else if (_typeEnnemy == enums::ennemies_Type::KAMIKAZ)
				speed = 85;
		}
		break;

	case enums::STATE_ENNEMY::ATTAQUE:
		//Sort de la zone Attaque
		if (Magnitude(pos - posFollow) > radiusATTAQUE)
		{
			state_ennemy = enums::STATE_ENNEMY::RUN;
			if (_typeEnnemy == enums::ennemies_Type::SOLDAT)
				speed = 100;
			else if (_typeEnnemy == enums::ennemies_Type::SOLDAT_LOURD)
				speed = 50;
			else if (_typeEnnemy == enums::ennemies_Type::KAMIKAZ)
				speed = 130;
			else if (_typeEnnemy == enums::ennemies_Type::SNIPER)
			speed = 0;
		}		
		break;
	}
}

enums::STATE_ENNEMY Ennemy::getState_ennemy()
{
	return state_ennemy;
}

void Ennemy::setState(enums::STATE_ENNEMY pState)
{
	state_ennemy = pState;
}

void Ennemy::applyDamage(float Damage)
{
	life -= Damage;
}
