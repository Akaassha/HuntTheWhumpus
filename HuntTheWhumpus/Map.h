#pragma once

#include <string>
#include <vector>
#include "vector2D.h">

class Map
{
	class Tile** Tiles;
	std::vector<class Actor*> Actors;
	int width;
	int height;

	vector2D PlayerSpawnLoc;

public:
	Map(std::string filename);

	void init();
	void draw();
	void redraw();
	const Tile& getTile(int x, int y);
	const Tile& getTile(vector2D loc);

	void AddActor(class Actor* actor) { Actors.push_back(actor); };
	void RemoveActor(class Actor* actor);
	std::vector<class Actor*> GetActors() { return Actors; };

	vector2D GetPlayerSpawnLoc() { return PlayerSpawnLoc; };
private:
	std::vector<std::string> read_map(std::string filename);
};

