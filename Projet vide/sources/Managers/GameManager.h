#pragma once
#include "../Scenes/Scene.h"
#include "../Tools/Enums.h"
#include "../Templates/Singleton.h"

#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <string>

class GameManager : public Singleton <GameManager>
{
public:
	GameManager();
	GameManager(sf::RenderWindow &_window);
	~GameManager();
	void init(sf::RenderWindow &_window);
	void loadScene(enums::SceneName _scene);
	void loadScene(enums::SceneName _scene,std::string _playerName);
	bool update();
	void display();
	sf::RenderWindow& getWindow();
	void setPlayer1Speeder(bool _state);
private:
	Scene *currentScene;
	enums::SceneName currentSceneName;
	sf::RenderWindow * window;
	bool isP1Speeder;
};

