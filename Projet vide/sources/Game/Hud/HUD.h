#pragma once
#include "../Entities/DrawableObject.h"
#include "../../Tools/Enums.h"
#include <string>
class HUD :
	public DrawableObject
{
public:
	HUD();
	HUD(enums::TurretSlot pSlot, enums::TurretType pType, sf::String pName);
	~HUD();

	virtual void update();
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	virtual sf::FloatRect getGlobalBounds() const;

	void setString(sf::String pText);
	void setStringScore(std::string);

protected:
	sf::Texture texture;
	sf::Sprite sprite;

	sf::Text text;
	sf::Text textScore;
	sf::Font font;
	sf::String stringText;
	sf::String stringTextScore;
};

