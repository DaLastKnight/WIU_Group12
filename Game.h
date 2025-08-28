#pragma once
#include "Player.h"
#include "SelectClass.h"
#include "World.h"
#include "Town.h"
#include "Dungeon.h"
#include "Difficultyselection.h"
#include "Wood.h"
#include "Stone.h"
#include "Enemy.h"
#include "Inventory.h"


class Game
{
private:
	DifficultySelection diffselect;
	Enemy grade;

	// Stats management
	Gold* goldPtr;

	// World management
	char currentSymbol;
	bool isResetDungeon;
	World* currentWorld;
	Town* townPtr;
	Dungeon* dungeonPtr;

	SelectClass selectClass;
	Player* playerPtr;
	DifficultySelection* diffPtr;
	Enemy* enemyPtr;
	Inventory* inventoryPtr;

	bool confirmSelection();
public:
	Game();
	~Game();

	void initGame();
	void startingScreen();
	void startGame();
	void switchWorld(char newSymbol);
	void setDungeonReset();
	void restartGame();
	Gold* getGoldPtr() const;
	Player* getPlayerPtr() const;
	DifficultySelection* getDifficultySelector() const;
	Enemy* getEnemyGrade() const;
	Inventory* getInventoryPtr() const;
};