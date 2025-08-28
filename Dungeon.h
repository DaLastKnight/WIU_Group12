#pragma once
#include "World.h"
#include "Tile.h"
#include "PlayerTile.h"
#include "Shop.h"
#include "Portal.h"
#include "Battle.h"
#include "Difficultyselection.h"
#include "Stone.h"
#include "Wood.h"
#include "Enemy.h"

class Game;

class Dungeon : public World
{
private:
	bool isInMenu;
	int currentDungeonLevel;
	int maxTiles;
	bool isInBattle;
	int enemy1row;
	int enemy1col;

	Game* gamePtr;
	PlayerTile* playerTilePtr;
	Tile** tileList;
	Shop* shopPtr;
	Portal portal;
	Enemy* enemyPtr;
	Battle* battlePtr;
	Player* playerPtr;
	DifficultySelection* diffPtr;
	Wood* woodPtr;
	Stone* stonePtr;

public:
	Dungeon(Game* ptrGame, Player* player);
	~Dungeon();
	void initWorld();
	void loopWorld();
	void checkInteraction();
	void resetDungeon();
	void updateTilePositions();
	void setDefault();
};
