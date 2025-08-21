#include "Game.h"
#include "Town.h"
#include "Dungeon.h"

Game::Game()
{
	currentWorld = nullptr;
	dungeonPtr = nullptr;
}

Game::~Game()
{
	delete dungeonPtr;
}

void Game::initGame()
{
	dungeonPtr = new Dungeon;
	town.initWorld();
}

void Game::startGame()
{
	town.loopWorld();
}
