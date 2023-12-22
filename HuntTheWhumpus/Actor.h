#pragma once
#include "vector2D.h"

class Actor
{
	vector2D loc;
	vector2D locLastFrame = vector2D{ 0, 0 };
public:
	enum class Direction
	{
		up,
		down,
		left,
		right
	};
	
	virtual void draw();
	virtual void tick();
	virtual void move(Direction direction, int distant);

	void SetLocation(const vector2D loc) { this->loc = loc; };
	vector2D GetLocation() { return loc; };

private:
	bool canMove(Direction direction, int distant);
};

