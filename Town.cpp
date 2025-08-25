#include <conio.h>
#include "Town.h"
#include "Tile.h"
#include "PlayerTile.h"
#include "Shop.h"
#include "selectClass.h"
#include "Portal.h"

Town::Town()
{
	isInMenu = false;
	hasTeleported = false;
	gridWidth = 10;
	gridHeight = 10;
	worldType = "Town";
	world = new char* [gridWidth];

	for (int i = 0; i < gridWidth; i++)
	{
		world[i] = new char[gridHeight];
	}
	for (int i = 0; i < gridWidth; i++)
	{
		for (int j = 0; j < gridHeight; j++)
		{
			world[i][j] = ' ';
		}
	}

	maxTiles = 7;
	tileList = new Tile * [maxTiles];

	for (int i = 0; i < maxTiles; i++)
	{
		tileList[i] = nullptr;
	}

	playerTilePtr = nullptr;
}

Town::~Town()
{
	for (int i = 0; i < maxTiles; i++)
	{
		delete tileList[i];
	}

	delete[] tileList;
}

void Town::initWorld()
{
	for (int i = 0; i < maxTiles; i++)
	{
		switch (i)
		{
		case 0:
			tileList[i] = new Tile('T'); // Teleporter/Portal to dungeons
			tileList[i]->setTilePosition(gridWidth, gridHeight, 0, 4);
			break;
		case 1:
			tileList[i] = new Tile('S'); // Shop
			tileList[i]->setTilePosition(gridWidth, gridHeight, 0, 8);
			break;
		case 2:
			tileList[i] = new Tile('C'); // Player class Selector
			tileList[i]->setTilePosition(gridWidth, gridHeight, 2, 1);
			break;
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

void Town::checkInteraction()
{
	bool isCollide = false;

	for (int i = 0; i < maxTiles; i++)
	{
		if (tileList[i] != nullptr)
		{
			if ((playerTilePtr->getTileRow() == tileList[i]->getTileRow()) && (playerTilePtr->getTileColumn() == tileList[i]->getTileColumn()))
			{
				isCollide = true;
			}

			if (isCollide)
			{
				if (tileList[i]->getTileSymbol() == 'T')
				{
					isInMenu = true;
					portal.teleport(worldType);
					isInMenu = false;
					loopWorld();
				}
				else if (tileList[i]->getTileSymbol() == 'S')
				{
					isInMenu = true;
					shop.interactShop();
					isInMenu = false;
					loopWorld();
				}
				else if (tileList[i]->getTileSymbol() == 'C')
				{
					isInMenu = true;
					selectorClass.chooseClass(p);
					isInMenu = false;
					loopWorld();
				}

				isCollide = false;
			}
		}
	}
}

void Town::updateTilePositions()
{
	for (int i = 0; i < gridWidth; i++)
	{
		for (int j = 0; j < gridHeight; j++)
		{
			world[i][j] = ' ';
		}
	}

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

	currentTileRow = playerTilePtr->getTileRow();
	currentTileColumn = playerTilePtr->getTileColumn();
	world[currentTileRow][currentTileColumn] = playerTilePtr->getTileSymbol();
}

void Town::loopWorld()
{
	updateTilePositions();
	printWorld();

	while (true)
	{
		if (!isInMenu)
		{
			playerTilePtr->move(gridWidth, gridHeight);
		}
		updateTilePositions();
		printWorld();
		checkInteraction();
	}
}