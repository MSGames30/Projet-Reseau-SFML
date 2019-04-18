#pragma once
#include "../Templates/Singleton.h"
#include <SFML\Graphics.hpp>
#include <string>

class PollEventManager :
	public Singleton <PollEventManager>
{
public:
	PollEventManager();
	~PollEventManager();
	void init(sf::RenderWindow& _window);
	void update();
	void setStringMaxSiZe(int _value);
	void resetString();
	std::string getString();
private:
	sf::RenderWindow* window;
	sf::Event pollEvent;
	std::string nameString;

	int maxStringMaxSize;

};

