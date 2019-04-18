#include "GameManager.h"

#include "../Scenes/Intro.h"
#include "../Scenes/Menu.h"
#include "../Scenes/Game.h"
#include "../Scenes/Lobby.h"
#include "../Scenes/Login.h"


GameManager::GameManager()
{
}

GameManager::GameManager(sf::RenderWindow & _window)
{
	window = &_window;
	loadScene(enums::SceneName::LOGIN);
}


GameManager::~GameManager()
{
	delete currentScene;
}

void GameManager::init(sf::RenderWindow & _window)
{
	window = &_window;
	loadScene(enums::SceneName::LOGIN);
	isP1Speeder = false;
}

void GameManager::loadScene(enums::SceneName _scene)
{
	switch (_scene)
	{
	case enums::SceneName::INTRO:
		// Create the menu and the game parts
		currentScene = new Intro();
		break;
	case enums::SceneName::MENU:
		currentScene = new Menu();
		break;
	case enums::SceneName::GAME:
		currentScene = new Game();
		break;
	case enums::SceneName::LOGIN:
		std::cout << "scene login" << std::endl;
		currentScene = new Login();
		break;
	case enums::SceneName::LOBBY:
		currentScene = new Lobby();
		break;
	default:
		std::cout << "Scene type invalid !" << std::endl;
		return;
		break;
	}
	currentSceneName = _scene;
}

void GameManager::loadScene(enums::SceneName _scene, std::string _playerName)
{
	switch (_scene)
	{
	case enums::SceneName::INTRO:
		// Create the menu and the game parts
		currentScene = new Intro();
		break;
	case enums::SceneName::MENU:
		currentScene = new Menu();
		break;
	case enums::SceneName::GAME:
		currentScene = new Game();
		break;
	case enums::SceneName::LOGIN:
		currentScene = new Login();
		break;
	case enums::SceneName::LOBBY:
		currentScene = new Lobby(_playerName);
		break;
	default:
		std::cout << "Scene type invalid !" << std::endl;
		return;
		break;
	}
	currentSceneName = _scene;
}

bool GameManager::update()
{
	currentScene->update();
	return false;
}

void GameManager::display()
{
	currentScene->display();
}

sf::RenderWindow & GameManager::getWindow()
{
	return *window;
}

void GameManager::setPlayer1Speeder(bool _state)
{
	isP1Speeder = _state;
}


