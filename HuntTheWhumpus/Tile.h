#pragma once
#include <iostream>

class Tile
{

public:
	enum class Type
	{
		wall,
		floor,
		//actor,
	};

	Type type;

	Tile() { type = Tile::Type::wall; };
	Tile(Tile::Type type) : type{ type } {};
	Tile(char c);

	friend std::ostream& operator<<(std::ostream& os, const Tile tile);
};



