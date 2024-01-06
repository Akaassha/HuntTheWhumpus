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
	Game& game = Game::GetInstance();
	Player* player = game.player;
	char input = 0;
	while (1)
	{
		FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));
		input = _getch();
		switch (input)
		{
		case 'W':
		case 'w':
			player->move(Actor::Direction::up, 1);
			break;
		case 'S':
		case 's':
			player->move(Actor::Direction::down, 1);
			break;
		case 'a':
		case 'A':
			player->move(Actor::Direction::left, 1);
			break;
		case 'D':
		case 'd':
			player->move(Actor::Direction::right, 1);
			break;
		case ' ':
			player->shot();
		}
		Sleep(100);

	}
}

int main()
{
	Game::CreateInstance();
	GraphicEngine::CreateInstance();
	Game& game = Game::GetInstance();

	Map* map = new Map("TestMap.txt");
	Player* player = new Player();

	game.map = map;
	game.player = player;
	game.game_loop = &game_loop;
	game.init();

}