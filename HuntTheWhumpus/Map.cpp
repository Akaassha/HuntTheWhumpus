#include "Map.h"
#include "Tile.h"
#include "Actor.h"
#include <fstream>
#include <iostream>
#include <Windows.h>
#include "Game.h"
#include "Player.h"


Map::Map(std::string filename)
{
	auto map_data = read_map(filename);

	Tiles = new Tile* [width * height];

	for (int y = 0; y < height; ++y)
	{
		Tiles[y] = new Tile[width];
		for (int x = 0; x < width; ++x)
		{
			switch (map_data[y][x])
			{
			case '%':
				PlayerSpawnLoc.set(x, y);

			default:
				Tiles[y][x] = Tile(map_data[y][x]);
				break;
			}
		}
	}
}

void Map::draw()
{
	system("cls");

	for (int y = 0; y != height; y++)
	{
		for (int x = 0; x != width; x++)
		{
			std::cout << Tiles[y][x];
		}

		std::cout << std::endl;
	}
};


const Tile& Map::getTile(int x, int y)
{
	return Tiles[y][x];
}

const Tile& Map::getTile(vector2D vec)
{
	return getTile(vec.x, vec.y);
}

std::vector<std::string> Map::read_map(std::string filename)
{
	std::ifstream file(filename);

	if (!file.good()) {
		throw std::runtime_error("Cannot open file."); 
	};

	std::vector<std::string> map_data;
	std::string line;
	file >> line;
	width = stoi(line);
	file >> line;
	height = stoi(line);

	while(file >> line)
	{
		if (line.size() <= 0)
		{
			throw std::runtime_error("ile structure is not correct.");
			file.close();
		}
		map_data.push_back(line);
	}

	file.close();
	return map_data;
}

void Map::redraw()
{
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);

	for (auto actor : Actors)
	{
		COORD coords;
		coords.X = actor->GetLocation().x*2;
		coords.Y = actor->GetLocation().y;

		SetConsoleCursorPosition(hOut, coords);
		SetConsoleTextAttribute(hOut, 240);
		actor->draw();
		//std::cout << actor->disp;
	}

	SetConsoleTextAttribute(hOut, 0);

}

void Map::init()
{
	Game& game = Game::GetGame();
	Player* player = game.player;
	player->SetLocation(PlayerSpawnLoc);
	Actors.push_back(player);
}