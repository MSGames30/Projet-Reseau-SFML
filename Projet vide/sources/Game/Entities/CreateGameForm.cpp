#include "CreateGameForm.h"
#include "../../Managers/GameManager.h"
#include "../../Managers/PollEventManager.h"
#include "../../Tools/Defines.h"

CreateGameForm::CreateGameForm()
{
	backForm.setSize(sf::Vector2f(600,620));
	backForm.setFillColor(sf::Color::Black);
	backForm.setOutlineColor(sf::Color::White);
	backForm.setOutlineThickness(5);

	backForm.setPosition(backForm.getOutlineThickness(), backForm.getOutlineThickness());

	this->setOrigin(backForm.getGlobalBounds().width / 2, backForm.getGlobalBounds().height / 2);
	this->setPosition(WINDOW_SIZE.x / 2, WINDOW_SIZE.y / 2);

	gameNameBox.setSize(sf::Vector2f(500,50));
	gameNameBox.setFillColor(sf::Color::Black);
	gameNameBox.setOutlineColor(sf::Color::White);
	gameNameBox.setOutlineThickness(5);
	gameNameBox.setOrigin(gameNameBox.getGlobalBounds().width / 2, gameNameBox.getGlobalBounds().height / 2);
	gameNameBox.setPosition(backForm.getGlobalBounds().width / 2, 100);


	font = new sf::Font();
	font->loadFromFile("resources/fonts/Subscribe.ttf");
	gameNameTitle.setFont(*font);
	gameNameTitle.setCharacterSize(50);
	gameNameTitle.setString("NOM DE LA PARTIE : ");
	gameNameTitle.setOrigin(0, gameNameTitle.getGlobalBounds().height);
	gameNameTitle.setPosition(gameNameBox.getGlobalBounds().left, gameNameBox.getGlobalBounds().top - 25);

	//Button* createBtn;
	//Button* cancelBtn;
	chooseSkinTitle.setFont(*font);
	chooseSkinTitle.setCharacterSize(50);
	chooseSkinTitle.setString("CHOISIR LE SKIN :");
	chooseSkinTitle.setPosition(gameNameBox.getGlobalBounds().left, gameNameBox.getGlobalBounds().top + gameNameBox.getGlobalBounds().height);




	textureSkin1 = new sf::Texture();
	textureSkin1->loadFromFile("resources/textures/TankRouge.png");

	textureSkin2 = new sf::Texture();
	textureSkin2->loadFromFile("resources/textures/TankBleu.png");


	tankSkin1.setSize((sf::Vector2f)textureSkin1->getSize());
	tankSkin1.setTexture(textureSkin1);
	tankSkin1.setOutlineColor(sf::Color::Transparent);
	tankSkin1.setOutlineThickness(5);
	tankSkin1.setOrigin(tankSkin1.getGlobalBounds().width / 2, 0);
	tankSkin1.setPosition(gameNameBox.getPosition().x - (tankSkin1.getGlobalBounds().width / 2) - 20, chooseSkinTitle.getGlobalBounds().top + chooseSkinTitle.getGlobalBounds().height + 20);
	tankSkin1.setScale(0.7, 0.7);

	tankSkin2.setSize((sf::Vector2f)textureSkin2->getSize());
	tankSkin2.setTexture(textureSkin2);
	tankSkin2.setOutlineColor(sf::Color::Transparent);
	tankSkin2.setOutlineThickness(5);
	tankSkin2.setOrigin(tankSkin2.getGlobalBounds().width / 2, 0);
	tankSkin2.setPosition(gameNameBox.getPosition().x + (tankSkin2.getGlobalBounds().width / 2) + 20, chooseSkinTitle.getGlobalBounds().top + chooseSkinTitle.getGlobalBounds().height + 20);
	tankSkin2.setScale(0.7, 0.7);

	isSkin1Selected = false;
	isSkin2Selected = false;
	
	tankSkin1Bounds = this->getTransform().transformRect(tankSkin1.getGlobalBounds());
	tankSkin2Bounds = this->getTransform().transformRect(tankSkin2.getGlobalBounds());


	chooseCanonTitle = sf::Text(chooseSkinTitle);
	chooseCanonTitle.setString("CHOISIR LE CANON :");
	chooseCanonTitle.setPosition(gameNameBox.getGlobalBounds().left, tankSkin1.getGlobalBounds().top + tankSkin1.getGlobalBounds().height + 25);


	textureCanon1 = new sf::Texture();
	textureCanon1->loadFromFile("resources/textures/canonSimple.png");

	textureCanon2 = new sf::Texture();
	textureCanon2->loadFromFile("resources/textures/canonTriple.png");


	tankCanon1.setSize((sf::Vector2f)textureCanon1->getSize());
	tankCanon1.setTexture(textureCanon1);
	tankCanon1.setOutlineColor(sf::Color::Transparent);
	tankCanon1.setOutlineThickness(3.5);
	tankCanon1.setOrigin(tankCanon1.getGlobalBounds().width/2, tankCanon1.getGlobalBounds().height / 2);
	tankCanon1.rotate(90);
	tankCanon1.setPosition(tankSkin1.getPosition().x, chooseCanonTitle.getGlobalBounds().top + chooseCanonTitle.getGlobalBounds().height + 60);

	tankCanon2.setSize((sf::Vector2f)textureCanon2->getSize());
	tankCanon2.setTexture(textureCanon2);
	tankCanon2.setOutlineColor(sf::Color::Transparent);
	tankCanon2.setOutlineThickness(3.5);
	tankCanon2.setOrigin(tankCanon2.getGlobalBounds().width / 2, tankCanon2.getGlobalBounds().height / 2);
	tankCanon2.setPosition(tankSkin2.getPosition().x , chooseCanonTitle.getGlobalBounds().top + chooseCanonTitle.getGlobalBounds().height + 60);

	isCanon1Selected = false;
	isCanon2Selected = false;

	tankCanon1Bounds = this->getTransform().transformRect(tankCanon1.getGlobalBounds());
	tankCanon2Bounds = this->getTransform().transformRect(tankCanon2.getGlobalBounds());


	createBtn = new Button("CREER",sf::Color::Green,50,sf::Vector2f(tankCanon2.getPosition().x + 20, tankCanon2.getGlobalBounds().top + tankCanon2.getGlobalBounds().height + 80),false,this->getTransform());
	cancelBtn = new Button("ANNULER", sf::Color::Green, 50, sf::Vector2f(tankCanon1.getPosition().x - 20, tankCanon2.getGlobalBounds().top + tankCanon2.getGlobalBounds().height + 80), true, this->getTransform());;

	//createBtn->setPosition(sf::Vector2f(tankCanon2.getPosition().x + 20, tankCanon2.getGlobalBounds().top + tankCanon2.getGlobalBounds().height + 80));

	playerName.setFont(*font);
	playerName.setCharacterSize(50);
	nameString = "";
	playerName.setString(nameString);
	playerName.setOrigin(0, 0);
	playerName.setPosition(gameNameBox.getGlobalBounds().left +10, gameNameBox.getGlobalBounds().top);
}


