#pragma once
#include "DrawableObject.h"
#include "Button.h"
#include <string>

class CreateGameForm :
	public DrawableObject
{
public:
	CreateGameForm();
	~CreateGameForm();
	virtual void update();
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	virtual sf::FloatRect getGlobalBounds() const;
	bool isOverTank(sf::Vector2i _mousePos, int _skinNbr);
	void setOutlineColorSkin(sf::Color _color,int _skinNbr);
	bool getIsSelected(int _skinNbr);
	void setSkinSelected(int _skinNbr);

	bool isOverCanon(sf::Vector2i _mousePos, int _canonNbr);
	void setOutlineColorCanon(sf::Color _color, int _canonNbr);
	bool getIsSelectedCanon(int _canonNbr);
	void setCanonSelected(int _canonNbr);

	std::string getString();

	Button& getButton(int _btnNbr);

	void resetForm();
private:
	sf::RectangleShape backForm;
	sf::RectangleShape gameNameBox;

	Button* createBtn;
	Button* cancelBtn;

	sf::Font* font;

	sf::Text gameNameTitle;
	sf::Text chooseSkinTitle;

	sf::Texture* textureSkin1;
	sf::Texture* textureSkin2;

	sf::RectangleShape tankSkin1;
	sf::RectangleShape tankSkin2;

	bool isSkin1Selected;
	bool isSkin2Selected;

	sf::FloatRect tankSkin1Bounds;
	sf::FloatRect tankSkin2Bounds;


	sf::Text chooseCanonTitle;

	sf::Texture* textureCanon1;
	sf::Texture* textureCanon2;

	sf::RectangleShape tankCanon1;
	sf::RectangleShape tankCanon2;

	bool isCanon1Selected;
	bool isCanon2Selected;

	sf::FloatRect tankCanon1Bounds;
	sf::FloatRect tankCanon2Bounds;

	sf::Text playerName;
	std::string nameString;
};

