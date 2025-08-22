#pragma once
#include "World.h"
#include "Tile.h"
#include "PlayerTile.h"
#include "Shop.h"
#include "SelectClass.h"
#include "Portal.h"

class Game;

class Town : public World
{
private:
	bool isInMenu;
	bool hasTeleported;
	int maxTiles;
	Game* gamePtr;
	Tile** tileList;
	PlayerTile* playerTilePtr;
	Shop* shopPtr;
	SelectClass selectorClass;
	Portal portal;

public:
	Town(Game* ptrGame);
	~Town();
	void initWorld();
	void checkInteraction();
	void updateTilePositions();
	void loopWorld();
	void setDefault();
};

