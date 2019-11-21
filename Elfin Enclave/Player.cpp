#include <iostream>
#include "Player.h"

/*Player::Player(char Symbol)
{
	_Symbol = Symbol;
	_X = 1;
	_Y = 1;
}*/

Player::~Player()
{
}

Position Player::HandleInput(char input)
{
	Position p;
	switch (input) {
		case 's':
			//Move player down
			p.x = _pos.x;
			p.y = _pos.y + 1;
			break;
		case 'w':
			//Move player up
			p.x = _pos.x;
			p.y = _pos.y - 1;
			break;
		case 'a':
			//Move player left
			p.x = _pos.x - 1;
			p.y = _pos.y;
			break;
		case 'd':
			//Move player right
			p.x = _pos.x + 1;
			p.y = _pos.y;
			break;
		default:
			//Do shits
			p.x = _pos.x;
			p.y = _pos.y;
			break;
	}

	//_wantsToMove = p;
	return p;
}

void Player::CheckCollision(char nextTile, Position move)
{	
	if (nextTile == '.') {
		SetPosition(move);
	}
}

