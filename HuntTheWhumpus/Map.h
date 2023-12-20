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

	void draw();
	void redraw();
	inline const Tile& getTile(int x, int y);

	void AddActor(class Actor* actor) { Actors.push_back(actor); };

	vector2D GetPlayerSpawnLoc() { return PlayerSpawnLoc; };
private:
	std::vector<std::string> read_map(std::string filename);
};

