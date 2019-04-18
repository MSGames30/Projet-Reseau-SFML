#pragma once
#include "DrawableObject.h"
#include <string>

#define BTN_GREY sf::Color(150,150, 150, 75)

class Button :
	public DrawableObject
{
public:
	Button(std::string _buttonText, sf::Color _backColor, float _charSize, sf::Vector2f _pos,bool _isAvaible);
	Button(std::string _buttonText, sf::Color _backColor, float _charSize, sf::Vector2f _pos, bool _isAvaible, sf::Transform _transform);
	~Button();
	virtual void update();
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	virtual sf::FloatRect getGlobalBounds() const;
	bool isOver(sf::Vector2i _mousePos);
	bool getIsAvaible();
	void setIsAvaible(bool _state);
private:
	sf::Font* font;
	sf::Text buttonText;
	sf::Color backColor;
	sf::RectangleShape button;

	bool isAvaible;
	mutable sf::Transform transform;
};

