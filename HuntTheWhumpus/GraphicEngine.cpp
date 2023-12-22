#include "GraphicEngine.h"
#include "Map.h"
#include "Tile.h"
#include "Actor.h"
#include <Windows.h>
#include <iostream>
#include <thread>

void graphic_loop()
{
	GraphicEngine& graphicEngine = GraphicEngine::GetEngine();
	graphicEngine.run();
}

GraphicEngine::GraphicEngine()
{
	graphic_loop = &::graphic_loop;
}

void GraphicEngine::SetMap(class Map* map)
{
	this->map = map;
}

void GraphicEngine::run()
{
	HANDLE console;
	console = GetStdHandle(STD_OUTPUT_HANDLE);

	map->draw();
	COORD coords;

	while (true)
	{
		
		auto actors = map->GetActors();
		for (auto actor : actors)
		{

			coords.X = actor->GetLocation().x*2;
			coords.Y = actor->GetLocation().y;
			SetConsoleCursorPosition(console, coords);
			actor->tick();
			coords.Y = -1;
			SetConsoleCursorPosition(console, coords);
			Sleep(50);
		}
	}
}

void GraphicEngine::redrawTile(vector2D loc)
{
	HANDLE console;
	console = GetStdHandle(STD_OUTPUT_HANDLE);

	COORD coords;
	coords.X = loc.x * 2;
	coords.Y = loc.y;
	SetConsoleCursorPosition(console, coords);
	std::cout << map->getTile(loc);
}