CreateGameForm::~CreateGameForm()
{
}

void CreateGameForm::update()
{
	nameString = PollEventManager::Instance()->getString();
	playerName.setString(nameString);
}

void CreateGameForm::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	target.draw(backForm, this->getTransform());
	target.draw(gameNameBox, this->getTransform());
	target.draw(gameNameTitle, this->getTransform());
	target.draw(chooseSkinTitle, this->getTransform());
	target.draw(chooseCanonTitle, this->getTransform());



	target.draw(tankSkin1, this->getTransform());
	target.draw(tankSkin2, this->getTransform());
	target.draw(tankCanon1, this->getTransform());
	target.draw(tankCanon2, this->getTransform());

	target.draw(*createBtn, this->getTransform());
	target.draw(*cancelBtn, this->getTransform());
	target.draw(playerName, this->getTransform());




}

sf::FloatRect CreateGameForm::getGlobalBounds() const
{
	return sf::FloatRect();
}

bool CreateGameForm::isOverTank(sf::Vector2i _mousePos, int _skinNbr)
{
	if (_skinNbr == 1)
	{
		if (tankSkin1Bounds.contains((sf::Vector2f)_mousePos))
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	else if (_skinNbr == 2)
	{
		if (tankSkin2Bounds.contains((sf::Vector2f)_mousePos))
		{
			return true;
		}
		else
		{
			return false;
		}
	}

}

void CreateGameForm::setOutlineColorSkin(sf::Color _color, int _skinNbr)
{
	if (_skinNbr == 1)
	{
		tankSkin1.setOutlineColor(_color);
	}
	else if (_skinNbr == 2)
	{
		tankSkin2.setOutlineColor(_color);
	}
}

bool CreateGameForm::getIsSelected(int _skinNbr)
{
	if (_skinNbr == 1)
	{
		return isSkin1Selected;
	}
	else if (_skinNbr == 2)
	{
		return isSkin2Selected;
	}
	else
	{
		return false;
	}
}

void CreateGameForm::setSkinSelected(int _skinNbr)
{
	if (_skinNbr == 1)
	{
		isSkin1Selected = true;
		isSkin2Selected = false;
	}
	else if (_skinNbr == 2)
	{
		isSkin1Selected = false;
		isSkin2Selected = true;
	}
}

bool CreateGameForm::isOverCanon(sf::Vector2i _mousePos, int _canonNbr)
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

void CreateGameForm::setOutlineColorCanon(sf::Color _color, int _canonNbr)
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

bool CreateGameForm::getIsSelectedCanon(int _canonNbr)
{
	if (_canonNbr == 1)
	{
		return isCanon1Selected;
	}
	else if (_canonNbr == 2)
	{
		return isCanon2Selected;
	}
	else
	{
		return false;
	}
}

void CreateGameForm::setCanonSelected(int _canonNbr)
{
	if (_canonNbr == 1)
	{
		isCanon1Selected = true;
		isCanon2Selected = false;
	}
	else if (_canonNbr == 2)
	{
		isCanon1Selected = false;
		isCanon2Selected = true;
	}
}

std::string CreateGameForm::getString()
{
	return nameString;
}

Button & CreateGameForm::getButton(int _btnNbr)
{
	if (_btnNbr == 1)
	{
		return *cancelBtn;
	}
	else if (_btnNbr == 2)
	{
		return *createBtn;
	}
}

void CreateGameForm::resetForm()
{
	PollEventManager::Instance()->resetString();
	PollEventManager::Instance()->setStringMaxSiZe(15);
	isSkin1Selected = false;
	isSkin2Selected = false;
	isCanon1Selected = false;
	isCanon2Selected = false;
}
