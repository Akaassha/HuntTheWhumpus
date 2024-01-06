#pragma once
#include "vector2D.h"
#include <utility>

class Actor
{
	vector2D loc;
	
public:
	virtual ~Actor();
	enum class Direction
	{
		up,
		down,
		left,
		right
	};
	
	std::pair<char, char> apperance;

	virtual void draw();
	virtual void tick();
	virtual void move(Direction direction, int distant);

	void SetLocation(const vector2D loc) { this->loc = loc; };
	vector2D GetLocation() { return loc; };

protected:
	bool canMove(Direction direction, int distant);
	vector2D locLastFrame = vector2D{ 0, 0 };
};

