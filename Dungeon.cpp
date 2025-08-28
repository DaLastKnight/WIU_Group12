#include "Game.h"
#include "Dungeon.h"
#include "Tile.h"
#include "PlayerTile.h"
#include "Shop.h"
#include "Portal.h"
#include "Battle.h"

Dungeon::Dungeon(Game* ptrGame, Player* player)
{
	worldType = "Dungeon";
	isInMenu = false;
	isInBattle = false;
	currentDungeonLevel = 1;
	gridWidth = 15;
	gridHeight = 15;
	gamePtr = ptrGame;
	shopPtr = new Shop(gamePtr->getGoldPtr());
	playerTilePtr = nullptr;
	battlePtr = nullptr;
	world = new char* [gridWidth];
	playerPtr = player;
	diffPtr = gamePtr->getDifficultySelector();
	enemyPtr = gamePtr->getEnemyGrade();

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
	gamePtr = nullptr;

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
			tileList[i] = new Tile('T'); // Teleporter 
			tileList[i]->setTilePosition(gridWidth, gridHeight, 0, 4);
			break;
		case 1:
			tileList[i] = new Tile('S'); // Shop
			tileList[i]->setTilePosition(gridWidth, gridHeight, 0, 8);
			break;
		case 2:
			tileList[i] = new Tile('E'); // Enemy
			enemy1row = rand() % 15;
			enemy1col = rand() % 15;
			if (enemy1row == 4 && enemy1col == 4)
			{
				tileList[i]->setTilePosition(gridWidth, gridHeight, enemy1row + 1, enemy1col);
			}
			else if (enemy1row == 0 && enemy1col == 4)
			{
				tileList[i]->setTilePosition(gridWidth, gridHeight, enemy1row + 1, enemy1col);
			}
			else if (enemy1row == 0 && enemy1col == 8)
			{
				tileList[i]->setTilePosition(gridWidth, gridHeight, enemy1row + 1, enemy1col);
			}
			else
			{
				tileList[i]->setTilePosition(gridWidth, gridHeight, enemy1row, enemy1col);
			}
			
			break;
		case 3:
			tileList[i] = new Tile('E'); // Enemy
			enemy1row = rand() % 15;
			enemy1col = rand() % 15;
			if (enemy1row == 4 && enemy1col == 4)
			{
				tileList[i]->setTilePosition(gridWidth, gridHeight, enemy1row + 1, enemy1col);
			}
			else if (enemy1row == 0 && enemy1col == 4)
			{
				tileList[i]->setTilePosition(gridWidth, gridHeight, enemy1row + 1, enemy1col);
			}
			else if (enemy1row == 0 && enemy1col == 8)
			{
				tileList[i]->setTilePosition(gridWidth, gridHeight, enemy1row + 1, enemy1col);
			}
			else
			{
				tileList[i]->setTilePosition(gridWidth, gridHeight, enemy1row, enemy1col);
			}
			break;
		case 4:
			tileList[i] = new Tile('E'); // Enemy
			enemy1row = rand() % 15;
			enemy1col = rand() % 15;
			if (enemy1row == 4 && enemy1col == 4)
			{
				tileList[i]->setTilePosition(gridWidth, gridHeight, enemy1row + 1, enemy1col);
			}
			else if (enemy1row == 0 && enemy1col == 4)
			{
				tileList[i]->setTilePosition(gridWidth, gridHeight, enemy1row + 1, enemy1col);
			}
			else if (enemy1row == 0 && enemy1col == 8)
			{
				tileList[i]->setTilePosition(gridWidth, gridHeight, enemy1row + 1, enemy1col);
			}
			else
			{
				tileList[i]->setTilePosition(gridWidth, gridHeight, enemy1row, enemy1col);
			}
			break;
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

void Dungeon::checkInteraction()
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
					gamePtr->switchWorld(portal.teleport(worldType));
				}
				else if (tileList[i]->getTileSymbol() == 'S')
				{
					isInMenu = true;
					shopPtr->interactShop();
					isInMenu = false;
					loopWorld();
				}
				else if (tileList[i]->getTileSymbol() == 'C')
				{
					isInMenu = true;
					isInMenu = false;
					loopWorld();
				}
				else if (tileList[i]->getTileSymbol() == 'E')
				{
					battlePtr = new Battle(gamePtr, playerPtr);
					system("cls");
					isInBattle = true;
					isInMenu = true;
					battlePtr->loopWorld();
					isInBattle = false;
					isInMenu = false;
					delete tileList[i];
					tileList[i] = nullptr;
					loopWorld();
				}
				isCollide = false;
			}
		}
	}
}

void Dungeon::resetDungeon()
{
	// resets player pos to one side of the dungeon
}

void Dungeon::updateTilePositions()
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

void Dungeon::loopWorld()
{
	updateTilePositions();
	printWorld();

	while (true)
	{
		if (!isInMenu)
		{
			if (isInBattle) {
				isInBattle = false;
			}
			else {
				playerTilePtr->move(gridWidth, gridHeight);
			}
		}
		updateTilePositions();
		printWorld();
		checkInteraction();
	}
}

void Dungeon::setDefault()
{
	playerTilePtr->setTilePosition(gridWidth, gridHeight, 4, 4);
}