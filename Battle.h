#pragma once
#include "World.h"
#include "Enemy.h"
#include "DifficultySelection.h"
#include "Entity.h"
#include "PlayerClass.h"
#include "Wood.h"
#include "Stone.h"
#include "Gold.h"

class Battle : public World
{
private:
	int row;
	int column;
	int maxTiles;
	bool enemyAlive[3];
	bool battleActive;
	bool defending;
	bool useSkill;

	Tile** tileList;
	PlayerTile* playerTilePtr;
	Game* gamePtr;
	Enemy* eType[3];
	Entity* entityPtr;
	Player* playerPtr;
	PlayerClass* pc;
	DifficultySelection* diffPtr;
	Stone* stonePtr;
	Wood* woodPtr;
	Gold* goldPtr;
	
	bool confirmSelection();
	
public:
	Battle(Game* ptrGame, Player* player);
	~Battle();
	void battleMenu();
	bool enemySelect();
	void initWorld();
	void printWorld();
	void loopWorld();
	void updateTilePositions();
	void checkInteraction();
};