#pragma once
#include <SFML\Graphics.hpp>



class DrawableObject : public sf::Drawable , public sf::Transformable 
{
public:
	DrawableObject();
	~DrawableObject();
	virtual void update() = 0;
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const = 0;
	virtual sf::FloatRect getGlobalBounds() const = 0;
private:
	sf::Drawable * drawableObject;
};

