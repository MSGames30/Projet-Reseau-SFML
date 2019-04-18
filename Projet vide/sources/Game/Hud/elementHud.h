#pragma once
#include "HUD.h"
class elementHud :
	public HUD
{
public:
	elementHud();
	elementHud(enums::TurretSlot pSlot, enums::TurretType pType, sf::String pName);
	~elementHud();

	virtual void update();
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	virtual sf::FloatRect getGlobalBounds() const;


};

