#include "Player.h"
#include "Arrow.h"
#include "Game.h"
#include "Map.h"
#include <iostream>

void Player::shot()
{
	vector2D diff = GetLocation() - locLastFrame;
	Direction direct = Direction::right;
	if (diff.x == 0 && diff.y == 1)
		direct = Direction::down;
	if (diff.x == 0 && diff.y == -1)
		direct = Direction::up;
	if (diff.x == 1 && diff.y == 0)
		direct = Direction::right;
	if (diff.x == -1 && diff.y == 0)
		direct = Direction::left;

	//Make spawn Actor Function
	Game& game = Game::GetInstance();
	Arrow* arrow = new Arrow(direct);
	arrow->SetLocation(GetLocation() + diff);
	game.map->AddActor(arrow);
}