#pragma once
#include "Actor.h"

class Player : public Actor
{

public:
	Player() { apperance.first = '('; apperance.second = ')'; };
	void shot();
};

