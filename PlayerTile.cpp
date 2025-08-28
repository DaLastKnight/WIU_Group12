#include <iostream>
#include <conio.h>
#include "PlayerTile.h"

#include <Windows.h> 
#include <ctype.h>
#include <cstdlib>
#include "World.h"

#include "Inventory.h"
#include "Sword.h"
#include "Bow.h"
#include "Dagger.h"
#include "LightArmor.h"
#include "HeavyArmor.h"
#include "HealthPotions.h"
#include "Rope.h"
#include "Wood.h"
#include "Stone.h"

PlayerTile::PlayerTile(Inventory* playerInventory)
{
	tileSymbol = 'P';
	isPlayerMoved = false;
	inventoryPtr = playerInventory;
}

PlayerTile::~PlayerTile()
{
	inventoryPtr = nullptr;
}

void PlayerTile::move(int maxGridWidth, int maxGridHeight)
{
	isPlayerMoved = false;

	while (!isPlayerMoved)
	{
		int input = _getch();
		
		switch (input)
		{
		case 72:
			setTilePosition(maxGridWidth, maxGridHeight, getTileRow() - 1, getTileColumn()); // go up
			isPlayerMoved = true;
			break;
		case 80:
			setTilePosition(maxGridWidth, maxGridHeight, getTileRow() + 1, getTileColumn()); // go down
			isPlayerMoved = true;
			break;
		case 75:
			setTilePosition(maxGridWidth, maxGridHeight, getTileRow(), getTileColumn() - 1); // go left
			isPlayerMoved = true;
			break;
		case 77:
			setTilePosition(maxGridWidth, maxGridHeight, getTileRow(), getTileColumn() + 1); // go right
			isPlayerMoved = true;
			break;
		case 73:
		case 105:
			inventoryPtr->openInventory();
			isPlayerMoved = true;
			break;
		default:
			isPlayerMoved = false;
			break;
		}
	}
}