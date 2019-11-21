/*
	ASCII Rogue-like game
*/
#include <iostream>
//#include "Game.h"
#include <dos.h>
#include <chrono>
#include <ctime>

#include "windows.h"
#include "StupidGame.h"

void getCurrentTime()
{

}

int main()
{
	//TODO Make Game loop with the Update pattern
	/*
		Game intro

		While(Game is not finished)			
			Game.update()			

		Game Exit
	*/
	std::chrono::high_resolution_clock::time_point lastTime = std::chrono::high_resolution_clock::now();
	
	double step = 200;
	double counter = 0;
	StupidGame Game;
	Game.Start();
	
	while (!Game.IsGameOver()) {

		std::chrono::high_resolution_clock::time_point current = std::chrono::high_resolution_clock::now();
		std::chrono::duration<double, std::milli> elapsed = current - lastTime;
		
		if (counter >= step)
		{
			Game.Update();
			counter = 0;
		}
		Game.Draw();

		std::cout << "elapsed time: " << elapsed.count() << "s\n";
		lastTime = current;
		counter += elapsed.count();
		//Sleep(300);
	}

	std::cout << "Game Over" << std::endl;
	system("PAUSE");
	return 0;
}