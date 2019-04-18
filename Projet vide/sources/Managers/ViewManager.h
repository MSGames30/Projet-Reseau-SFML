#pragma once
#include "../Templates/Singleton.h"
#include "../SCENES/Game.h"
#include <iostream>

class ViewManager :
	public Singleton<ViewManager>
{
public:

	ViewManager();
	~ViewManager();
	void InitViewManager(sf::RenderWindow* _window);

	//Update de la vue principale (vue du jeu)
	void updateViewMain(DrawableObject* _EntityToRefer, Map* _Map);

	//void updateParallaxViews(Plan_Parallax* _parallaxToUpdate, sf::Sprite* PlanGame, sf::View* _viewToRefer, float _MoveSpeed, Player* _player);

	sf::View getViewMain();
	sf::View getViewHUD();

	/*TEST PARALLAX*/
	//sf::View p_viewFirstPlan;
	//sf::View p_viewSecondPlan;
	//sf::View p_viewThirdPlan;
	//sf::View p_viewThourthPlan;
	//sf::View p_viewFifthPlan;
	//sf::View p_viewSixPlan;
	//sf::View p_viewSevenPlan;
private:
	//MapToRefer for updating views
	//Map_Of_Level *CurrentMapOfLevel;

	//int iCurrentMap = 0;
	sf::View p_viewMain; // Vue du Gameplay (principal)
	sf::View p_ViewHUD; // vue de l'HUD
};

