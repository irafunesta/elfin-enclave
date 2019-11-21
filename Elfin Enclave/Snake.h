#pragma once
#include "Entity.h"

class Snake: public Entity
{
public:
	Snake(char Symbol) : Entity(Symbol) {};
	~Snake();

	Position HandleInput(char input);
	void CheckCollision(char nextTile, Position move);
private:
	bool _goDown = false;
	//Position _wantsToMove;
};

