#pragma once


class GraphicEngine
{
	class Map* map = nullptr;

public:
	static GraphicEngine& GetEngine()
	{
		static GraphicEngine Instance;
		return Instance;
	}

	void (*graphic_loop)();
	void SetMap(class Map* map);
	void run();
	void redrawTile(class vector2D);

private:
	GraphicEngine();
	~GraphicEngine() {};
	GraphicEngine(GraphicEngine&) = delete;
	GraphicEngine& operator=(const GraphicEngine&) = delete;

};
