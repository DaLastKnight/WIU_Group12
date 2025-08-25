#include "Game.h"
#include "Gold.h"
#include "Town.h"
#include "Dungeon.h"

Game::Game()
{
	
	currentSymbol = 'T';
	currentWorld = nullptr;
	goldPtr = nullptr;
	townPtr = nullptr;
	dungeonPtr = nullptr;
}

Game::~Game()
{
	delete townPtr;
	delete dungeonPtr;
}

void Game::initGame()
{
	goldPtr = new Gold(0);
	townPtr = new Town(this);
	dungeonPtr = new Dungeon(this);
	townPtr->initWorld();
	dungeonPtr->initWorld();
}

void Game::startGame()
{
	currentWorld = townPtr;
	currentWorld->loopWorld();
}

Gold* Game::getGoldPtr() const
{
	return goldPtr;
}

void Game::switchWorld(char newSymbol)
{
	if (currentSymbol == newSymbol)
	{
		std::cout << "You are already in this world!" << '\n';
	}
	else
	{
		currentSymbol = newSymbol;

		if (currentSymbol == 'T')
		{
			currentWorld = townPtr;
			
		}
		else if (currentSymbol == 'N')
		{
			currentWorld = dungeonPtr;
		}
	}

	currentWorld->loopWorld();
}
