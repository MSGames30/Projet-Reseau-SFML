#include "JoinGameForm.h"
#include"../../Tools/Defines.h"
#include "../../Tools/UtilsCpp.h"
#include "../../Managers/PollEventManager.h"


JoinGameForm::JoinGameForm()
{
	backForm.setSize(sf::Vector2f(600, 620));
	backForm.setFillColor(sf::Color::Black);
	backForm.setOutlineColor(sf::Color::White);
	backForm.setOutlineThickness(5);

	backForm.setPosition(backForm.getOutlineThickness(), backForm.getOutlineThickness());

	this->setOrigin(backForm.getGlobalBounds().width / 2, backForm.getGlobalBounds().height / 2);
	this->setPosition(WINDOW_SIZE.x / 2, WINDOW_SIZE.y / 2);

	font = new sf::Font();
	font->loadFromFile("resources/fonts/Subscribe.ttf");
	chooseSlotTitle.setFont(*font);
	chooseSlotTitle.setCharacterSize(50);
	chooseSlotTitle.setString("CHOISIR UN SLOT : ");
	chooseSlotTitle.setOrigin(0, 0);
	chooseSlotTitle.setPosition(50, 10);




	//TODO recuperer le slot et la tourelle choisie de la partie qu'on veut rejoindre
	textureSkin = new sf::Texture();
	textureSkin->loadFromFile("resources/textures/TankRouge.png");

	tankSkin.setSize((sf::Vector2f)textureSkin->getSize());
	tankSkin.setTexture(textureSkin);
	tankSkin.setOutlineColor(sf::Color::Transparent);
	tankSkin.setOutlineThickness(5);
	tankSkin.setOrigin(tankSkin.getGlobalBounds().width / 2, tankSkin.getGlobalBounds().height / 2);
	tankSkin.setRotation(90);
	tankSkin.setPosition(backForm.getGlobalBounds().width / 2, chooseSlotTitle.getGlobalBounds().top + chooseSlotTitle.getGlobalBounds().height + (tankSkin.getGlobalBounds().height / 2) + 30);



	//tankSkin.setScale(0.7, 0.7);
	//sf::RectangleShape tankSkin;

	textureCanon = new sf::Texture();
	textureCanon->loadFromFile("resources/textures/canonSimple.png");

	tankCanon.setSize((sf::Vector2f)textureCanon->getSize());
	tankCanon.setTexture(textureCanon);
	tankCanon.setOutlineColor(sf::Color::Transparent);
	tankCanon.setOutlineThickness(3.5);
	tankCanon.setOrigin(tankCanon.getGlobalBounds().width / 2, 108.5);
	tankCanon.rotate(90);
	tankCanon.setPosition(tankSkin.getPosition().x, tankSkin.getPosition().y);

	slot1Circle.setRadius(16);
	slot1Circle.setOrigin(16, 16);
	slot1Circle.setPosition(tankCanon.getPosition().x - 62 + 5, tankCanon.getPosition().y - 51 -5);
	slot1Circle.setOutlineColor(sf::Color::Blue);
	slot1Circle.setOutlineThickness(2);
	slot1Circle.setFillColor(sf::Color::Transparent);


	slot2Circle.setRadius(16);
	slot2Circle.setOrigin(16, 16);
	slot2Circle.setPosition(tankCanon.getPosition().x - 62 +5, tankCanon.getPosition().y + 51 -5);
	slot2Circle.setOutlineColor(sf::Color::Blue);
	slot2Circle.setOutlineThickness(2);
	slot2Circle.setFillColor(sf::Color::Transparent);


	slot3Circle.setRadius(16);
	slot3Circle.setOrigin(16, 16);
	slot3Circle.setPosition(tankCanon.getPosition().x + 62+5, tankCanon.getPosition().y + 51-5);
	slot3Circle.setOutlineColor(sf::Color::Blue);
	slot3Circle.setOutlineThickness(2);
	slot3Circle.setFillColor(sf::Color::Transparent);


	slot4Circle.setRadius(16);
	slot4Circle.setOrigin(16, 16);
	slot4Circle.setPosition(tankCanon.getPosition().x + 62+5, tankCanon.getPosition().y - 51-5);
	slot4Circle.setOutlineColor(sf::Color::Blue);
	slot4Circle.setOutlineThickness(2);
	slot4Circle.setFillColor(sf::Color::Transparent);

	selectionCircle = sf::CircleShape(slot4Circle);
	selectionCircle.setRadius(20);
	selectionCircle.setOrigin(20, 20);
	selectionCircle.setOutlineColor(sf::Color::Transparent);
	selectionCircle.setOutlineThickness(3);


	chooseCanonTitle = sf::Text(chooseSlotTitle);
	chooseCanonTitle.setString("CHOISIR LE CANON : ");
	chooseCanonTitle.setPosition(50, tankSkin.getGlobalBounds().top + tankSkin.getGlobalBounds().height + 20);

	textureCanon1 = new sf::Texture();
	textureCanon1->loadFromFile("resources/textures/submachine.png");

	textureCanon2 = new sf::Texture();
	textureCanon2->loadFromFile("resources/textures/turretIncendiary.png");


	tankCanon1.setSize((sf::Vector2f)textureCanon1->getSize());
	tankCanon1.setTexture(textureCanon1);
	tankCanon1.setOutlineColor(sf::Color::Transparent);
	tankCanon1.setOutlineThickness(3.5);
	tankCanon1.setOrigin(tankCanon1.getGlobalBounds().width / 2, tankCanon1.getGlobalBounds().height / 2);
	tankCanon1.rotate(90);
	tankCanon1.setScale(1.5, 1.5);
	tankCanon1.setPosition((backForm.getGlobalBounds().width/2) - (tankCanon1.getGlobalBounds().width/2)  - 20 , chooseCanonTitle.getGlobalBounds().top + chooseCanonTitle.getGlobalBounds().height + 80);

	tankCanon2.setSize((sf::Vector2f)textureCanon2->getSize());
	tankCanon2.setTexture(textureCanon2);
	tankCanon2.setOutlineColor(sf::Color::Transparent);
	tankCanon2.setOutlineThickness(3.5);
	tankCanon2.setOrigin(tankCanon2.getGlobalBounds().width / 2, tankCanon2.getGlobalBounds().height / 2);
	tankCanon2.setScale(1.5, 1.5);
	tankCanon2.setPosition((backForm.getGlobalBounds().width / 2) + (tankCanon1.getGlobalBounds().width / 2) + 20, chooseCanonTitle.getGlobalBounds().top + chooseCanonTitle.getGlobalBounds().height + 80);

	tankCanon1Bounds = this->getTransform().transformRect(tankCanon1.getGlobalBounds());
	tankCanon2Bounds = this->getTransform().transformRect(tankCanon2.getGlobalBounds());

	joinBtn = new Button("REJOINDRE", sf::Color::Green, 50, sf::Vector2f(tankCanon2.getPosition().x + 60, tankCanon2.getGlobalBounds().top + tankCanon2.getGlobalBounds().height + 80), false, this->getTransform());
	cancelBtn = new Button("ANNULER", sf::Color::Green, 50, sf::Vector2f(tankCanon1.getPosition().x - 60, tankCanon2.getGlobalBounds().top + tankCanon2.getGlobalBounds().height + 80), true, this->getTransform());;


}


