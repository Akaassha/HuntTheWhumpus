#include "Player.h"
#include <iostream>

void Player::draw() 
{
	Actor::draw();
	std::cout << '(' << ')';
}