#pragma once
#include "Scene.h"
#include "../Managers/GameManager.h"
#include "../Game/Character/Tank/Tank.h"
#include "../Game/Character/Player.h"
#include "../Game/Entities/Map.h"

class Game :
	public Scene
{
public:
	Game();
	~Game();
	virtual void update();
	virtual void display();

private:
	Tank *tank;
	Player *player;
	Map *myMap;
	
};

