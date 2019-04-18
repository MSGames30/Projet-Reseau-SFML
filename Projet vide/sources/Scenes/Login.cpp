#include "Login.h"
#include "../Managers/GameManager.h"
#include "../Managers/PollEventManager.h"
#include "../Tools/Defines.h"
#include "../Tools/Enums.h"

#define PSEUDO_MIN 3
#define PSEUDO_MAX 10

Login::Login()
{
	font = new sf::Font();
	font->loadFromFile("resources/fonts/Subscribe.ttf");

	logoText.setFont(*font);
	logoText.setCharacterSize(200);
	logoText.setString("TANK");
	logoText.setOrigin(logoText.getGlobalBounds().width / 2, 0);
	logoText.setPosition(WINDOW_SIZE.x / 2, 0);

	textBox.setSize(sf::Vector2f(540, 120));
	textBox.setFillColor(sf::Color::Black);
	textBox.setOutlineColor(sf::Color::White);
	textBox.setOutlineThickness(5);
	textBox.setOrigin(textBox.getGlobalBounds().width / 2, textBox.getGlobalBounds().height / 2);
	textBox.setPosition(WINDOW_SIZE.x / 2, TEXTBOX_POS_Y);

	enterName.setFont(*font);
	enterName.setCharacterSize(50);
	enterName.setString("PSEUDO ! 3 A 10 LETTRES OU CHIFFRES ! :");
	enterName.setOrigin(enterName.getGlobalBounds().width / 2, enterName.getGlobalBounds().height);
	enterName.setPosition(textBox.getPosition().x, textBox.getGlobalBounds().top - 30);


	playerName.setFont(*font);
	playerName.setCharacterSize(100);
	nameString = "";
	playerName.setString(nameString);
	playerName.setOrigin(0, 0);
	playerName.setPosition(textBox.getGlobalBounds().left + 30, textBox.getGlobalBounds().top);

	//sf::Text enterName;
	//sf::Text playerName;

	logInButton = new Button("ENTRER", sf::Color::Green, 75, sf::Vector2f(WINDOW_SIZE.x / 2, 900),false);

	isMousePressed = false;

	std::cout << "login constructor" << std::endl;
	PollEventManager::Instance()->resetString();
	PollEventManager::Instance()->setStringMaxSiZe(10);

}


Login::~Login()
{
	delete font;
	delete logInButton;
}

void Login::update()
{
	//while (GameManager::Instance()->getWindow().pollEvent(pollEvent))
	//{
	//	if (pollEvent.type == sf::Event::Closed)
	//	{
	//		GameManager::Instance()->getWindow().close();
	//	}
	//	if (pollEvent.type == sf::Event::TextEntered)
	//	{
	//		//std::cout << "ASCII character typed: " << (pollEvent.text.unicode) << std::endl;
	//		if (pollEvent.text.unicode < 128)
	//		{
	//			if (pollEvent.text.unicode == 8)
	//			{
	//				if (nameString.size() != 0)
	//				{
	//					nameString.pop_back();
	//				}
	//				playerName.setString(nameString);
	//				if (nameString.size() < PSEUDO_MIN)
	//				{
	//					logInButton->setIsAvaible(false);
	//				}
	//			}
	//			//else if (pollEvent.text.unicode == 13)
	//			//{
	//			//	//networkManager->sendString(nameString);
	//			//	nameString.resize(0);
	//			//	playerName.setString(nameString);
	//			//}
	//			else
	//			{
	//				if (nameString.size() != PSEUDO_MAX)
	//				{
	//					if (pollEvent.text.unicode >= 97 && pollEvent.text.unicode <= 122)
	//					{
	//						nameString += (char)(pollEvent.text.unicode ) - 32;
	//						playerName.setString(nameString);
	//					}
	//					if ((pollEvent.text.unicode >= 48 && pollEvent.text.unicode <= 57) || (pollEvent.text.unicode >= 65 && pollEvent.text.unicode <= 90))
	//					{
	//						nameString += (char)(pollEvent.text.unicode);
	//						playerName.setString(nameString);
	//					}
	//					if (nameString.size() >= PSEUDO_MIN)
	//					{
	//						logInButton->setIsAvaible(true);
	//					}
	//				}

	//			}

	//		}
	//		std::cout << "String : " << nameString << std::endl;
	//	}
	//}
	nameString = PollEventManager::Instance()->getString();
	playerName.setString(nameString);
	if (nameString.size() >= 3)
	{
		logInButton->setIsAvaible(true);
	}
	else
	{
		logInButton->setIsAvaible(false);
	}

	if (logInButton->isOver(sf::Mouse::getPosition(GameManager::Instance()->getWindow())) && logInButton->getIsAvaible())
	{
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && !isMousePressed)
		{
			isMousePressed = true;
			GameManager::Instance()->loadScene(enums::SceneName::LOBBY, nameString);
		}
		else if (!sf::Mouse::isButtonPressed(sf::Mouse::Left) && isMousePressed)
		{
			isMousePressed = false;
		}
	}

}

void Login::display()
{
	GameManager::Instance()->getWindow().draw(logoText);
	GameManager::Instance()->getWindow().draw(textBox);
	GameManager::Instance()->getWindow().draw(playerName);
	GameManager::Instance()->getWindow().draw(enterName);
	GameManager::Instance()->getWindow().draw(*logInButton);

}
