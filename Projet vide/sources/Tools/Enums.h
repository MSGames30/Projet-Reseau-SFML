#pragma once
#ifndef ENUMS
#define ENUMS

namespace enums
{
	enum class SceneName
	{
		INTRO,
		MENU,
		GAME,
		CHARA_SELECT,
		LOBBY,
		LOGIN,
	};

	//Yanis 15-04
	enum class TurretType
	{
		INCENDIARY,
		SUBMACHINE,
		MAIN_CANON_SIMPLE,
		MAIN_CANON_TRIPLE,
		NONE
	};

	enum class TurretSlot
	{
		//Center
		SLOT_1,
		//TopLeft
		SLOT_2,
		//TopRight
		SLOT_3,
		//DownLeft
		SLOT_4,
		//DownRight
		SLOT_5
	};

	enum class BulletState
	{
		ON_COLLIDER,
		TO_DELETE,
		MOVING
	};

	enum class Collectibles
	{
		SHIELD,
		LIFE
	};
}


#endif // !ENUMS