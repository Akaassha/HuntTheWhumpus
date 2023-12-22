#include "Actor.h"
#include "Game.h"
#include "GraphicEngine.h"
#include "Map.h"

void Actor::move(Direction direction, int distant)
{
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

void Actor::draw()
{
	
}

void Actor::tick()
{
	

	draw();

	if (locLastFrame != GetLocation());
	{
		GraphicEngine& graphicEngine = GraphicEngine::GetEngine();
		graphicEngine.redrawTile(locLastFrame);
	}

}