#pragma once
#include "SceneManager.h"
#include "SceneNode.h"
#include "Map.h"
/*
	Renderer 
	Class used to render the game,	
	can render a scene, 
	and can render a scene node
*/
class Renderer
{
public:
	Renderer();
	~Renderer();

	void RenderScene(SceneManager *scene);
	void RenderNode(SceneNode *node);
};

