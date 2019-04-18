#include "Button.h"
#include "../../Managers/GameManager.h"
#include "../../Tools/Defines.h"

#define TEXT_OFFSET sf::Vector2f(1.5f,0.03f)
#define TEXT_OUTLINE_OFFSET 0.01f
#define RECTANGLE_OUTLINE_OFFSET 0.05f


Button::Button(std::string _buttonText, sf::Color _backColor, float _charSize, sf::Vector2f _pos, bool _isAvaible)
{
	this->setPosition(_pos);

	font = new sf::Font();
	font->loadFromFile("resources/fonts/Subscribe.ttf");

	buttonText.setFont(*font);
	buttonText.setCharacterSize(_charSize);
	buttonText.setString(_buttonText);
	buttonText.setOutlineColor(sf::Color::Black);
	buttonText.setOutlineThickness(_charSize * TEXT_OUTLINE_OFFSET);
	buttonText.setOrigin(buttonText.getGlobalBounds().width / 2, buttonText.getGlobalBounds().height - (_charSize * TEXT_OFFSET.y));


	button.setSize(sf::Vector2f(buttonText.getGlobalBounds().width * TEXT_OFFSET.x, buttonText.getGlobalBounds().height* TEXT_OFFSET.x));
	backColor = _backColor;
	button.setFillColor(backColor);
	button.setOutlineColor(sf::Color::White);
	button.setOutlineThickness(_charSize * RECTANGLE_OUTLINE_OFFSET);

	this->setOrigin(button.getGlobalBounds().width/2, button.getGlobalBounds().height / 2);
	
	buttonText.setPosition(button.getPosition().x + button.getGlobalBounds().width/2, button.getPosition().y + button.getGlobalBounds().height / 2);
	isAvaible = _isAvaible;
	if (isAvaible)
	{
		button.setFillColor(backColor);
	}
	else
	{
		button.setFillColor(BTN_GREY);
	}

}

Button::Button(std::string _buttonText, sf::Color _backColor, float _charSize, sf::Vector2f _pos, bool _isAvaible, sf::Transform _transform)
{
	this->setPosition(_pos);

	font = new sf::Font();
	font->loadFromFile("resources/fonts/Subscribe.ttf");

	buttonText.setFont(*font);
	buttonText.setCharacterSize(_charSize);
	buttonText.setString(_buttonText);
	buttonText.setOutlineColor(sf::Color::Black);
	buttonText.setOutlineThickness(_charSize * TEXT_OUTLINE_OFFSET);
	buttonText.setOrigin(buttonText.getGlobalBounds().width / 2, buttonText.getGlobalBounds().height - (_charSize * TEXT_OFFSET.y));


	button.setSize(sf::Vector2f(buttonText.getGlobalBounds().width * TEXT_OFFSET.x, buttonText.getGlobalBounds().height* TEXT_OFFSET.x));
	backColor = _backColor;
	button.setFillColor(backColor);
	button.setOutlineColor(sf::Color::White);
	button.setOutlineThickness(_charSize * RECTANGLE_OUTLINE_OFFSET);

	this->setOrigin(button.getGlobalBounds().width / 2, button.getGlobalBounds().height / 2);

	buttonText.setPosition(button.getPosition().x + button.getGlobalBounds().width / 2, button.getPosition().y + button.getGlobalBounds().height / 2);
	isAvaible = _isAvaible;
	if (isAvaible)
	{
		button.setFillColor(backColor);
	}
	else
	{
		button.setFillColor(BTN_GREY);
	}
	transform = _transform;
}


Button::~Button()
{
}

void Button::update()
{
}

void Button::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	transform = states.transform;
	//states.transform *= this->getTransform();
	GameManager::Instance()->getWindow().draw(button, this->getTransform()* states.transform);
	GameManager::Instance()->getWindow().draw(buttonText, this->getTransform() * states.transform);
}

sf::FloatRect Button::getGlobalBounds() const
{
	transform *= this->getTransform();
	//std::cout << "GET GLOBLA" << std::endl;
	return transform.transformRect(button.getGlobalBounds());

}

bool Button::isOver(sf::Vector2i _mousePos)
{
	if (this->getGlobalBounds().contains(sf::Vector2f(_mousePos)))
	{
		button.setOutlineColor(sf::Color::Red);
		return true;
	}
	else
	{
		button.setOutlineColor(sf::Color::White);
		return false;
	}
}

bool Button::getIsAvaible()
{
	return isAvaible;
}

void Button::setIsAvaible(bool _state)
{
	isAvaible = _state;
	if (isAvaible)
	{
		button.setFillColor(backColor);
	}
	else
	{
		button.setFillColor(BTN_GREY);
	}
}
