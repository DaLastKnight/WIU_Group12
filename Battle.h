#pragma once
#include "World.h"
#include "Enemy.h"
#include "DifficultySelection.h"
#include "Entity.h"
#include "PlayerClass.h"
#include "Wood.h"
#include "Stone.h"
#include "Gold.h"
#include "Items.h"
#include "Inventory.h"

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
	char gradeType;

	Tile** tileList;
	Tile* tilePtr;
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
	Inventory* inventoryPtr;
	
	bool confirmSelection();
	
public:
	Battle(Game* ptrGame, Player* player, char grade);
	~Battle();
	void battleMenu();
	bool enemySelect();
	void initWorld();
	void printWorld();
	void loopWorld();
	void updateTilePositions();
	void checkInteraction();
};