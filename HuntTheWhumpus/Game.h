#pragma once

class Game
{
public:
	static Game& GetGame()
	{
		static Game instance;
		return instance;
	}

	class Map* map;
	class Player* player;

private:
	Game() {};
	~Game() {};
	Game(Game&) {};
	Game& operator=(const Game&) {};
};

