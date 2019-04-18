#include "Game.h"
#include "../Managers/ViewManager.h"



Game::Game()
{
	//this->tank->getPosition()
	//this->tank->getRotation()
	//this->tank->getLife()
	
	//Turret->bulletList[indiceBullet]
	myMap = new Map();
	player = new Player();
	this->tank = new Tank(true);

	//rejoins
	player->initTurret(enums::TurretType::MAIN_CANON_SIMPLE, enums::TurretSlot::SLOT_2);



	std::cout << "[Game]initTurret" << (int)player->getType() << " ; " << (int)player->getSlot() << std::endl;

	tank->initTurret(player->getType(), player->getSlot());
	player->setTurret(tank->getTurret(player->getSlot()));
}

Game::~Game()
{

}

void Game::update()
{
	if (this->tank != nullptr)
		this->tank->update();
	if (this->player != nullptr)
		this->player->update();
	if (this->myMap != nullptr && this->tank != nullptr)
		this->myMap->update(this->tank->getPosition());

	//Gestion de la vue du gameplay
	ViewManager::Instance()->updateViewMain(tank, myMap);
}

void Game::display()
{
	//SET VIEW MAIN (GAMEPLAY)
	GameManager::Instance()->getWindow().setView(ViewManager::Instance()->getViewMain());

	if (this->myMap != nullptr)
		GameManager::Instance()->getWindow().draw(*this->myMap);
	if (this->tank != nullptr)
		GameManager::Instance()->getWindow().draw(*this->tank);

	//debug view
	if (this->tank->p_rectShape != NULL)
	{
		GameManager::Instance()->getWindow().draw(*this->tank->p_rectShape);
	}

	//SET VIEW HUD
	GameManager::Instance()->getWindow().setView(ViewManager::Instance()->getViewHUD());

	GameManager::Instance()->getWindow().draw(this->tank->getRectLife());
	GameManager::Instance()->getWindow().draw(this->tank->getRectShield());
	if (this->tank->getHUD() != nullptr)
		GameManager::Instance()->getWindow().draw(*this->tank->getHUD());


	//HUD des tourelles
	for (int indiceTurret = 0; indiceTurret < this->tank->getTurretList().size(); indiceTurret++)
	{
		GameManager::Instance()->getWindow().draw(*this->tank->getTurretList()[indiceTurret]->getHUD());
	}


}




