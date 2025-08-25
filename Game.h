#pragma once
#include "World.h"
#include "Town.h"
#include "Dungeon.h"
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
public:
	Game();
	~Game();

	void initGame();
	void startGame();
	void switchWorld(char newSymbol);
	Gold* getGoldPtr() const;
};

