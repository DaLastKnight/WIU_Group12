#pragma once
#include "Tile.h"

class Inventory;

class PlayerTile : public Tile
{
private:
	Inventory* inventoryPtr;
	bool isPlayerMoved;
public:
	PlayerTile(Inventory* playerInventory);
	~PlayerTile();
	void move(int maxGridWidth, int maxGridHeight);
};
