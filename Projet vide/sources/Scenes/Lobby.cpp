#include "Lobby.h"
#include "../Managers/ConnectManager.h"
#include "../Managers/GameManager.h"
#include "../Managers/PollEventManager.h"
#include "../Tools/Defines.h"

Lobby::Lobby()
{
}

Lobby::Lobby(std::string _playerName)
{
	font = new sf::Font();
	font->loadFromFile("resources/fonts/Subscribe.ttf");

	displayName.setFont(*font);
	displayName.setCharacterSize(50);

	player = new Player();
	player->setPlayerName(_playerName);
	ConnectManager::Instance()->init();
	ConnectManager::Instance()->sendMessage("-hello", sf::IpAddress::Broadcast);

	freeNamesBox.setSize(sf::Vector2f(700, 400));
	freeNamesBox.setFillColor(sf::Color::Black);
	freeNamesBox.setOutlineColor(sf::Color::White);
	freeNamesBox.setOutlineThickness(5);
	freeNamesBox.setPosition(130, WINDOW_SIZE.y / 2);

	inGameNamesBox = sf::RectangleShape(freeNamesBox);
	inGameNamesBox.setPosition(1060, WINDOW_SIZE.y / 2);


	freeNamesTitle.setFont(*font);
	freeNamesTitle.setCharacterSize(75);
	freeNamesTitle.setString("JOUEURS DISPO :");
	freeNamesTitle.setOrigin(0, freeNamesTitle.getGlobalBounds().top + freeNamesTitle.getGlobalBounds().height);
	freeNamesTitle.setPosition(freeNamesBox.getPosition().x, freeNamesBox.getPosition().y - 20);

	inGameNamesTitle = sf::Text(freeNamesTitle);
	inGameNamesTitle.setString("JOUEURS EN JEU :");
	inGameNamesTitle.setPosition(inGameNamesBox.getPosition().x, inGameNamesBox.getPosition().y - 20);

	gamesBox = sf::RectangleShape(freeNamesBox);
	gamesBox.setSize(sf::Vector2f(700, 300));
	gamesBox.setOrigin(0, 0);
	gamesBox.setPosition(freeNamesBox.getPosition().x, 125);

	gamesTitle = sf::Text(freeNamesTitle);
	gamesTitle.setString("PARTIES EN COURS :");
	gamesTitle.setPosition(gamesBox.getPosition().x, gamesBox.getPosition().y - 20);

	createGameBtn = new Button(" CREER ", sf::Color::Green, 75, sf::Vector2f(1425, 200), true);
	joinGameBtn = new Button("REJOINDRE", sf::Color::Green, 75, sf::Vector2f(1425, 350), true);

	sendTimer.restart();

	isCreatingGame = false;
	isJoiningGame = false;


	greyScreen.setSize(WINDOW_SIZE);
	greyScreen.setFillColor(sf::Color(150, 150, 150, 125));

	isMousePressed = false;

	PollEventManager::Instance()->resetString();
	PollEventManager::Instance()->setStringMaxSiZe(15);

	selectedSlot = 0;
	selectedCanon = 0;



	
}


Lobby::~Lobby()
{
	delete font;
}

