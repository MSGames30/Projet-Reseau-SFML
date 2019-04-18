#pragma once
#include <SFML\Graphics.hpp>


//class GameManager;


class Scene
{
public:
	Scene();
	~Scene();
	virtual void update() = 0;
	virtual void display() = 0;
protected:
};

