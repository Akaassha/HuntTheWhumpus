#include "Tile.h"
#include <windows.h>

#define WHITE 240
#define GREY 117

Tile::Tile(char c)
{
	switch (c)
	{
	case '_':
		type = Tile::Type::floor;
		break;
	case '#':
		type = Tile::Type::wall;
		break;

	default:
		type = Tile::Type::floor;
		break;
	}
}

std::ostream& operator<<(std::ostream& os, const Tile tile)
{
	HANDLE console_color;
	console_color = GetStdHandle(STD_OUTPUT_HANDLE);
	system("Color 0");
	switch (tile.type)
	{
	case Tile::Type::wall:
		SetConsoleTextAttribute(console_color, GREY);
		os << ' ' << ' ';
		break;
		//case Tile::Type::player:
		//	os << '%';
		//	break;
	case Tile::Type::floor:
		SetConsoleTextAttribute(console_color, WHITE);
		os << ' ' << ' ';
		break;
		//case Tile::Type::barrel:
		//	os << 'O';
		//	break;
		//case Tile::Type::goal:
		//	os << 'x';
		break;
	}
	SetConsoleTextAttribute(console_color, 0);

	return os;
}