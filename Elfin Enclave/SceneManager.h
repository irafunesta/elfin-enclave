#pragma once
#include "SceneNode.h"
#include <vector>
#include <string>
#include "Map.h"
/*
SceneManager
Will menage the current scene, 
has the list of SceneNode,
Can retrive one specific scene node
It will be a singleton
*/
class SceneManager
{
public:
	static SceneManager& instance()
	{
		static SceneManager *instance = new SceneManager();
		return *instance;
	}

	void AddSceneNode(SceneNode* node);
	int LoadMap(std::string map);
	SceneNode* GetSceneNode(std::string id);
	SceneNode* GetSceneNodeAtPos(int x, int y);
	std::vector<SceneNode*> GetSceneNodes() { return _scene; }
	Map GetMap() const { return _map; };
	char GetMapTile(int x, int y) { return _map.GetMapTile(x, y); }
private:
	SceneManager();
	std::vector<SceneNode*> _scene; //I use a vector cause i don't care about the order
	Map _map;
};

