#include "Snake.h"

Position Snake::HandleInput(char input)
{
	Position p = _pos;
	//The snake move up and down from wall to wall
	if (_goDown) {
		p.y++;
	}
	else {
		p.y--;
	}
	return p;
}

void Snake::CheckCollision(char nextTile, Position move)
{
	if (nextTile == '.') {
		SetPosition(move);
	}
	if (nextTile == '#') {
		_goDown = !_goDown;
	}
	if (nextTile == '@') {
		_goDown = !_goDown;
	}
}
