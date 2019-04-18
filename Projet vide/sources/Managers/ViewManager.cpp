#include "ViewManager.h"

ViewManager::ViewManager()
{
}

ViewManager::~ViewManager()
{
}

void ViewManager::InitViewManager(sf::RenderWindow* _window)
{
	std::cout << "ViewManager::InitViewManager / BEGINNING" << std::endl;

	//INITIALISATION DES VUES
	// INITIALISATION DES VIEWS

	#pragma region VIEW

	//MainView
	p_viewMain.reset(sf::FloatRect(0, 0, _window->getSize().x, _window->getSize().y));
	p_viewMain.setViewport(sf::FloatRect(0.f, 0.f, 1.f, 1.f));
	p_viewMain.zoom(1.5);

	//ParallaxView
	//p_viewParallax.reset(sf::FloatRect(0, 0, _window->getSize().x, _window->getSize().y));
	//p_viewParallax.setViewport(FloatRect(0.f, 0.f, 1.f, 1.f));

	p_ViewHUD.reset(sf::FloatRect(0, 0, _window->getSize().x, _window->getSize().y));
	p_ViewHUD.setViewport(sf::FloatRect(0.f, 0.f, 1.f, 1.f));
	p_ViewHUD.zoom(1);

	//VUE DES PLANS DE PARALLAX
	//p_viewFirstPlan.reset(sf::FloatRect(0, 0, _window->getSize().x, _window->getSize().y));
	//p_viewSecondPlan.reset(sf::FloatRect(0, 0, _window->getSize().x, _window->getSize().y));
	//p_viewThirdPlan.reset(sf::FloatRect(0, 0, _window->getSize().x, _window->getSize().y));
	//p_viewThourthPlan.reset(sf::FloatRect(0, 0, _window->getSize().x, _window->getSize().y));
	//p_viewFifthPlan.reset(sf::FloatRect(0, 0, _window->getSize().x, _window->getSize().y));
	//p_viewSixPlan.reset(sf::FloatRect(0, 0, _window->getSize().x, _window->getSize().y));
	//p_viewSevenPlan.reset(sf::FloatRect(0, 0, _window->getSize().x, _window->getSize().y));

	#pragma endregion VIEW

	std::cout << "ViewManager::InitViewManager / ENDING" << std::endl;
}

