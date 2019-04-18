#include "HUD.h"
#include <iostream>


HUD::HUD()
{
}

HUD::HUD(enums::TurretSlot pSlot, enums::TurretType pType, sf::String pName)
{

}


HUD::~HUD()
{
}

void HUD::update()
{

}

void HUD::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	target.draw(sprite, this->getTransform());
	target.draw(text, this->getTransform());
}

sf::FloatRect HUD::getGlobalBounds() const
{
	return this->getTransform().transformRect(this->getGlobalBounds());
}

void HUD::setString(sf::String pText)
{
	stringText = pText;
	text.setString(stringText);
}

void HUD::setStringScore(std::string pText)
{
	stringTextScore = pText;
	textScore.setString(stringTextScore);
	
	//std::string tmpString = pText;
	//std::cout <<"[Turret]->String: "<< pText << std::endl;
}
