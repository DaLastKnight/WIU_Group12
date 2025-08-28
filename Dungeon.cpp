#include "Game.h"
#include "Dungeon.h"
#include "Tile.h"
#include "PlayerTile.h"
#include "Shop.h"
#include "Portal.h"
#include "Battle.h"
#include <conio.h>

#include <random>

Dungeon::Dungeon(Game* ptrGame, Player* player)
{
	worldType = "Dungeon";
	isInMenu = false;
	isInBattle = false;
	currentDungeonLevel = 1;
	currentEnemiesLeft = 0;
	gridWidth = 15;
	gridHeight = 15;
	gamePtr = ptrGame;
	shopPtr = new Shop(gamePtr->getInventoryPtr(), gamePtr->getGoldPtr());
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

	if (shopPtr != nullptr)
	{
		delete shopPtr;
	}

	for (int i = 0; i < maxTiles; i++)
	{
		delete tileList[i];
	}

	delete[] tileList;
	delete playerTilePtr;
}

void Dungeon::initWorld()
{
	int randomNumber = 0;
	std::mt19937 generator(std::random_device{}());
	std::uniform_int_distribution<int> spawnChance(0, 100);
	randomNumber = spawnChance(generator);

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
			tileList[i] = new Tile('N'); // Enemy
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
			tileList[i] = new Tile('N'); // Enemy
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
			if (randomNumber <= 50) {
				tileList[i] = new Tile('N'); // Enemy
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
			}
			else if (randomNumber > 50 && randomNumber <= 80) {
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
			}
			else if (randomNumber > 80 && randomNumber <= 100) {
				tileList[i] = new Tile('B'); // Enemy
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
			}
			
		case 5:
			if (randomNumber <= 20) {
				tileList[i] = new Tile('?'); // Enemy
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
			}
		default:
			break;
		}
	}

	currentEnemiesLeft = 3;
	playerTilePtr = new PlayerTile(gamePtr->getInventoryPtr());
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
					if (currentEnemiesLeft <= 0)
					{
						gamePtr->setDungeonReset();
					}
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
				else if (tileList[i]->getTileSymbol() == '?')
				{
					isInMenu = true;
					openTreasureChest();
					isInMenu = false;
					loopWorld();
				}
				else if (tileList[i]->getTileSymbol() == 'N')
				{
					battlePtr = new Battle(gamePtr, playerPtr, 'N');
					system("cls");
					isInBattle = true;
					isInMenu = true;
					battlePtr->loopWorld();
					isInBattle = false;
					isInMenu = false;
					delete tileList[i];
					tileList[i] = nullptr;
					currentEnemiesLeft--;
					loopWorld();
				}
				else if (tileList[i]->getTileSymbol() == 'E')
				{
					battlePtr = new Battle(gamePtr, playerPtr, 'E');
					system("cls");
					isInBattle = true;
					isInMenu = true;
					battlePtr->loopWorld();
					isInBattle = false;
					isInMenu = false;
					delete tileList[i];
					tileList[i] = nullptr;
					currentEnemiesLeft--;
					loopWorld();
				}
				else if (tileList[i]->getTileSymbol() == 'B')
				{
					battlePtr = new Battle(gamePtr, playerPtr, 'B');
					system("cls");
					isInBattle = true;
					isInMenu = true;
					battlePtr->loopWorld();
					isInBattle = false;
					isInMenu = false;
					delete tileList[i];
					tileList[i] = nullptr;
					currentEnemiesLeft--;
					loopWorld();
				}
				delete battlePtr;
				battlePtr = nullptr;
				isCollide = false;
			}
		}
	}
}

void Dungeon::resetDungeon()
{
    if (shopPtr != nullptr)
    {
        delete shopPtr;
    }
	shopPtr = nullptr;
	shopPtr = new Shop(gamePtr->getInventoryPtr(), gamePtr->getGoldPtr());

    for (int i = 0; i < maxTiles; i++)
    {
		if (tileList[i] != nullptr)
		{
            delete tileList[i];
			tileList[i] = nullptr;
		}   
    }

	delete playerTilePtr;

	initWorld();
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

void Dungeon::openTreasureChest()
{
	int keyInput = '-';
	int randomNumber = 0;
	std::mt19937 generator(std::random_device{}());
	std::uniform_int_distribution<int> goldAmount(0, 100);
	randomNumber = goldAmount(generator);

	gamePtr->getGoldPtr()->setTotalGold(gamePtr->getGoldPtr()->getTotalGold() + randomNumber);

	while (true)
	{
		system("cls");

		std::cout << "  |             |             |             |             |           \n";
		std::cout << "__|_____________|_______._.==_._____________|_____________|___________\n";
		std::cout << "         |         _.==` __.--'-,    |             |              |   \n";
		std::cout << "_________|________;   .=`        `=._._____________|______________|___\n";
		std::cout << "                |   `._ o '._           `=._|             |           \n";
		std::cout << "________________|______'-_  `--.            `=____________|___________\n";
		std::cout << "         |              `=_   `-._    __-'`'=.     |              |   \n";
		std::cout << "_________|_________.--'``` `=._ o  `-.`  _.--. `.__|______________|___\n";
		std::cout << "            ._.--`             `=._ .' ,`     ; '         |           \n";
		std::cout << "____________|o`-._                 `=._ `-._  ; '_________|___________\n";
		std::cout << "         |  | ;=. `--.                 `-._ ``` ;  |              |   \n";
		std::cout << "_________|__|o;  `-._ `-._                 `-._/___|______________|___\n";
		std::cout << "            | ;      (#). `-._          ___.--o|          |           \n";
		std::cout << "____________|o.`-.    `  `=_. `=-.__.--`o__.-; |__________|___________\n";
		std::cout << "________/_____'_ o`-_.      `-..o|o_.--'     ; |______/_______/_______\n";
		std::cout << "___/________/___`-.__ `=._     ; | ;         ; |/________/________/___\n";
		std::cout << "________/________/___`=._ `-.  ;o|o;    ,__.-; |______/_______/_______\n";
		std::cout << "___/________/________/___`=._`.; | ;_.--`o___.o|/________/________/___\n";
		std::cout << "________/________/________/__`=_o|o_.----`__/_________/_______/_______\n";
		std::cout << "___/________/________/________/________/________/________/________/___\n";
		std::cout << "________/________/________/________/________/________/________/_______\n";

		std::cout << "\nYou got " << randomNumber << " Gold from the treasure chest!\n";
		
		std::cout << "\nUse X to exit.\n";

		keyInput = _getch();

		switch (keyInput) {
		case 88:
		case 120:
			return;
			break;
		}
	}
}