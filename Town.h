#pragma once
#include "World.h"
#include "Tile.h"
#include "PlayerTile.h"
#include "Shop.h"
#include "SelectClass.h"
#include "Portal.h"

class Town : public World
{
private:
	bool isInMenu;
	bool hasTeleported;
	int maxTiles;
	Tile** tileList;
	PlayerTile* playerTilePtr;
	Shop shop;
	SelectClass selectorClass;
	Portal portal;

public:
	Town();
	~Town();
	void initWorld();
	void checkInteraction();
	void updateTilePositions();
	void loopWorld();
};
