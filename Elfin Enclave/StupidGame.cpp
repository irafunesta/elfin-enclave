#include <string>
#include <vector>
#include <conio.h>
#include <iostream>
#include "StupidGame.h"
#include "Map.h"
#include "Position.h"
#include "Player.h"
#include "Snake.h"

Entity *player = new Player('@');
Map map;
Position snake;
char snake_char = 'S';
char prev_snake_char;
std::vector<Entity*> entities;

StupidGame::StupidGame()
{
}


StupidGame::~StupidGame()
{
}

void StupidGame::PrintIntro()
{

};

void StupidGame::Start() 
{
	//Load the map	
	int mapLoadingErr;
	mapLoadingErr = map.LoadMap("map1.txt");
	if (mapLoadingErr == 1)
	{
		//If the map can't be loaded end the program
		_bGameOver = true;
	}

	//Player starting position
	player->SetPosition(5, 5);

	//Add an enemy S for now only one
	Entity *snake = new Snake('S');
	snake->SetPosition(2, 1);

	//Set prev snake char
	//prev_snake_char = map.GetMapTile(snake.x, snake.y);
	//map.SetMapTile(snake.x, snake.y, snake_char);

	entities.push_back(player);
	entities.push_back(snake);
};

void StupidGame::Draw()
{
	system("cls");
	//Print the map location
	std::cout << std::endl;
	std::cout << "     Map 1" << std::endl;
	std::cout << std::endl;

	map.PrintMap(entities);

	Position player_pos = entities[0]->GetPosition();
	std::cout << "(x:" << player_pos.x << ",y:" << player_pos.y << ")" << std::endl;
}

void StupidGame::Update()
{
	//Get the input
	//Move the player
	//Check collision
	//Print the map
	
	char input = '1';
	//Handle input
	if (_kbhit())
	{
		input = _getch();
	}

	for (int i = 0; i < entities.size(); i++) {
		Entity *e = entities[i];
		//Move the entity, if a Player it will move based on the input
		Position move = e->HandleInput(input);
		//Check for collision
		e->CheckCollision(map.GetMapTile(move.x, move.y), move);
	}

	//System input
	switch (input) {
		case 'p':
			_bGameOver = true;
			break;		
		default:
			//Do shits
			break;
	}
}

void StupidGame::GameEnd()
{
	//std::cout << "Game Over" << std::endl;
};

bool StupidGame::IsGameOver()
{
	return _bGameOver;
};

