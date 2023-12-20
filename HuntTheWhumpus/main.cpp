#include <iostream>
#include <Windows.h>
#include <thread>
#include "Game.h"
#include "Map.h"
#include "Player.h"

using namespace std;

int main()
{
	Game& game = Game::GetGame();
	Map* map = new Map("TestMap.txt");
	Player* player = new Player();

	game.map = map;
	game.player = player;

	player->SetLocation(map->GetPlayerSpawnLoc());
	map->AddActor(player);

	map->draw();
	map->redraw();

	//static const HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	//COORD coords;
	//coords.X = 2;
	//coords.Y = 2;

	//while (1)
	//{
	//	SetConsoleCursorPosition(hOut, coords);
	//	SetConsoleTextAttribute(hOut, 666);
	//	cout << '<' << '>';
	//	coords.Y = 1;
	//	SetConsoleTextAttribute(hOut, 0);
	//	Sleep(100);

	//	SetConsoleCursorPosition(hOut, coords);
	//	SetConsoleTextAttribute(hOut, 666);
	//	cout << '-' << '-';
	//	coords.Y = 1;
	//	SetConsoleTextAttribute(hOut, 0);
	//	Sleep(100);
	//}

	while (1);
}