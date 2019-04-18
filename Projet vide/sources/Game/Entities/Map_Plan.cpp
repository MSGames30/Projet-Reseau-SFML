#include "Map_Plan.h"
#include "../../Tools/ToolsSFML.h"

Map_Plan::Map_Plan()
{
}

Map_Plan::Map_Plan(std::string _pathTexture)
{
	p_sprite = ToolsSFML::CreateSpriteFromPathPointer(_pathTexture);
}

Map_Plan::~Map_Plan()
{
}

void Map_Plan::update()
{
}

void Map_Plan::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	if (p_sprite != NULL)
	{
		target.draw(*p_sprite, this->getTransform());
	}
}

sf::FloatRect Map_Plan::getGlobalBounds() const
{
	return this->getTransform().transformRect(p_sprite->getGlobalBounds());
}
