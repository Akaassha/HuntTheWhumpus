#include "Actor.h"
#include "Game.h"
#include "GraphicEngine.h"
#include "Map.h"
#include "Tile.h"

void Actor::move(Direction direction, int distant)
{

	if (!canMove(direction, distant)) return;
	locLastFrame = GetLocation();

	switch (direction)
	{
	case Actor::Direction::up:
		SetLocation(GetLocation() + vector2D{ 0 , -1 } * distant);
		break;
	case Actor::Direction::down:
		SetLocation(GetLocation() + vector2D{ 0 , 1 } *distant);
		break;
	case Actor::Direction::left:
		SetLocation(GetLocation() + vector2D{ -1 , 0 } *distant);
		break;
	case Actor::Direction::right:
		SetLocation(GetLocation() + vector2D{ 1 , 0 } *distant);
		break;
	default:
		break;

	}


}

Actor::~Actor()
{
	Game& game = Game::GetInstance();
	GraphicEngine& graphicEngine = GraphicEngine::GetInstance();
	graphicEngine.redrawTile(GetLocation());
	game.map->RemoveActor(this);

}

void Actor::draw()
{
	std::cout << apperance.first << apperance.second;
}

void Actor::tick()
{
	draw();

	if (locLastFrame != GetLocation());
	{
		GraphicEngine& graphicEngine = GraphicEngine::GetInstance();
		graphicEngine.redrawTile(locLastFrame);
	}

}

bool Actor::canMove(Direction direction, int distant)
{
	Game& game = Game::GetInstance();
	
	vector2D loc;
	switch (direction)
	{
	case Actor::Direction::up:
		loc = (GetLocation() + vector2D{ 0 , -1 } *distant);
		break;
	case Actor::Direction::down:
		loc = (GetLocation() + vector2D{ 0 , 1 } *distant);
		break;
	case Actor::Direction::left:
		loc = (GetLocation() + vector2D{ -1 , 0 } *distant);
		break;
	case Actor::Direction::right:
		loc = (GetLocation() + vector2D{ 1 , 0 } *distant);
		break;
	default:
		break;

	}

	if (game.map->getTile(loc).type == Tile::Type::wall)
		return false;
	else
		return true;
}