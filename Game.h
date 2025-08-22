#pragma once
#include "World.h"
#include "Town.h"
#include "Dungeon.h"
#include "Difficultyselection.h"
#include "Gold.h"

class Game
{
private:
	// Stats management
	Gold* goldPtr;

	// World management
	char currentSymbol;
	World* currentWorld;
	Town* townPtr;
	Dungeon* dungeonPtr;
	DifficultySelection diffselect;

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