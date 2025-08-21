#pragma once
#include "World.h"
#include "Town.h"
#include "Dungeon.h"
class Game
{
private:
	World* currentWorld;
	Town town;
	Dungeon* dungeonPtr;
public:
	Game();
	~Game();

	void initGame();
	void startGame();
};

