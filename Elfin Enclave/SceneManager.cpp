#include "SceneManager.h"

SceneManager::SceneManager()
{
}
/*
	Add a new node to the Scene
*/
void SceneManager::AddSceneNode(SceneNode * node)
{
	_scene.push_back(node);
}

int SceneManager::LoadMap(std::string map)
{
	return _map.LoadMap(map);
}

SceneNode * SceneManager::GetSceneNode(std::string id)
{
	SceneNode * p = nullptr;
	for(int i = 0; i < _scene.size(); i++) {
		if(_scene[i]->GetId() == id) {
			p = _scene[i];
			break;
		}
	}
	return p;
}

SceneNode * SceneManager::GetSceneNodeAtPos(int x, int y)
{
	SceneNode * p = nullptr;
	for (int i = 0; i < _scene.size(); i++) {
		if (_scene[i]->GetPositionX() == x && _scene[i]->GetPositionY() == y) {
			p = _scene[i];
			break;
		}
	}
	return p;
}

/*SceneManager::~SceneManager()
{
}*/
