#pragma once
#include "World.h"
#include "Town.h"
#include "Dungeon.h"
#include "Difficultyselection.h"

class Game
{
private:
	DifficultySelection diffselect;

	// Stats management
	Gold* goldPtr;

	// World management
	char currentSymbol;
	World* currentWorld;
	Town* townPtr;
	Dungeon* dungeonPtr;

	bool confirmSelection();
public:
	Game();
	~Game();

	void initGame();
	void startingScreen();
	void startGame();
	void switchWorld(char newSymbol);
	Gold* getGoldPtr() const;
};