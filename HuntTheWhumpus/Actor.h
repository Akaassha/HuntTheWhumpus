#pragma once
#include "vector2D.h"

class Actor
{
	vector2D loc;
public:
	
	virtual void draw() = 0;

	void SetLocation(const vector2D loc) { this->loc = loc; };
	vector2D GetLocation() { return loc; };
};

