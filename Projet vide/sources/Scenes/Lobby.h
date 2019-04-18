#pragma once
#include "Scene.h"
#include "../Game/Character/Player.h"
#include "../Game/Entities/Button.h"
#include "../Game/Entities/CreateGameForm.h"
#include "../Game/Entities/JoinGameForm.h"
#include "../Game/Entities/HostedGame.h"

#include <vector>


class Lobby :
	public Scene
{
public:
	Lobby();
	Lobby(std::string _playerName);
	~Lobby();
	virtual void update();
	virtual void display();
	void updateNamesList();
private:
	Player * player;

	sf::Font* font;
	sf::Text displayName;

	std::vector<sf::Text> freePlayersName;
	std::vector<sf::Text> inGamePlayersName;

	sf::RectangleShape freeNamesBox;
	sf::RectangleShape inGameNamesBox;
	sf::RectangleShape gamesBox;

	sf::Text freeNamesTitle;
	sf::Text inGameNamesTitle;
	sf::Text gamesTitle;

	sf::Clock sendTimer;

	Button* createGameBtn;
	Button* joinGameBtn;

	CreateGameForm creatGameForm;
	JoinGameForm joinGameForm;

	sf::RectangleShape greyScreen;
	bool isCreatingGame;
	bool isJoiningGame;


	bool isMousePressed;

	int selectedSlot;
	int selectedCanon;

	std::vector<HostedGame*> hostedGamesList;

	bool isSkinOne;
	enums::TurretType turretType;
};

