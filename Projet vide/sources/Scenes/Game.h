#pragma once
#include "Scene.h"
#include "../Managers/GameManager.h"
#include "../Game/Character/Player.h"


class Game :
	public Scene
{
public:
	Game();
	~Game();
	virtual void update();
	virtual void display();
private:
	Player player;
};

