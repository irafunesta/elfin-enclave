#pragma once
#include "Entity.h"
#include "Position.h"

class Player : public Entity
{
public:
	Player(char Symbol) : Entity(Symbol) {};
	~Player();

	//Next step need thinking 
	static enum Action
	{
		MOVE_DOWN,
		MOVE_UP,
		MOVE_LEFT,
		MOVE_RIGHT
	};

	Position HandleInput (char input);
	//Position HandleInput(std::string input, char nextTile);
	void CheckCollision(char nextTile, Position move);
private:
	//Position _wantsToMove;
};

