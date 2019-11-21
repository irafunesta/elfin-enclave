#pragma once

class StupidGame
{
public:
	StupidGame();
	~StupidGame();
	void PrintIntro();
	void Start();
	void Update();
	void ParseInput();
	void Draw();
	void GameEnd();
	bool IsGameOver();

	//void HandlePlayerInput(char input, Entity *e);

	void HandleSnakeMove();
private:

	bool _bGameOver = false;
};