void ViewManager::updateViewMain(DrawableObject* _EntityToRefer, Map* _Map)
{
	#pragma region SPRITE
	//JE FAIS LES CALCULS EN FONCTION DE LA MAP SUR LAQUELLE SE TROUVE LE TANK
	//if (_Map->p_spPlan1->getGlobalBounds().contains(_EntityToRefer->getPosition()))
	//{
	//	//DEBUG
	//	_Map->p_spPlan1->setColor(sf::Color::Blue);
	//	_Map->p_spPlan2->setColor(sf::Color::White);

	//	//iCurrentMap = 1;
	//	_Map->p_spCurrentPlan = _Map->p_spPlan1;
	//	_Map->p_spOtherPlan = _Map->p_spPlan2;

	//}
	//else if (_Map->p_spPlan2->getGlobalBounds().contains(_EntityToRefer->getPosition()))
	//{
	//	//DEBUG
	//	_Map->p_spPlan2->setColor(sf::Color::Blue);
	//	_Map->p_spPlan1->setColor(sf::Color::White);

	//	//iCurrentMap = 2;
	//	_Map->p_spCurrentPlan = _Map->p_spPlan2;
	//	_Map->p_spOtherPlan = _Map->p_spPlan1;

	//}

	

	////CHANGEMENT DE MAP
	/////(REMPLACER LA DEFINE PAR LA VRAIE SIZE DE LA VIEW)
	//if (_EntityToRefer->getPosition().y < _Map->p_spCurrentPlan->getGlobalBounds().top + _Map->p_spCurrentPlan->getGlobalBounds().height - (WINDOW_SIZE.y / 2))
	//{
	//	//Si l'autre map se trouve en dessous je la remonte
	//	if (_Map->p_spOtherPlan->getPosition().y > _Map->p_spCurrentPlan->getPosition().y)
	//	{
	//		_Map->p_spOtherPlan->setPosition(sf::Vector2f(
	//			_Map->p_spOtherPlan->getPosition().x,
	//			_Map->p_spCurrentPlan->getPosition().y - _Map->p_spOtherPlan->getGlobalBounds().height));
	//	}
	//}

	////1) JE CENTRE LA CAMERA SUR LE JOUEUR
	//if (_EntityToRefer != NULL)
	//{
	//	//2) je check les cas ou caméra arrive sur les cotes de l'écran

	//	///GESTION EN X
	//	//centré sur le player
	//	if (_EntityToRefer->getPosition().x > _Map->p_spCurrentPlan->getGlobalBounds().left + p_viewMain.getSize().x / 2 
	//		&& _EntityToRefer->getPosition().x < _Map->p_spCurrentPlan->getGlobalBounds().left + _Map->p_spCurrentPlan->getGlobalBounds().width - (p_viewMain.getSize().x / 2))
	//	{
	//		p_viewMain.setCenter(_EntityToRefer->getPosition());
	//	}
	//	//coté gauche
	//	else if (_EntityToRefer->getPosition().x <= _Map->p_spCurrentPlan->getGlobalBounds().left + (p_viewMain.getSize().x / 2))
	//	{
	//		//je cale la vue en x a la position left du plan actuel + la taille de la vue / 2
	//		p_viewMain.setCenter(sf::Vector2f(
	//			_Map->p_spCurrentPlan->getGlobalBounds().left + (p_viewMain.getSize().x / 2),
	//			p_viewMain.getCenter().y));
	//	}
	//	//coté droit
	//	else if (_EntityToRefer->getPosition().x >= _Map->p_spCurrentPlan->getGlobalBounds().left + _Map->p_spCurrentPlan->getGlobalBounds().width - (p_viewMain.getSize().x / 2))
	//	{
	//		//je cale la vue en x a la position left du plan actuel + la largeur du plan actuel - la taille de la vue / 2
	//		p_viewMain.setCenter(sf::Vector2f(
	//			_Map->p_spCurrentPlan->getGlobalBounds().left + _Map->p_spCurrentPlan->getGlobalBounds().width - (p_viewMain.getSize().x / 2),
	//			p_viewMain.getCenter().y));
	//	}

	//	///GESTION EN Y
	//	p_viewMain.setCenter(sf::Vector2f(
	//		p_viewMain.getCenter().x,
	//		_EntityToRefer->getPosition().y));

	//}

	#pragma endregion SPRITE


	///AVEC MAP PLAN
	#pragma region MAP PLAN

	//DEBUG
	if (_Map->p_MapPlan1->getGlobalBounds().contains(_EntityToRefer->getPosition()))
	{
		//DEBUG
		_Map->p_MapPlan1->p_sprite->setColor(sf::Color::Blue);
		_Map->p_MapPlan2->p_sprite->setColor(sf::Color::White);

		//iCurrentMap = 1;
		_Map->p_MapCurrent = _Map->p_MapPlan1;
		_Map->p_MapOther = _Map->p_MapPlan2;

	}
	else if (_Map->p_MapPlan2->getGlobalBounds().contains(_EntityToRefer->getPosition()))
	{
		//DEBUG
		_Map->p_MapPlan2->p_sprite->setColor(sf::Color::Blue);
		_Map->p_MapPlan1->p_sprite->setColor(sf::Color::White);

		//iCurrentMap = 2;
		_Map->p_MapCurrent = _Map->p_MapPlan2;
		_Map->p_MapOther = _Map->p_MapPlan1;

	}

	#pragma region GESTION MAP
	//CHANGEMENT DE MAP
	///(REMPLACER LE DEFINE PAR LA VRAIE SIZE DE LA VIEW)
	if (_EntityToRefer->getPosition().y < _Map->p_MapCurrent->getGlobalBounds().top + _Map->p_MapCurrent->getGlobalBounds().height - (WINDOW_SIZE.y / 2))
	{
		//Si l'autre map se trouve en dessous je la remonte
		if (_Map->p_MapOther->getPosition().y > _Map->p_MapCurrent->getPosition().y)
		{
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
			{
				std::cout << "DEBUG" << std::endl;
			}

			_Map->p_MapOther->setPosition(sf::Vector2f(
				_Map->p_MapOther->getPosition().x,
				_Map->p_MapCurrent->getPosition().y - _Map->p_MapOther->getGlobalBounds().height));
			
		}

	}


	#pragma endregion GESTION MAP

	//std::cout << "ID PLAN_CURRENT : " << _Map->p_MapCurrent->p_iIDPlan << "ID PLAN_OTHER : " << _Map->p_MapOther->p_iIDPlan << std::endl;

	#pragma region GESTION VIEW
	//1) JE CENTRE LA CAMERA SUR LE JOUEUR
	if (_EntityToRefer != NULL)
	{
		//2) je check les cas ou la caméra arrive sur les cotés de la map

		///GESTION EN X
		//centré sur le player
		if (_EntityToRefer->getPosition().x > _Map->p_MapCurrent->getGlobalBounds().left + p_viewMain.getSize().x / 2
			&& _EntityToRefer->getPosition().x < _Map->p_MapCurrent->getGlobalBounds().left + _Map->p_MapCurrent->getGlobalBounds().width - (p_viewMain.getSize().x / 2))
		{
			p_viewMain.setCenter(sf::Vector2f(_EntityToRefer->getPosition().x, p_viewMain.getCenter().y) );
		}
		//coté gauche
		else if (_EntityToRefer->getPosition().x <= _Map->p_MapCurrent->getGlobalBounds().left + (p_viewMain.getSize().x / 2))
		{
			//je cale la vue en x a la position left du plan actuel + la taille de la vue / 2
			p_viewMain.setCenter(sf::Vector2f(
				_Map->p_MapCurrent->getGlobalBounds().left + (p_viewMain.getSize().x / 2),
				p_viewMain.getCenter().y));
		}
		//coté droit
		else if (_EntityToRefer->getPosition().x >= _Map->p_MapCurrent->getGlobalBounds().left + _Map->p_MapCurrent->getGlobalBounds().width - (p_viewMain.getSize().x / 2))
		{
			//je cale la vue en x a la position left du plan actuel + la largeur du plan actuel - la taille de la vue / 2
			p_viewMain.setCenter(sf::Vector2f(
				_Map->p_MapCurrent->getGlobalBounds().left + _Map->p_MapCurrent->getGlobalBounds().width - (p_viewMain.getSize().x / 2),
				p_viewMain.getCenter().y));
		}

		///GESTION EN Y
		//p_viewMain.setCenter(sf::Vector2f(
		//	p_viewMain.getCenter().x,
		//	_EntityToRefer->getPosition().y));

		
		//centré sur le player
		if (_EntityToRefer->getPosition().y > _Map->p_MapCurrent->getGlobalBounds().top + p_viewMain.getSize().y / 2
			&& _EntityToRefer->getPosition().y < _Map->p_MapCurrent->getGlobalBounds().top + _Map->p_MapCurrent->getGlobalBounds().height - (p_viewMain.getSize().y / 2))
		{
			p_viewMain.setCenter(sf::Vector2f(p_viewMain.getCenter().x, _EntityToRefer->getPosition().y));
		}
		//HAUT DE LA MAP
		else if (_EntityToRefer->getPosition().y <= _Map->p_MapCurrent->getGlobalBounds().top + (p_viewMain.getSize().y / 2))
		{
			//je cale la vue en x a la position left du plan actuel + la taille de la vue / 2
			p_viewMain.setCenter(sf::Vector2f(
				p_viewMain.getCenter().x,
				_Map->p_MapCurrent->getGlobalBounds().top + (p_viewMain.getSize().y / 2)));
		}
		////BAS DE LA MAP
		else if (_EntityToRefer->getPosition().y >= _Map->p_MapCurrent->getGlobalBounds().top + _Map->p_MapCurrent->getGlobalBounds().height - (p_viewMain.getSize().y / 2))
		{
			//je cale la vue en y a la position top du plan actuel + la hauteur du plan actuel - la taille de la vue en y/ 2
			p_viewMain.setCenter(sf::Vector2f(
				p_viewMain.getCenter().x,
				_Map->p_MapCurrent->getGlobalBounds().top + _Map->p_MapCurrent->getGlobalBounds().height - (p_viewMain.getSize().y / 2)));
		}

	}
	#pragma endregion GESTION VIEW

	///ARRET DU PLAYER
	//SI L'AUTRE MAP N'EST PLUS EN DESSOUS DE LA MAP ACTUELLE LE JOUEUR NE PEUT PAS DESENDRE
	if (_Map->p_MapOther->getPosition().y <= _Map->p_MapCurrent->getPosition().y)
	{
		//Positionnement du player
		if (_EntityToRefer->getPosition().y + _EntityToRefer->getGlobalBounds().height / 2 >= _Map->p_MapCurrent->getGlobalBounds().top + _Map->p_MapCurrent->getGlobalBounds().height)
		{
			_EntityToRefer->setPosition(sf::Vector2f(
				_EntityToRefer->getPosition().x,
				_Map->p_MapCurrent->getGlobalBounds().top + _Map->p_MapCurrent->getGlobalBounds().height - _EntityToRefer->getGlobalBounds().height / 2));
		}
	}

	#pragma endregion MAP PLAN

}

