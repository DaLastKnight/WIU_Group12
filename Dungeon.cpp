#include "Dungeon.h"
#include "Tile.h"
#include "PlayerTile.h"

Dungeon::Dungeon()
{
	currentDungeonLevel = 1;
	gridWidth = 15;
	gridHeight = 15;
	isInMenu = false;
	worldType = "Dungeon";
	playerTilePtr = nullptr;
	world = new char* [gridWidth];

	for (int i = 0; i < gridWidth; i++)
	{
		world[i] = new char[gridHeight];
	}
	for (int i = 0; i < gridWidth; i++)
	{
		for (int j = 0; j < gridHeight; j++)
		{
			world[i][j] = '-';
		}
	}

	maxTiles = 10;
	tileList = new Tile * [maxTiles];

	for (int i = 0; i < maxTiles; i++)
	{
		tileList[i] = nullptr;
	}
}

Dungeon::~Dungeon()
{
	for (int i = 0; i < maxTiles; i++)
	{
		delete tileList[i];
	}

	delete[] tileList;
}

void Dungeon::initWorld()
{
	for (int i = 0; i < maxTiles; i++)
	{
		switch (i)
		{
		case 0:
			tileList[i] = new Tile('T'); // Teleporter to dungeons
			tileList[i]->setTilePosition(gridWidth, gridHeight, 0, 4);
			break;
		case 1:
			tileList[i] = new Tile('S'); // Shop
			tileList[i]->setTilePosition(gridWidth, gridHeight, 0, 8);
			break;
		case 2:
		case 3:
		case 4:
		case 5:
		case 6:
			// tileList[i] = new Tile('U'); // Unbuilt buildings
			break;
		default:
			break;
		}
	}

	playerTilePtr = new PlayerTile;
	playerTilePtr->setTilePosition(gridWidth, gridHeight, 4, 4);
}

void Dungeon::resetDungeon()
{
	// resets player pos to one side of the dungeon
}

void Dungeon::updateTilePositions()
{
	int currentTileRow = 0;
	int currentTileColumn = 0;

	for (int i = 0; i < maxTiles; i++)
	{
		if (tileList[i] != nullptr)
		{
			currentTileRow = tileList[i]->getTileRow();
			currentTileColumn = tileList[i]->getTileColumn();

			world[currentTileRow][currentTileColumn] = tileList[i]->getTileSymbol();
		}
	}
}

void Dungeon::loopWorld()
{

}