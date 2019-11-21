#include "Renderer.h"
#include <vector>
#include <string>
#include <iostream>
#include <Windows.h>

Renderer::Renderer()
{
}


Renderer::~Renderer()
{
}

void Renderer::RenderScene(SceneManager * scene)
{
	/*
	Pass the scene Nodes ,
	add it to the loaded map,
	render the thing
	*/
	system("cls");
	Map currentMap = scene->GetMap();
	std::vector<std::string> map = currentMap.GetBaseMap();
	std::vector<SceneNode*> sceneList = scene->GetSceneNodes();

	// Draw the symbol of each node on the base map
	for (int i = 0; i < sceneList.size(); i++) {
		char symbol = sceneList[i]->GetEntity()->GetSymbol();
		int x = sceneList[i]->GetPositionX();
		int y = sceneList[i]->GetPositionY();
		map[y][x] = symbol;
	}

	// Draw the whole map
	for (int i = 0; i < map.size(); i++) {
		std::cout << map[i] << std::endl;
	}

}
