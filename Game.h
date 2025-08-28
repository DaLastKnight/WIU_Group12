#pragma once
#include "Player.h"
#include "Inventory.h"
#include "SelectClass.h"
#include "World.h"
#include "Town.h"
#include "Dungeon.h"
#include "Difficultyselection.h"
#include "Wood.h"
#include "Stone.h"

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

	SelectClass selectClass;
	Player* playerPtr;
	Inventory* inventoryPtr;

	bool confirmSelection();
public:
	Game();
	~Game();

	void initGame();
	void startingScreen();
	void startGame();
	void switchWorld(char newSymbol);
	Gold* getGoldPtr() const;
	Player* getPlayerPtr() const;
	Inventory* getInventoryPtr() const;
};