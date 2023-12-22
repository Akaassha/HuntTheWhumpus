#include "Arrow.h"
#include "GraphicEngine.h"
#include "Game.h"
#include "Map.h"
#include <iostream> 
#include <Windows.h>

void Arrow::draw()
{
	HANDLE console_color;
	console_color = GetStdHandle(STD_OUTPUT_HANDLE);
	system("Color 0");
	SetConsoleTextAttribute(console_color, 240);

	if (direct == Direction::left or direct == Direction::right)
		std::cout << '-' << '-';
	else
		std::cout << '|';
}

void Arrow::tick()
{
	Actor::tick();
	vector2D vec;
	if(canMove(direct, 1))
	{
		locLastFrame = GetLocation();
		switch (direct)
		{
		case Actor::Direction::up:
			vec = vector2D{ 0,-1 };
			break;
		case Actor::Direction::down:
			vec = vector2D{ 0,1 };
			break;
		case Actor::Direction::left:
			vec = vector2D{ -1,0 };
			break;
		case Actor::Direction::right:
			vec = vector2D{1,0 };
			break;
		}
		SetLocation(GetLocation() + vec);
	}
	else
	{
		delete this;
	}
	
}

