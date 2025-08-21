#include <iostream>
#include "Game.h"

int main()
{
	Game* gamePtr = new Game;
	gamePtr->initGame();
	gamePtr->startGame();
	delete gamePtr;
	return 0;
}