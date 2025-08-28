#include "Game.h"
#include "Battle.h"
#include "Tile.h"
#include "PlayerTile.h"
#include "Player.h"
#include "Enemy.h"
#include "Difficultyselection.h"
#include <iostream>
#include <Windows.h> 
#include <conio.h>
#include <ctype.h>
#include <cstdlib>
#include <random>

#include "Goblin.h"
#include "Slime.h"
#include "Wolf.h"

Battle::Battle(Game* ptrGame, Player* player)
{
	gamePtr = ptrGame;
	diffPtr = gamePtr->getDifficultySelector();
	playerPtr = player;
	woodPtr = gamePtr->getWoodPtr();
	stonePtr = gamePtr->getStonePtr();
	goldPtr = gamePtr->getGoldPtr();
	playerTilePtr = nullptr;
	worldType = "Battle";
	gridWidth = 5;
	gridHeight = 28;
	world = new char* [gridWidth];
	battleActive = true;
	defending = false;
	useSkill = false;

	for (int i = 0; i < 3; i++) {
		eType[i] = gamePtr->getEnemyGrade();
	}

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

	maxTiles = 3;
	tileList = new Tile * [maxTiles];

	for (int i = 0; i < maxTiles; i++)
	{
		tileList[i] = nullptr;
		enemyAlive[i] = true;
	}
}

Battle::~Battle()
{
	for (int i = 0; i < gridWidth; i++)
	{
		delete[] world[i];
	}
	delete[] world;

	for (int i = 0; i < maxTiles; i++)
	{
		delete tileList[i];
	}
	delete[] tileList;

	gamePtr = nullptr;

	for (int i = 0; i < 3; i++) {
		delete eType[i];
	}
}

void Battle::printWorld()
{
	system("cls");

	// This print only works if gridWidth = gridHeight! For others, please override this function
	std::cout << "Currently in: " << worldType;
	if (worldType == "Dungeon")
	{
		std::cout << '\n';
	}
	else if (worldType == "Battle")
	{
		std::cout << '\n';
	}
	else
	{
		std::cout << '\n';
	}

	std::cout << '+';
	for (int i = 0; i < gridWidth - 1; i++)
	{
		std::cout << "-------" << "------";
	}
	std::cout << "---" << '+' << '\n';

	for (int i = 0; i < gridWidth; i++)
	{
		for (int j = 0; j < gridHeight; j++)
		{
			switch (j)
			{
			case 0:
				std::cout << '|' << world[i][j];
				break;
			default:
				std::cout << ' ' << world[i][j];
				break;
			}
		}
		std::cout << '|' << '\n';
	}

	std::cout << '+';
	for (int i = 0; i < gridWidth - 1; i++)
	{
		std::cout << "-------" << "------";
	}
	std::cout << "---" << '+' << '\n';
}

void Battle::checkInteraction()
{

}

bool Battle::confirmSelection()
{
	int currentSelection = 0;
	char keyInput;
	const int numOptions = 2; // For Yes and No options

	while (true)
	{
		system("cls"); // Clear the screen

		std::cout << "\nDo you want to do this?\n";

		// Print menu options with highlighting
		std::cout << ((currentSelection == 0) ? "> " : "  ") << "Yes\n";
		std::cout << ((currentSelection == 1) ? "> " : "  ") << "No\n";

		std::cout << "\nUse W/S to navigate, Z to select, X to go back.\n";

		keyInput = _getch();

		switch (keyInput)
		{
		case 72:
			currentSelection = (currentSelection > 0) ? currentSelection - 1 : numOptions - 1;
			break;
		case 80:
			currentSelection = (currentSelection < numOptions - 1) ? currentSelection + 1 : 0;
			break;
		case 90:
		case 122:
			if (currentSelection == 0) { // Yes
				return true;
			}
			else { // No
				return false;
			}
		case 88:
		case 120:
			return false; // Return false to go back to the previous menu
		default:
			break; // Ignore invalid keys
		}
	}
}

