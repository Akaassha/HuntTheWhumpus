#include <iostream>
#include <Windows.h>
#include <conio.h>
#include "Game.h"
#include "GraphicEngine.h"
#include "Map.h"
#include "Player.h"

using namespace std;

void game_loop()
{
	Game& game = Game::GetGame();
	Player* player = game.player;
	char input = 0;
	while (1)
	{
		input = _getch();
		switch (input)
		{
		case 'w':
			player->move(Actor::Direction::up, 1);
			break;
		case 's':
			player->move(Actor::Direction::down, 1);
			break;
		case 'a':
			player->move(Actor::Direction::left, 1);
			break;
		case 'd':
			player->move(Actor::Direction::right, 1);
			break;
		}
		Sleep(100);

	}
}

int main()
{
	Game& game = Game::GetGame();
	
	Map* map = new Map("TestMap.txt");
	Player* player = new Player();

	game.map = map;
	game.player = player;
	game.game_loop = &game_loop;
	game.init();


}