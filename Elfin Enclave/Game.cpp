#include <iostream>
#include <cstdio>
#include <list>
#include <conio.h>
#include "Game.h"
#include "Player.h"
#include "Snake.h"
#include "SceneManager.h"
#include "SceneNode.h"
#include "Renderer.h"
#include "Position.h"

Entity *player2 = new Player('@');
SceneManager sceneManager = SceneManager::instance();
Renderer renderer;

Game::Game()
{
	_bGameOver = false;	
}

Game::~Game()
{
}

//TODO make real intro
void Game::PrintIntro()
{
	std::cout << "Intro";
}

void Game::Start()
{
	//Print the intro
	//Load the map
	PrintIntro();
	//Make the scene manager load the first map
	
	int mapLoadingErr;
	mapLoadingErr = sceneManager.LoadMap("map1.txt");
	if(mapLoadingErr == 1) 
	{
		//If the map can't be loaded end the program
		_bGameOver = true;
	}
	
	/*for (int i = 0; i < 3; i++)
	{
		Entity *snake = new Snake('S');
		snake->SetPosition(5, 5+i);
		_EntityList.push_back(snake);
	}*/
	
	/*player->SetPosition(1,1);
	_EntityList.push_back(player);*/
	//Create a scene node for the player
	SceneNode *playerNode = new SceneNode("player", player2);
	playerNode->SetPosition(1, 1);

	//Add it to the scene
	sceneManager.AddSceneNode(playerNode);
}

void Game::Update()
{
	//Draw the loaded map with the relative entities
	//Use & to get the pointer
	renderer.RenderScene(&sceneManager);
	
	//Print data here
	//Test the scene node retrive
	SceneNode *playerNode = sceneManager.GetSceneNode("player");
	std::cout << "(x:" << playerNode->GetPositionX() << ",y:" << playerNode->GetPositionY() << ")" << std::endl;
	
	char input;
	input = _getch();

	//HandleInput(input);
	
	for (int i = 0; i < sceneManager.GetSceneNodes().size(); i++)
	{
		SceneNode *node = sceneManager.GetSceneNodes()[i];
		//Handle the input given, it will return a position to move
		//TODO more rich input handling for thing different than movement
		Position move ;

		//if the node wants to move Check collision for now only wall		
		if(sceneManager.GetMapTile(node->GetPositionX() + move.x, node->GetPositionY() + move.y) != '#') {
			node->SetPositionRelative(move.x, move.y);
		}
	}

	//_bGameOver = true;
}

void HandleInput(char input)
{
	SceneNode *player = sceneManager.GetSceneNode("player");
	int x = player->GetPositionX();
	int y = player->GetPositionY();

	switch (input)
	{
		case 'd':
		{
			if (sceneManager.GetMapTile(x + 1, y) != '#') // Inverted coordinates cause vector of string
			{
				//SetPositionRelative(1, 0);
				player->SetPositionRelative(1, 0);
			}
			break;
		}
		case 'a':
		{
			if (sceneManager.GetMapTile(x - 1, y) != '#')
			{
				player->SetPositionRelative(-1, 0);
			}
			break;
		}
		case 's':
		{
			if (sceneManager.GetMapTile(x, y + 1) != '#')
			{
				player->SetPositionRelative(0, 1);
			}
			break;
		}
		case 'w':
		{
			if (sceneManager.GetMapTile(x, y - 1) != '#')
			{
				player->SetPositionRelative(0, -1);
			}
			break;
		}
		default:
		{
			std::cout << "Input :" << input;
			break;
		}
	}
}

bool Game::IsGameOver()
{
	return _bGameOver;
}