void Battle::initWorld()
{
	int randomNumber = 0;
	std::mt19937 generator(std::random_device{}());
	std::uniform_int_distribution<int> distr(0, 2);

	for (int i = 0; i < maxTiles; i++)
	{
		randomNumber = distr(generator);

		if (randomNumber == 0) {
			eType[i] = new Goblin(diffPtr->getDifficultyGrade());
			eType[i]->setEnemyGrade();
		}
		else if (randomNumber == 1) {
			eType[i] = new Slime(diffPtr->getDifficultyGrade());
			eType[i]->setEnemyGrade();
		}
		else if (randomNumber == 2) {
			eType[i] = new Wolf(diffPtr->getDifficultyGrade());
			eType[i]->setEnemyGrade();
		}

		switch (i)
		{
		case 0:
			tileList[i] = new Tile(eType[i]->getType()); // Enemy
			tileList[i]->setTilePosition(gridWidth, gridHeight, 0, 17);
			break;
		case 1:
			tileList[i] = new Tile(eType[i]->getType()); // Enemy
			tileList[i]->setTilePosition(gridWidth, gridHeight, 2, 17);
			break;
		case 2:
			tileList[i] = new Tile(eType[i]->getType()); // Enemy
			tileList[i]->setTilePosition(gridWidth, gridHeight, 4, 17);
			break;
		//case 3:
		//case 4:
		//case 5:
		//case 6:
		//	break;
		default:
			break;
		}
	}
	playerTilePtr = new PlayerTile;
	playerTilePtr->setTilePosition(gridWidth, gridHeight, 2, 10);

}


void Battle::updateTilePositions()
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

void Battle::loopWorld()
{
	initWorld();

	while (battleActive)
	{
		updateTilePositions();
		printWorld();
		battleMenu();

		int randomNumber = 0;
		std::mt19937 generator(std::random_device{}());
		std::uniform_int_distribution<int> normal(1, 10);
		std::uniform_int_distribution<int> elite(11, 20);
		std::uniform_int_distribution<int> boss(30, 50);

		for (int i = 0; i < maxTiles; i++) {
			if (eType[i] && eType[i]->getHealth() <= 0) {
				if (eType[i]->getEnemyGrade() == 'N') {

					for (int i = 0; i < 3; i++) {
						randomNumber = normal(generator);
						switch (i) {
						case 0:
							goldPtr->setTotalGold(goldPtr->getTotalGold() + normal(generator));
							break;
						case 1:
							woodPtr->setMaterialAmount(woodPtr->getMaterialAmount() + normal(generator));
							break;
						case 2:
							stonePtr->setMaterialAmount(stonePtr->getMaterialAmount() + normal(generator));
							break;
						}
					}
				}
				else if (eType[i]->getEnemyGrade() == 'E') {
					for (int i = 0; i < 3; i++) {
						randomNumber = elite(generator);
						switch (i) {
						case 0:
							goldPtr->setTotalGold(goldPtr->getTotalGold() + elite(generator));
							break;
						case 1:
							woodPtr->setMaterialAmount(woodPtr->getMaterialAmount() + elite(generator));
							break;
						case 2:
							stonePtr->setMaterialAmount(stonePtr->getMaterialAmount() + elite(generator));
							break;
						}
					}
				}
				else if (eType[i]->getEnemyGrade() == 'B') {
					for (int i = 0; i < 3; i++) {
						randomNumber = boss(generator);
						switch (i) {
						case 0:
							goldPtr->setTotalGold(goldPtr->getTotalGold() + boss(generator));
							break;
						case 1:
							woodPtr->setMaterialAmount(woodPtr->getMaterialAmount() + boss(generator));
							break;
						case 2:
							stonePtr->setMaterialAmount(stonePtr->getMaterialAmount() + boss(generator));
							break;
						}
					}
				}

				delete eType[i];
				eType[i] = nullptr;

				delete tileList[i];
				tileList[i] = nullptr;
				enemyAlive[i] = false;
			}
		}

		if (!enemyAlive[0] && !enemyAlive[1] && !enemyAlive[2]) {
			std::cout << "You win!\n";
			battleActive = false;
		}

		for (int i = 0; i < 3; i++) {
			if (eType[i]) {
				if (defending) {
					playerPtr->defending(eType[i]);
				}
				else {
					eType[i]->attacking(playerPtr);
				}
			}
		}
		defending = false;
		useSkill = false;

		if (playerPtr->getHealth() <= 0) {
			std::cout << "You lose...\n";
			battleActive = false;
		}
	}
	return;
}

