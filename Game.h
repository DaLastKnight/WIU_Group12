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

class Game
{
private:
	DifficultySelection diffselect;
	Enemy grade;

	// Stats management
	Gold* goldPtr;
	Wood* woodPtr;
	Stone* stonePtr;

	// World management
	char currentSymbol;
	World* currentWorld;
	Town* townPtr;
	Dungeon* dungeonPtr;

	SelectClass selectClass;
	Player* playerPtr;
	DifficultySelection* diffPtr;
	Enemy* enemyPtr;
	bool confirmSelection();
public:
	Game();
	~Game();

	void initGame();
	void startingScreen();
	void startGame();
	void switchWorld(char newSymbol);
	Gold* getGoldPtr() const;
	Wood* getWoodPtr() const;
	Stone* getStonePtr() const;
	Player* getPlayerPtr() const;
	DifficultySelection* getDifficultySelector() const;
	Enemy* getEnemyGrade() const;
};