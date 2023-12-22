#pragma once
#include "Actor.h"

class Arrow : public Actor
{
	Direction direct;

public:
	Arrow(Direction direct) : direct{ direct } {};

protected:
	virtual void draw() override;
	virtual void tick() override;
};