void Battle::battleMenu()
{
	int currentSelectionCol = 0;
	int currentSelectionRow = 0;
	char keyInput;
	const int numOptions = 2; // Total number of menu options

	while (true) {

		std::cout << "\It's your turn. \n";
		std::cout << "\nWhat are you going to do?\n";

		// Print menu options with highlighting

		HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);

		printWorld();

		std::cout << "|                                                       |\n";
		std::cout << "|                                                       |\n";
		std::cout << "|          |----------|          |----------|           |\n";
		std::cout << "|        " << ((currentSelectionCol == 0 && currentSelectionRow == 0) ? "> |" : "  |") << "  ";
		SetConsoleTextAttribute(h, 4);
		std::cout << "Attack";
		SetConsoleTextAttribute(h, 7);
		std::cout << "  |        " << ((currentSelectionCol == 0 && currentSelectionRow == 1) ? "> |" : "  |") << "  ";

		SetConsoleTextAttribute(h, 3);
		std::cout << "Skill";
		SetConsoleTextAttribute(h, 7);
		std::cout << "   |           |\n";

		std::cout << "|          |----------|          |----------|           |\n";
		std::cout << "|                                                       |\n";

		std::cout << "|          |----------|          |----------|           |\n";
		std::cout << "|        " << ((currentSelectionCol == 1 && currentSelectionRow == 0) ? "> |" : "  |") << "  ";
		SetConsoleTextAttribute(h, 2);
		std::cout << "Items";
		SetConsoleTextAttribute(h, 7);
		std::cout << "   |        " << ((currentSelectionCol == 1 && currentSelectionRow == 1) ? "> |" : "  |") << "  ";

		SetConsoleTextAttribute(h, 6);
		std::cout << "Defend";
		SetConsoleTextAttribute(h, 7);
		std::cout << "  |           |\n";

		std::cout << "|          |----------|          |----------|           |\n";
		std::cout << "|                                                       |\n";
		std::cout << "|                                                       |\n";
		std::cout << "+-------------------------------------------------------+\n";

		std::cout << "\nUse Arrow Keys to navigate, Z to select.\n";

		keyInput = _getch();

		switch (keyInput) {
		case 72:
			currentSelectionCol = (currentSelectionCol > 0) ? currentSelectionCol - 1 : numOptions - 1;
			break;
		case 80:
			currentSelectionCol = (currentSelectionCol < numOptions - 1) ? currentSelectionCol + 1 : 0;
			break;
		case 75:
			currentSelectionRow = (currentSelectionRow > 0) ? currentSelectionRow - 1 : numOptions - 1;
			break;
		case 77:
			currentSelectionRow = (currentSelectionRow < numOptions - 1) ? currentSelectionRow + 1 : 0;
			break;

		case 90:
		case 122:
			if (currentSelectionRow == 0 && currentSelectionCol == 0) {
				std::cout << "You attacked";
				if (enemySelect()) {
					return;
				}
			}
			else if (currentSelectionRow == 0 && currentSelectionCol == 1) {
				std::cout << "You went into inventory";
				return;
			}
			else if (currentSelectionRow == 1 && currentSelectionCol == 0) {
				std::cout << "You are using skill";
				useSkill = true;
				/*if (pc->getName() == "Cleric") {
					return;
				}*/
				if (enemySelect()) {
					return;
				}
			}
			else if (currentSelectionRow == 1 && currentSelectionCol == 1) {
				std::cout << "You are defending. Why?";
				defending = true;
				return;
			}
		default:
			break; // Ignore invalid key presses
		}
	}
}


