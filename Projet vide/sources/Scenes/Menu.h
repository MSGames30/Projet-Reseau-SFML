#pragma once
#include "Scene.h"
#include "../Managers/GameManager.h"

class Menu :
	public Scene
{
public:
	Menu();
	~Menu();
	virtual void update();
	virtual void display();

private:
	

};

