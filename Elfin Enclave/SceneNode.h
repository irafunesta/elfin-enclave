#pragma once
#include "Entity.h"
#include <string>
/*
SceneNode
Correspond to a node on the scene containing an Entity,
His position
His rotation (not used for now)
His scale (not used for now)
*/
class SceneNode
{
public:
	SceneNode();
	SceneNode(std::string id) : _id(id) {};
	SceneNode(std::string id, Entity *entity) : _entity(entity), _id(id) {};
	~SceneNode();

	int GetPositionX() const { return _x; };
	int GetPositionY() const { return _y; };

	void SetPosition(int X, int Y)
	{
		_x = X;
		_y = Y;
	};

	void SetPositionRelative(int X, int Y)
	{
		_x += X;
		_y += Y;
	};

	std::string GetId() const {return _id; };
	Entity* GetEntity() const { return _entity; };

	//void HandleInput(SceneManager &sceneManager, char input);

private:
	int _x;
	int _y;
	Entity *_entity;
	std::string _id;
};

