#pragma once
#include "Scene.h"
#include "../Game/Entities/Button.h"
#include "../Game/Entities/CreateGameForm.h"

#define TEXTBOX_POS_Y 750.0f

class Login :
	public Scene
{
public:
	Login();
	~Login();
	virtual void update();
	virtual void display();
private:
	sf::Event pollEvent;

	sf::Font* font;
	sf::Text logoText;
	sf::Text enterName;
	sf::Text playerName;
	std::string nameString;

	sf::RectangleShape textBox;

	Button* logInButton;
	bool isMousePressed;

};

