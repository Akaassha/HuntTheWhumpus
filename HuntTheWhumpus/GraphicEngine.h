#pragma once
#include "Singleton.h"

class GraphicEngine : public Singleton<GraphicEngine>
{
	class Map* map = nullptr;

public:
	void (*graphic_loop)();
	void SetMap(class Map* map);
	void run();
	void redrawTile(class vector2D);

	GraphicEngine();
};