void Lobby::update()
{


	if (sendTimer.getElapsedTime().asSeconds() > 3.0f)
	{
		sendTimer.restart();
		ConnectManager::Instance()->sendMessage("-hello", sf::IpAddress::Broadcast);
	}


	//MENU LOBBY
	if (!isCreatingGame && !isJoiningGame)
	{
		if (createGameBtn->isOver(sf::Mouse::getPosition(GameManager::Instance()->getWindow())) && createGameBtn->getIsAvaible())
		{
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{
				isCreatingGame = true;
			}
		}
		else if (joinGameBtn->isOver(sf::Mouse::getPosition(GameManager::Instance()->getWindow())) && joinGameBtn->getIsAvaible())
		{
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{
				isJoiningGame = true;
			}
		}


	}
	//// MENU CREER UNE PARTIE
	else if (isCreatingGame && !isJoiningGame)
	{
		creatGameForm.update();


		//SURVOL SKIN
		if (creatGameForm.isOverTank(sf::Mouse::getPosition(GameManager::Instance()->getWindow()), 1))
		{
			creatGameForm.setOutlineColorSkin(sf::Color::Red, 1);
			//creatGameForm.setOutlineColorSkin(sf::Color::Transparent, 2);
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{
				creatGameForm.setSkinSelected(1);
				creatGameForm.setOutlineColorSkin(sf::Color::Transparent, 2);
			}
		}
		else if (creatGameForm.isOverTank(sf::Mouse::getPosition(GameManager::Instance()->getWindow()), 2))
		{
			creatGameForm.setOutlineColorSkin(sf::Color::Red, 2);
			//creatGameForm.setOutlineColorSkin(sf::Color::Transparent, 1);
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{
				creatGameForm.setSkinSelected(2);
				creatGameForm.setOutlineColorSkin(sf::Color::Transparent, 1);
			}
		}
		else
		{
			if (creatGameForm.getIsSelected(1))
			{
				creatGameForm.setOutlineColorSkin(sf::Color::Green, 1);
				creatGameForm.setOutlineColorSkin(sf::Color::Transparent, 2);
			}
			else if (creatGameForm.getIsSelected(2))
			{
				creatGameForm.setOutlineColorSkin(sf::Color::Transparent, 1);
				creatGameForm.setOutlineColorSkin(sf::Color::Green, 2);
			}
			else
			{
				creatGameForm.setOutlineColorSkin(sf::Color::Transparent, 1);
				creatGameForm.setOutlineColorSkin(sf::Color::Transparent, 2);
			}
		}


		//SURVOL CANON
		if (creatGameForm.isOverCanon(sf::Mouse::getPosition(GameManager::Instance()->getWindow()), 1))
		{
			creatGameForm.setOutlineColorCanon(sf::Color::Red, 1);
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{
				creatGameForm.setCanonSelected(1);
				creatGameForm.setOutlineColorCanon(sf::Color::Transparent, 2);
			}
		}
		else if (creatGameForm.isOverCanon(sf::Mouse::getPosition(GameManager::Instance()->getWindow()), 2))
		{
			creatGameForm.setOutlineColorCanon(sf::Color::Red, 2);
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{
				creatGameForm.setCanonSelected(2);
				creatGameForm.setOutlineColorCanon(sf::Color::Transparent, 1);
			}
		}
		else
		{
			if (creatGameForm.getIsSelectedCanon(1))
			{
				creatGameForm.setOutlineColorCanon(sf::Color::Green, 1);
				creatGameForm.setOutlineColorCanon(sf::Color::Transparent, 2);
			}
			else if (creatGameForm.getIsSelectedCanon(2))
			{
				creatGameForm.setOutlineColorCanon(sf::Color::Transparent, 1);
				creatGameForm.setOutlineColorCanon(sf::Color::Green, 2);
			}
			else
			{
				creatGameForm.setOutlineColorCanon(sf::Color::Transparent, 1);
				creatGameForm.setOutlineColorCanon(sf::Color::Transparent, 2);
			}
		}

		//SURVOL BOUTONS
		if (creatGameForm.getButton(1).isOver(sf::Mouse::getPosition(GameManager::Instance()->getWindow())))
		{
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{
				isCreatingGame = false;
				creatGameForm.resetForm();
			}
		}
		else if (creatGameForm.getButton(2).isOver(sf::Mouse::getPosition(GameManager::Instance()->getWindow())))
		{
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{
				if ((creatGameForm.getIsSelectedCanon(1) || creatGameForm.getIsSelectedCanon(2)) && (creatGameForm.getIsSelected(1) || creatGameForm.getIsSelected(2)) &&
					creatGameForm.getString().size() >= 3)
				{
					if (creatGameForm.getIsSelected(1))
					{
						isSkinOne = true;
					}
					else if (creatGameForm.getIsSelected(2))
					{
						isSkinOne = false;
					}
					if (creatGameForm.getIsSelectedCanon(1))
					{
						turretType = enums::TurretType::MAIN_CANON_SIMPLE;
					}
					else if (creatGameForm.getIsSelectedCanon(2))
					{
						turretType = enums::TurretType::MAIN_CANON_TRIPLE;
					}
					if (hostedGamesList.size() == 0)
					{
						hostedGamesList.push_back(new HostedGame(creatGameForm.getString(), isSkinOne, turretType));
						hostedGamesList[hostedGamesList.size() - 1]->setPosition(gamesBox.getGlobalBounds().left + 25, gamesBox.getGlobalBounds().top + 25);
						player->setHostedGame(*hostedGamesList[hostedGamesList.size() - 1]);
						for (int i = 0; i < ConnectManager::Instance()->getConnectedPlayers().size(); i++)
						{
							if (player->getPlayerIP() == ConnectManager::Instance()->getConnectedPlayers()[i]->getPlayerIP())
							{
								ConnectManager::Instance()->getConnectedPlayers()[i] = player;
							}
						}
					}
					else
					{
						hostedGamesList.push_back(new HostedGame(creatGameForm.getString(), isSkinOne, turretType));
						hostedGamesList[hostedGamesList.size() - 1]->setPosition(hostedGamesList[hostedGamesList.size() - 2]->getPosition().x,
							hostedGamesList[hostedGamesList.size() - 2]->getGlobalBounds().top + hostedGamesList[hostedGamesList.size() - 2]->getGlobalBounds().height + 25);
						player->setHostedGame(*hostedGamesList[hostedGamesList.size() - 1]);
						for (int i = 0; i < ConnectManager::Instance()->getConnectedPlayers().size(); i++)
						{
							if (player->getPlayerIP() == ConnectManager::Instance()->getConnectedPlayers()[i]->getPlayerIP())
							{
								ConnectManager::Instance()->getConnectedPlayers()[i] = player;
							}
						}
					}
				}
				isCreatingGame = false;
				creatGameForm.resetForm();
			}
		}

		if ((creatGameForm.getIsSelectedCanon(1) || creatGameForm.getIsSelectedCanon(2)) && (creatGameForm.getIsSelected(1) || creatGameForm.getIsSelected(2)) &&
			creatGameForm.getString().size() >= 3)
		{
			creatGameForm.getButton(2).setIsAvaible(true);
		}
		else
		{
			creatGameForm.getButton(2).setIsAvaible(false);
		}
	}
	//// MENU REJOINDRE UNE PARTIE
	else if (!isCreatingGame && isJoiningGame)
	{

		//SURVOL SLOTS
		if (joinGameForm.isOverSlot(1, (sf::Vector2f)sf::Mouse::getPosition(GameManager::Instance()->getWindow())))
		{
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{
				selectedSlot = 1;
				joinGameForm.setSelectedSlot(selectedSlot);
				std::cout << "sur le slot 1 !!!" << std::endl;
			}
		}
		else if (joinGameForm.isOverSlot(2, (sf::Vector2f)sf::Mouse::getPosition(GameManager::Instance()->getWindow())))
		{
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{
				selectedSlot = 2;
				joinGameForm.setSelectedSlot(selectedSlot);
				std::cout << "sur le slot 2 !!!" << std::endl;
			}
		}
		else if (joinGameForm.isOverSlot(3, (sf::Vector2f)sf::Mouse::getPosition(GameManager::Instance()->getWindow())))
		{
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{
				selectedSlot = 3;
				joinGameForm.setSelectedSlot(selectedSlot);
				std::cout << "sur le slot 3 !!!" << std::endl;
			}
		}
		else if (joinGameForm.isOverSlot(4, (sf::Vector2f)sf::Mouse::getPosition(GameManager::Instance()->getWindow())))
		{
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{
				selectedSlot = 4;
				joinGameForm.setSelectedSlot(selectedSlot);
				std::cout << "sur le slot 4 !!!" << std::endl;
			}
		}

		//SURVOL CANON
		if (joinGameForm.isOverCanon(sf::Mouse::getPosition(GameManager::Instance()->getWindow()), 1))
		{
			joinGameForm.setOutlineColorCanon(sf::Color::Red, 1);
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{
				selectedCanon = 1;
				joinGameForm.setOutlineColorCanon(sf::Color::Transparent, 2);
			}
		}
		else if (joinGameForm.isOverCanon(sf::Mouse::getPosition(GameManager::Instance()->getWindow()), 2))
		{
			joinGameForm.setOutlineColorCanon(sf::Color::Red, 2);
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{
				selectedCanon = 2;
				joinGameForm.setOutlineColorCanon(sf::Color::Transparent, 1);
			}
		}
		else
		{
			if (selectedCanon == 1)
			{
				joinGameForm.setOutlineColorCanon(sf::Color::Green, 1);
				joinGameForm.setOutlineColorCanon(sf::Color::Transparent, 2);
			}
			else if (selectedCanon == 2)
			{
				joinGameForm.setOutlineColorCanon(sf::Color::Transparent, 1);
				joinGameForm.setOutlineColorCanon(sf::Color::Green, 2);
			}
			else
			{
				joinGameForm.setOutlineColorCanon(sf::Color::Transparent, 1);
				joinGameForm.setOutlineColorCanon(sf::Color::Transparent, 2);
			}
		}

		if (selectedCanon!=0 && selectedSlot!=0 )
		{
			joinGameForm.getButton(2).setIsAvaible(true);
		}
		else
		{
			joinGameForm.getButton(2).setIsAvaible(false);
		}

		//SURVOL BOUTONS
		if (joinGameForm.getButton(1).isOver(sf::Mouse::getPosition(GameManager::Instance()->getWindow())) && joinGameForm.getButton(1).getIsAvaible())
		{
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{
				isJoiningGame = false;
				selectedCanon = 0;
				selectedSlot = 0;
				joinGameForm.setSelectedSlot(0);
				//joinGameForm.resetForm();
			}
		}
		else if (joinGameForm.getButton(2).isOver(sf::Mouse::getPosition(GameManager::Instance()->getWindow())) && joinGameForm.getButton(2).getIsAvaible())
		{

		}

	}





	//if (ConnectManager::Instance()->receiveMessage(*player))
	//{
	//	Lobby::updateNamesList();
	//}
	//std::cout << "IN UPDATE" << std::endl;
	ConnectManager::Instance()->receiveMessage(*player);

	Lobby::updateNamesList();

}

