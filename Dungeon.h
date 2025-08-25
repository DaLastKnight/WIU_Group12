#pragma once
#include "World.h"
#include "Tile.h"
#include "PlayerTile.h"
#include "Shop.h"
#include "Portal.h"

class Game;

class Dungeon : public World
{
private:
	bool isInMenu;
	int currentDungeonLevel;
	int maxTiles;

    Game* gamePtr;
    PlayerTile* playerTilePtr;
    Tile** tileList;
    Shop* shopPtr;
    Portal portal;
public:
	Dungeon(Game* ptrGame);
	~Dungeon();
	void initWorld();
	void loopWorld();
	void checkInteraction();
	void resetDungeon();
	void updateTilePositions();
	void setDefault();
};