bool Battle::enemySelect()
{
	int currentSelection = 0;
	char keyInput;
	const int numOptions = 3; // Total number of menu options

	while (true) {

		std::cout << "\nWho you gonna target?\n";

		// Print menu options with highlighting

		HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);

		printWorld();

		std::cout << "|                                                       |\n";
		std::cout << "|                                                       |\n";
		std::cout << "|      |-----|          |-----|           |-----|       |\n";

		std::cout << "|    " << ((currentSelection == 0) ? "> |" : "  |") << "  ";

		SetConsoleTextAttribute(h, 3);
		if (enemyAlive[0]) {
			std::cout << tileList[0]->getTileSymbol();
		}
		else {
			std::cout << " ";
		}
		SetConsoleTextAttribute(h, 7);

		std::cout << "  |        " << ((currentSelection == 1) ? "> |" : "  |") << "  ";

		SetConsoleTextAttribute(h, 3);
		if (enemyAlive[1]) {
			std::cout << tileList[1]->getTileSymbol();
		}
		else {
			std::cout << " ";
		}
		SetConsoleTextAttribute(h, 7);

		std::cout << "  |         " << ((currentSelection == 2) ? "> |" : "  |") << "  ";

		SetConsoleTextAttribute(h, 3);
		if (enemyAlive[2]) {
			std::cout << tileList[2]->getTileSymbol();
		}
		else {
			std::cout << " ";
		}
		SetConsoleTextAttribute(h, 7);
		std::cout << "  |       |\n";

		std::cout << "|      |-----|          |-----|           |-----|       |\n";
		std::cout << "|                                                       |\n";
		std::cout << "|                                                       |\n";
		std::cout << "+-------------------------------------------------------+\n";

		std::cout << "\nUse Arrow Keys to navigate, Z to select, X to go back.\n";
		std::cout << "Enemy Stats: \n";
		if (enemyAlive[currentSelection]) {
			std::cout << "HP: " << eType[currentSelection]->getHealth() << std::endl;
			std::cout << "ATK: " << eType[currentSelection]->getAttack() << std::endl;
			std::cout << "DEF: " << eType[currentSelection]->getDefense() << std::endl;
			std::cout << "SPD: " << eType[currentSelection]->getSpeed() << std::endl;
		}
		else {
			std::cout << "He dead\n";
		}
		std::cout << "\n";
		std::cout << "Your Stats: \n";
		std::cout << "HP: " << playerPtr->getHealth() << std::endl;
		std::cout << "ATK: " << playerPtr->getAttack() << std::endl;
		std::cout << "DEF: " << playerPtr->getDefense() << std::endl;
		std::cout << "SPD: " << playerPtr->getSpeed() << std::endl;

		keyInput = _getch();

		switch (keyInput) {
		case 75:
			currentSelection = (currentSelection > 0) ? currentSelection - 1 : numOptions - 1;
			break;
		case 77:
			currentSelection = (currentSelection < numOptions - 1) ? currentSelection + 1 : 0;
			break;
		case 90:
		case 122:
		if (confirmSelection() && enemyAlive[currentSelection]) {
			if (useSkill) {
				playerPtr->useSkill(eType[currentSelection]);
			}
			else {
				playerPtr->attacking(eType[currentSelection]);
			}
			return true;
		}
		else {
			std::cout << "IT'S ALREADY DEAD STOP!!!\n";
			break;
		}
		break;
		case 88:
		case 120:
			return false;
		default:
			break; // Ignore invalid key presses
		}
	}
}