//void ViewManager::updateParallaxViews(Plan_Parallax* _parallaxToUpdate, sf::Sprite* PlanGame, sf::View* _viewToRefer, float _MoveSpeed, Player* _player)
//{
//	//J'utilise la fonction pour boucler un parralax
//	if (_player->getRightIsPressed())
//	{
//		ToolsSFML::UpdateLoopParralaxByView(_parallaxToUpdate->p_sprite, PlanGame, _viewToRefer, _MoveSpeed, _parallaxToUpdate->p_vPosCurrent, _parallaxToUpdate->p_vPosNext, _player->getPosition());
//	}
//	else if (_player->getLeftIsPressed())
//	{
//		ToolsSFML::UpdateLoopParralaxByView(_parallaxToUpdate->p_sprite, PlanGame, _viewToRefer, -_MoveSpeed, _parallaxToUpdate->p_vPosCurrent, _parallaxToUpdate->p_vPosNext, _player->getPosition());
//	}
//	//std::cout << "MANAGER : CURRENT_X : " << _parallaxToUpdate->p_vPosCurrent.x << " CURRENT_Y : " << _parallaxToUpdate->p_vPosCurrent.y;
//	//std::cout << " NEXT_X : " << _parallaxToUpdate->p_vPosNext.x << " NEXT_Y : " << _parallaxToUpdate->p_vPosNext.y << std::endl;
//}

sf::View ViewManager::getViewMain()
{
	return p_viewMain;
}

sf::View ViewManager::getViewHUD()
{
	return p_ViewHUD;
}
