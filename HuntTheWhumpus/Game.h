#pragma once

class Game
{
public:
	static Game& GetGame()
	{
		static Game instance;
		return instance;
	}

	void init();
	void (*game_loop)() = nullptr;

	class Map* map = nullptr;
	class Player* player = nullptr;

private:
	Game() {};
	~Game() {};
	Game(Game&) {};
	Game& operator=(const Game&) {};
};