void Lobby::display()
{
	GameManager::Instance()->getWindow().draw(freeNamesBox);
	GameManager::Instance()->getWindow().draw(inGameNamesBox);
	GameManager::Instance()->getWindow().draw(gamesBox);
	GameManager::Instance()->getWindow().draw(freeNamesTitle);
	GameManager::Instance()->getWindow().draw(inGameNamesTitle);
	GameManager::Instance()->getWindow().draw(gamesTitle);
	GameManager::Instance()->getWindow().draw(*createGameBtn);
	GameManager::Instance()->getWindow().draw(*joinGameBtn);

	for (int i = 0; i < freePlayersName.size(); i++)
	{
		GameManager::Instance()->getWindow().draw(freePlayersName[i]);
	}
	for (int i = 0; i < inGamePlayersName.size(); i++)
	{
		GameManager::Instance()->getWindow().draw(inGamePlayersName[i]);
	}

	for (int i = 0; i < hostedGamesList.size(); i++)
	{
		GameManager::Instance()->getWindow().draw(*hostedGamesList[i]);
	}


	if (isCreatingGame)
	{
		GameManager::Instance()->getWindow().draw(greyScreen);
		GameManager::Instance()->getWindow().draw(creatGameForm);
	}
	else if (isJoiningGame)
	{
		GameManager::Instance()->getWindow().draw(greyScreen);
		GameManager::Instance()->getWindow().draw(joinGameForm);
	}

}

