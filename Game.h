#pragma once
#include "World.h"
#include "Town.h"
#include "Dungeon.h"
#include "Difficultyselection.h"

class Game
{
private:
	World* currentWorld;
	Town town;
	Dungeon* dungeonPtr;
	DifficultySelection diffselect;

	bool confirmSelection();
public:
	Game();
	~Game();

	void initGame();
	void startingScreen();
	void startGame();
};