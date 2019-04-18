#pragma once
#include "DrawableObject.h"
#include "../Character/Soldat.h"
#include "../Character/SoldatLourd.h"
#include "../Character/Sniper.h"
#include "../Character/Kamikaz.h"
#include "../Entities/Map_Plan.h"
#include "Base.h"

class Map :
	public DrawableObject
{
public:
	Map();
	~Map();

	void update();
	void update(sf::Vector2f pPosTank);
	void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	sf::FloatRect getGlobalBounds() const;
	void ManageBases(sf::Vector2f _vPosTank);

	std::vector<Ennemy*> getListEnnemy();
	std::vector<Base*> getListBase() { return listBase; };

	Map_Plan* p_MapPlan1;
	Map_Plan* p_MapPlan2;

	Map_Plan* p_MapCurrent;
	Map_Plan* p_MapOther;
private:
	std::vector<Ennemy*> listEnnemy;
	bool p_bSecureDeleteBase = false;
	std::vector<Base*> listBase;
};

