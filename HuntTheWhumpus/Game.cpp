#include "Game.h"
#include "GraphicEngine.h"
#include "Map.h"
#include <thread>
#include <iostream>

void Game::init()
{
	GraphicEngine& graphicEngine = GraphicEngine::GetInstance();
	graphicEngine.SetMap(map);
	map->init();

	std::thread Graphic(*graphicEngine.graphic_loop);
	std::thread Gameplay(*game_loop);

	Graphic.join();
	Gameplay.join();
}