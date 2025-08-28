#include <iostream>
#include "Game.h"

int main()
{
	Game* gamePtr = new Game();
	gamePtr->initGame();
	gamePtr->startingScreen();
	delete gamePtr;
	return 0;
}