JoinGameForm::~JoinGameForm()
{
}

void JoinGameForm::update()
{

}

void JoinGameForm::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	target.draw(backForm, this->getTransform());
	
	target.draw(chooseSlotTitle, this->getTransform());
	target.draw(chooseCanonTitle, this->getTransform());

	target.draw(tankSkin, this->getTransform());
	target.draw(tankCanon, this->getTransform());

	target.draw(slot1Circle, this->getTransform());
	target.draw(slot2Circle, this->getTransform());
	target.draw(slot3Circle, this->getTransform());
	target.draw(slot4Circle, this->getTransform());
	target.draw(selectionCircle, this->getTransform());

	target.draw(tankCanon1, this->getTransform());
	target.draw(tankCanon2, this->getTransform());

	target.draw(*joinBtn, this->getTransform());
	target.draw(*cancelBtn, this->getTransform());
		   	 
}

sf::FloatRect JoinGameForm::getGlobalBounds() const
{
	return sf::FloatRect();
}

bool JoinGameForm::isOverSlot(int _slotNbr,sf::Vector2f _mousePos)
{
	switch (_slotNbr)
	{
	case 1:
		if (Magnitude(this->getTransform().transformPoint(slot1Circle.getPosition()) - _mousePos) < slot1Circle.getRadius())
		{
			selectionCircle.setPosition(slot1Circle.getPosition());
			selectionCircle.setOutlineColor(sf::Color::Red);
			return true;
		}
		else
		{
			selectionCircle.setOutlineColor(sf::Color::Transparent);
			return false;
		}
		break;
	case 2:
		if (Magnitude(this->getTransform().transformPoint(slot2Circle.getPosition()) - _mousePos) < slot2Circle.getRadius())
		{
			selectionCircle.setPosition(slot2Circle.getPosition());
			selectionCircle.setOutlineColor(sf::Color::Red);
			return true;
		}
		else
		{
			selectionCircle.setOutlineColor(sf::Color::Transparent);
			return false;
		}
		break;
	case 3:
		if (Magnitude(this->getTransform().transformPoint(slot3Circle.getPosition()) - _mousePos) < slot3Circle.getRadius())
		{
			selectionCircle.setPosition(slot3Circle.getPosition());
			selectionCircle.setOutlineColor(sf::Color::Red);
			return true;
		}
		else
		{
			selectionCircle.setOutlineColor(sf::Color::Transparent);
			return false;
		}
		break;
	case 4:
		if (Magnitude(this->getTransform().transformPoint(slot4Circle.getPosition()) - _mousePos) < slot4Circle.getRadius())
		{
			selectionCircle.setPosition(slot4Circle.getPosition());
			selectionCircle.setOutlineColor(sf::Color::Red);
			return true;
		}
		else
		{
			selectionCircle.setOutlineColor(sf::Color::Transparent);
			return false;
		}
		break;
	default:
		return false;
		break;
	}
}

