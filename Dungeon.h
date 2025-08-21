#pragma once
#include "World.h"
#include "Tile.h"
#include "PlayerTile.h"

class Dungeon : public World
{
private:
	bool isInMenu;
	int currentDungeonLevel;
	int maxTiles;
	PlayerTile* playerTilePtr;
	Tile** tileList;
public:
	Dungeon();
	~Dungeon();
	void initWorld();
	void loopWorld();
	void checkInteraction();
	void resetDungeon();
	void updateTilePositions();
};