void Lobby::updateNamesList()
{
	while (freePlayersName.size() != 0)
	{
		freePlayersName.erase(freePlayersName.begin());
	}
	while (inGamePlayersName.size() != 0)
	{
		inGamePlayersName.erase(inGamePlayersName.begin());
	}

	for (int i = 0; i < ConnectManager::Instance()->getConnectedPlayers().size(); i++)
	{
		if (!ConnectManager::Instance()->getConnectedPlayers()[i]->getIsInGame())
		{
			displayName.setString(ConnectManager::Instance()->getConnectedPlayers()[i]->getPlayerName());
			if (freePlayersName.size() == 0)
			{
				displayName.setPosition(freeNamesBox.getPosition().x + 10, freeNamesBox.getPosition().y + 10);
			}
			else
			{
				displayName.setPosition(freePlayersName[freePlayersName.size() - 1].getPosition().x, freePlayersName[freePlayersName.size() - 1].getGlobalBounds().top +
					freePlayersName[freePlayersName.size() - 1].getGlobalBounds().height);
			}
			freePlayersName.push_back(displayName);
		}
		else
		{
			displayName.setString(ConnectManager::Instance()->getConnectedPlayers()[i]->getPlayerName());
			if (inGamePlayersName.size() == 0)
			{
				displayName.setPosition(0, 0);
			}
			else
			{
				displayName.setPosition(inGamePlayersName[inGamePlayersName.size() - 1].getPosition().x, inGamePlayersName[inGamePlayersName.size() - 1].getGlobalBounds().top +
					inGamePlayersName[inGamePlayersName.size() - 1].getGlobalBounds().height);
			}
			inGamePlayersName.push_back(displayName);
		}
	}


}
