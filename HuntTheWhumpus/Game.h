#pragma once
#include "Singleton.h"

class Game : public Singleton<Game>
{
public:
	void init();
	void (*game_loop)() = nullptr;

	class Map* map = nullptr;
	class Player* player = nullptr;
};

