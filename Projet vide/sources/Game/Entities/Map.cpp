#include "Map.h"



Map::Map()
{
	std::cout << "Map::Map / BEGIN CONSTRUCTOR MAP" << std::endl;

	///GUILLAUME 17-04-2019

	//myBase = new Base({ 500 , 150 }, 1);
	//j'ajoute une base dans la liste de base
	listBase.push_back(new Base({ 500 , 150 }, 1));

	int nbEnnemy = 20;

	///GUILLAUME 17-04-2019
	//p_sprite = ToolsSFML::CreateSpriteFromPathPointer("resources/textures/Maps/map.png");

	//p_spPlan1 = ToolsSFML::CreateSpriteFromPathPointer("resources/textures/Maps/map1.jpg");
	//p_spPlan2 = ToolsSFML::CreateSpriteFromPathPointer("resources/textures/Maps/map2.jpg");
	//p_spPlan3 = ToolsSFML::CreateSpriteFromPathPointer("resources/textures/Maps/map3.jpg");

	p_MapPlan1 = new Map_Plan("resources/textures/Maps/map1.jpg");
	p_MapPlan2 = new Map_Plan("resources/textures/Maps/map2.jpg");

	p_MapPlan1->p_iIDPlan = 1;
	p_MapPlan2->p_iIDPlan = 2;

	p_MapPlan1->setPosition(0, 0);
	p_MapPlan2->setPosition(0, -p_MapPlan2->getGlobalBounds().height);

}


Map::~Map()
{
}

void Map::update()
{
}

void Map::update(sf::Vector2f pPosTank)
{
	for (int i = 0; i < listEnnemy.size(); i++)
	{
		listEnnemy[i]->update(sf::Vector2f(pPosTank));
	}
	//BASES
	this->ManageBases(pPosTank);
}

void Map::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	if (p_MapPlan1 != NULL)
	{
		target.draw(*p_MapPlan1, this->getTransform());
	}
	if (p_MapPlan2 != NULL)
	{
		target.draw(*p_MapPlan2, this->getTransform());
	}


	///GUILLAUME 17-04-2019
	for (int _IndiceBase = 0; _IndiceBase < listBase.size(); _IndiceBase++)
	{
		target.draw(*listBase[_IndiceBase]);
	}

	////////
	//target.draw(*myBase);
	for (int indiceEnnemies = 0; indiceEnnemies < listEnnemy.size(); indiceEnnemies++)
	{
		target.draw(*listEnnemy[indiceEnnemies]);
	}
}

sf::FloatRect Map::getGlobalBounds() const
{
	return sf::FloatRect();
}

void Map::ManageBases(sf::Vector2f _vPosTank)
{
	//if (myBase->SpawnEnnemy())
	for (int _IndiceBase = 0; _IndiceBase < listBase.size(); _IndiceBase++)
	{
		if (listBase[_IndiceBase]->SpawnEnnemy())
		{
			if (rand() % 5 == 0)
			{
				listEnnemy.push_back(new Soldat(enums::ennemies_Type::SOLDAT, listBase[_IndiceBase]->posSpawn));
			}
			else if (rand() % 5 == 1)
			{
				listEnnemy.push_back(new SoldatLourd(enums::ennemies_Type::SOLDAT_LOURD, listBase[_IndiceBase]->posSpawn));
			}
			else if (rand() % 5 == 2)
			{
				listEnnemy.push_back(new Sniper(enums::ennemies_Type::SNIPER, listBase[_IndiceBase]->posSpawn));
			}
			else if (rand() % 5 == 3)
			{
				listEnnemy.push_back(new Kamikaz(enums::ennemies_Type::KAMIKAZ, listBase[_IndiceBase]->posSpawn));
			}
		}
	}

	//DESTRUCTION DE LA BASE
	///debug destruction de base
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) == true && p_bSecureDeleteBase == false)
	{
		p_bSecureDeleteBase = true;

		//DELETE DE LA PREMIERE BASE DE LA LISTE
		if (listBase.size() > 0)
		{
			if (listBase[0] != NULL)
			{
				listBase.erase(listBase.begin());
			}
		}
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) == false && p_bSecureDeleteBase == true)
	{
		//var secure
		p_bSecureDeleteBase = false;
	}

	//SI MA LISTE DE BASE EST SUPERIEURE A 0
	///CHANGER LE "listBase[0] par l'iterateur beg pour que ce soit générique
	if (listBase.size() > 0)
	{
		//LE JOEUR NE PEUT PAS PASSER TANT QUE LA PREMIERE BASE DE LA LISTE EST ACTIVE
		if (listBase[0] != NULL)
		{
			if (_vPosTank.y < listBase[0]->getGlobalBounds().top + listBase[0]->getGlobalBounds().height)
			{
				_vPosTank.x = _vPosTank.x;
				_vPosTank.y = listBase[0]->getGlobalBounds().top + listBase[0]->getGlobalBounds().height;
			}
		}
	}
}

std::vector<Ennemy*> Map::getListEnnemy()
{
	return listEnnemy;
}


