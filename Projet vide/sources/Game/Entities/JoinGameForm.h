#pragma once
#include "DrawableObject.h"
#include "../Entities/Button.h"

class JoinGameForm :
	public DrawableObject
{
public:
	JoinGameForm();
	~JoinGameForm();
	virtual void update();
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	virtual sf::FloatRect getGlobalBounds() const;
	bool isOverSlot(int _slotNbr, sf::Vector2f _mousePos);
	bool isOverCanon(sf::Vector2i _mousePos, int _canonNbr);
	void setOutlineColorCanon(sf::Color _color, int _canonNbr);
	void setSelectedSlot(int _slotNbr);
	Button & getButton(int _btnNbr);
private:
	sf::RectangleShape backForm;

	sf::Font* font;

	sf::Text chooseSlotTitle;
	sf::Text chooseCanonTitle;

	sf::Texture* textureSkin;
	sf::RectangleShape tankSkin;

	sf::Texture* textureCanon;
	sf::RectangleShape tankCanon;

	sf::CircleShape slot1Circle;
	sf::CircleShape slot2Circle;
	sf::CircleShape slot3Circle;
	sf::CircleShape slot4Circle;

	sf::CircleShape selectionCircle;

	sf::Texture* textureCanon1;
	sf::Texture* textureCanon2;

	sf::RectangleShape tankCanon1;
	sf::RectangleShape tankCanon2;

	sf::FloatRect tankCanon1Bounds;
	sf::FloatRect tankCanon2Bounds;

	Button* joinBtn;
	Button* cancelBtn;

};

