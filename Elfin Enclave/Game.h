#pragma once
#include "Map.h"

class Game
{
public:
	//Initialized Constructor
	Game();
	~Game();

	void PrintIntro();
	void Start();
	void Update();
	bool IsGameOver();
private:

	bool _bGameOver;	
};

