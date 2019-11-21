#pragma once
#include <vector>
#include <string>
#include "Position.h"
/*
	Define a base entity on the map such as 
	the player
	the monsters
	the npcs
	ecc
*/
class Entity
{
public:
	Entity(char Symbol) { _Symbol = Symbol; };
	~Entity();
	
	int GetSymbol() const { return _Symbol; };
	virtual Position HandleInput(char action) = 0;
	//virtual Position HandleInput(std::string action, char nextTile) = 0;
	virtual void CheckCollision(char nextTile, Position move) = 0;
	
	Position GetPosition() const { return _pos; };

	void SetPosition(int x, int y) {
		_pos.x = x; 
		_pos.y = y; 
	};

	void SetPosition(Position p) {
		SetPosition(p.x, p.y);
	};
protected:
	char _Symbol;
	Position _pos;
};

