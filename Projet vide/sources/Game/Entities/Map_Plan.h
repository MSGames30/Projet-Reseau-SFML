#pragma once
#include "../Entities/DrawableObject.h"
class Map_Plan :
	public DrawableObject
{
public:

	Map_Plan();
	Map_Plan(std::string _pathTexture);
	~Map_Plan();

	virtual void update();
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	virtual sf::FloatRect getGlobalBounds() const;

	///mettre en accesseur si possible
	//void setIdPlan(int _IDPlan) { p_iIDPlan = _IDPlan; }
	//int getIdPlan() { return p_iIDPlan; }

	sf::Sprite* p_sprite;
	int p_iIDPlan;

private:


};

