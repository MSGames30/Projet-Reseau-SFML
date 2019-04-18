#include "elementHud.h"
#include "../../Tools/Defines.h"


elementHud::elementHud()
{
	texture.loadFromFile("resources/textures/hud/lifeBar.png");
	sprite.setTexture(texture);
	sprite.setOrigin(this->getGlobalBounds().width / 2, this->getGlobalBounds().height);
	this->setPosition(sf::Vector2f(WINDOW_SIZE.x / 2, WINDOW_SIZE.y -20));
}

elementHud::elementHud(enums::TurretSlot pSlot, enums::TurretType pType, sf::String pName)
{
	switch (pType)
	{
	case enums::TurretType::INCENDIARY:
		texture.loadFromFile("resources/textures/hud/incendiaryIcone.png");
		break;
	case enums::TurretType::SUBMACHINE:
		texture.loadFromFile("resources/textures/hud/submachineIcone.png");
		break;
	case enums::TurretType::MAIN_CANON_SIMPLE:
		texture.loadFromFile("resources/textures/hud/canonSimpleIcone.png");
		break;
	case enums::TurretType::MAIN_CANON_TRIPLE:
		texture.loadFromFile("resources/textures/hud/canonTripleIcone.png");
		break;
	case enums::TurretType::NONE:
		texture.loadFromFile("resources/textures/hud/noneIcone.png");
		break;
	default:
		break;
	}
	sprite.setTexture(texture);
	setOrigin(this->getGlobalBounds().width / 2, this->getGlobalBounds().height);
	switch (pSlot)
	{
	case enums::TurretSlot::SLOT_1:
		this->setPosition(813-43, WINDOW_SIZE.y - 100);
		break;
	case enums::TurretSlot::SLOT_2:
		this->setPosition(911 - 43, WINDOW_SIZE.y - 100);
		break;
	case enums::TurretSlot::SLOT_3:
		this->setPosition(1009 - 43, WINDOW_SIZE.y - 100);
		break;
	case enums::TurretSlot::SLOT_4:
		this->setPosition(1107 - 43, WINDOW_SIZE.y - 100);
		break;
	case enums::TurretSlot::SLOT_5:
		this->setPosition(1205 - 43, WINDOW_SIZE.y - 100);
		break;
	default:
		break;
	}

	font.loadFromFile("resources/fonts/Subscribe.ttf");
	text.setFont(font);
	text.setCharacterSize(25);
	stringText = pName;
	text.setString(stringText);
	text.setOrigin(0, this->getGlobalBounds().height / 2);
	text.setPosition(this->getGlobalBounds().width, this->getGlobalBounds().height /3);

	font.loadFromFile("resources/fonts/Subscribe.ttf");
	textScore.setFont(font);
	textScore.setCharacterSize(25);
	stringTextScore = "0";
	textScore.setString(stringTextScore);
	textScore.setOrigin(0, this->getGlobalBounds().height / 2);
	textScore.setPosition(text.getPosition().x , text.getPosition().y + text.getGlobalBounds().height + 5);

}


elementHud::~elementHud()
{
}

void elementHud::update()
{
}

void elementHud::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	target.draw(sprite, this->getTransform());
	target.draw(text, this->getTransform());
	target.draw(textScore , this->getTransform());
}

sf::FloatRect elementHud::getGlobalBounds() const
{
	return this->getTransform().transformRect(sprite.getGlobalBounds());
}