bool JoinGameForm::isOverCanon(sf::Vector2i _mousePos, int _canonNbr)
{
	if (_canonNbr == 1)
	{
		if (tankCanon1Bounds.contains((sf::Vector2f)_mousePos))
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	else if (_canonNbr == 2)
	{
		if (tankCanon2Bounds.contains((sf::Vector2f)_mousePos))
		{
			return true;
		}
		else
		{
			return false;
		}
	}
}

void JoinGameForm::setOutlineColorCanon(sf::Color _color, int _canonNbr)
{
	if (_canonNbr == 1)
	{
		tankCanon1.setOutlineColor(_color);
	}
	else if (_canonNbr == 2)
	{
		tankCanon2.setOutlineColor(_color);
	}
}

void JoinGameForm::setSelectedSlot(int _slotNbr)
{
	switch (_slotNbr)
	{
	case 1:
		slot1Circle.setOutlineColor(sf::Color::Green);
		slot2Circle.setOutlineColor(sf::Color::Blue);
		slot3Circle.setOutlineColor(sf::Color::Blue);
		slot4Circle.setOutlineColor(sf::Color::Blue);
		break;
	case 2:
		slot1Circle.setOutlineColor(sf::Color::Blue);
		slot2Circle.setOutlineColor(sf::Color::Green);
		slot3Circle.setOutlineColor(sf::Color::Blue);
		slot4Circle.setOutlineColor(sf::Color::Blue);
		break;
	case 3:
		slot1Circle.setOutlineColor(sf::Color::Blue);
		slot2Circle.setOutlineColor(sf::Color::Blue);
		slot3Circle.setOutlineColor(sf::Color::Green);
		slot4Circle.setOutlineColor(sf::Color::Blue);
		break;
	case 4:
		slot1Circle.setOutlineColor(sf::Color::Blue);
		slot2Circle.setOutlineColor(sf::Color::Blue);
		slot3Circle.setOutlineColor(sf::Color::Blue);
		slot4Circle.setOutlineColor(sf::Color::Green);
		break;
	default:
		slot1Circle.setOutlineColor(sf::Color::Blue);
		slot2Circle.setOutlineColor(sf::Color::Blue);
		slot3Circle.setOutlineColor(sf::Color::Blue);
		slot4Circle.setOutlineColor(sf::Color::Blue);
		break;
	}
}

Button & JoinGameForm::getButton(int _btnNbr)
{
	if (_btnNbr == 1)
	{
		return *cancelBtn;
	}
	else if (_btnNbr == 2)
	{
		return *joinBtn;
	}
}


