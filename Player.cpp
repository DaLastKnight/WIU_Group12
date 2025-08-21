#include <iostream>
#include "Player.h"

#include <Windows.h> 
#include <conio.h>
#include <ctype.h>
#include <cstdlib>

Player::Player()
{
}

bool Player::confirmSelection() {
	int currentSelection = 0;
	char keyInput;
	const int numOptions = 2; // For Yes and No options

	while (true) {
		system("cls"); // Clear the screen

		std::cout << "\nDo you want to do this?\n";

		// Print menu options with highlighting
		std::cout << ((currentSelection == 0) ? "> " : "  ") << "Yes\n";
		std::cout << ((currentSelection == 1) ? "> " : "  ") << "No\n";

		std::cout << "\nUse W/S to navigate, Z to select, X to go back.\n";

		keyInput = _getch();

		switch (keyInput) {
		case 'w':
			currentSelection = (currentSelection > 0) ? currentSelection - 1 : numOptions - 1;
			break;
		case 's':
			currentSelection = (currentSelection < numOptions - 1) ? currentSelection + 1 : 0;
			break;
		case 'z':
			if (currentSelection == 0) { // Yes
				return true;
			}
			else { // No
				return false;
			}
		case 'x':
			return false; // Return false to go back to the previous menu
		default:
			break; // Ignore invalid keys
		}
	}
}

void Player::viewCurrentStats()
{
	std::cout << "Health: " << getHealth() << "\n";
	std::cout << "Attack: " << getAttack() << "\n";
	std::cout << "Defense: " << getDefense() << "\n";
	std::cout << "Speed: " << getSpeed() << "\n";
	std::cout << "Row: " << pos.getRow() << "\n";
	std::cout << "Column: " << pos.getCol() << "\n";
}

void Player::move(char table[20][20])
{
	std::cout << "Enter WASD to move: ";
	std::cin >> input;

	// Gets the current Position
	int row = pos.getRow();
	int col = pos.getCol();
	// Sets the old Position info into the new one
	int newRow = row, newCol = col;

	// Moves according to the input
	switch (input) {
	case 'W':
		newRow--; break;
	case 'A':
		newCol--; break;
	case 'S':
		newRow++; break;
	case 'D':
		newCol++; break;
	default:
		std::cout << (input) << std::endl;
		std::cout << "Turn forfeited.\n";
		return;
	}

	std::cout << (input) << std::endl;

	// Checks if Player is going outside the map
	/*if (newRow < 0 || newRow >= 20 || newCol < 0 || newCol >= 20) {
		std::cout << "Turn forfeited.\n";
		return;
	}*/

	// Sets the new Position into the World
	char newPosition = table[newRow][newCol];

	// Checks which Entity it's colliding
	//for (int i = 1; i < 6; i++) {
	//    if (gameObjects[i] != nullptr) {
	//        // Get each Entities symbol to check
	//        char objType = gameObjects[i]->getType();

	//        // Checks if the Pacmans Position is the same with any other Entity
	//        if (gameObjects[i]->getPosition().getRow() == newRow && gameObjects[i]->getPosition().getCol() == newCol) {
	//            // Enter batttle function
	//        }
	//    }
	//}

	// Clears the old position
	table[row][col] = ' ';

	// Moves to the new Position
	pos.setRow(newRow);
	pos.setCol(newCol);
	table[newRow][newCol] = getType();
}

void Player::useSkill()
{
	std::cout << "You used a skill of whatever is called\n";
	skill(12);
}

void Player::attacking()
{
	int currentSelection = 0;
	char keyInput;
	const int numOptions = 4; // Total number of menu options

	while (true) {
		system("cls"); // Clear the screen at the start of the main loop

		std::cout << "\You are Attacking!\n";
		std::cout << "\nWhat are you going to do?\n";

		// Print menu options with highlighting

		HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);

		std::cout << "+-------------------------------------------------------+\n";
		std::cout << "|                                                       |\n";
		std::cout << "|                                                       |\n";
		std::cout << "|                                                       |\n";
		std::cout << "|                                                       |\n";
		std::cout << "|                                                       |\n";
		std::cout << "|                                                       |\n";
		std::cout << "|                                                       |\n";
		std::cout << "|                                                       |\n";
		std::cout << "|                                                       |\n";
		std::cout << "|                                                       |\n";
		std::cout << "+-------------------------------------------------------+\n";
		std::cout << "|                                                       |\n";
		std::cout << "|                                                       |\n";
		std::cout << "|          |----------|          |----------|           |\n";
		std::cout << "|        " << ((currentSelection == 0) ? "> |" : "  |") << "  ";
		SetConsoleTextAttribute(h, 4);
		std::cout << "Attack";
		SetConsoleTextAttribute(h, 7);
		std::cout << "  |        " << ((currentSelection == 1) ? "> |" : "  |") << "  ";

		SetConsoleTextAttribute(h, 3);
		std::cout << "Skill";
		SetConsoleTextAttribute(h, 7);
		std::cout << "   |           |\n";

		std::cout << "|          |----------|          |----------|           |\n";
		std::cout << "|                                                       |\n";

		std::cout << "|          |----------|          |----------|           |\n";
		std::cout << "|        " << ((currentSelection == 2) ? "> |" : "  |") << "  ";
		SetConsoleTextAttribute(h, 2);
		std::cout << "Items";
		SetConsoleTextAttribute(h, 7);
		std::cout << "   |        " << ((currentSelection == 3) ? "> |" : "  |") << "  ";

		SetConsoleTextAttribute(h, 6);
		std::cout << "Defend";
		SetConsoleTextAttribute(h, 7);
		std::cout << "  |           |\n";

		std::cout << "|          |----------|          |----------|           |\n";
		std::cout << "|                                                       |\n";
		std::cout << "|                                                       |\n";
		std::cout << "+-------------------------------------------------------+\n";

		std::cout << "\nUse W/S to navigate, Z to select.\n";

		keyInput = _getch();

		switch (keyInput) {
		case 'w':
			currentSelection = (currentSelection > 0) ? currentSelection - 1 : numOptions - 1;
			break;
		case 's':
			currentSelection = (currentSelection < numOptions - 1) ? currentSelection + 1 : 0;
			break;
		case 'z':
			switch (currentSelection) {
			case 0:
				system("cls");
				std::cout << "\nYou chose to Attack\n";
				if (confirmSelection()) {
					// Logic to do the said action

					std::cout << "\nYou attacked\n";
					return; // Exit the function to start the game
				}
				break;
			case 1:
				system("cls");
				std::cout << "\nYou chose to use Skill\n";
				if (confirmSelection()) {
					useSkill();
					std::cout << "\nYou skilled\n";
					return;
				}
				break;
			case 2:
				system("cls");
				std::cout << "\nYou chose to go into inventory\n";
				if (confirmSelection()) {

					std::cout << "\nYou looked into your bag\n";
					return;
				}
				break;
			case 3:
				system("cls");
				std::cout << "\nYou choose to defend\n";
				if (confirmSelection()) {
					defending();
					std::cout << "\nYou are defending\n";
					return;
				}
				break;
			}
		default:
			break; // Ignore invalid key presses
		}
	}
}

void Player::defending()
{
	int currentSelection = 0;
	char keyInput;
	const int numOptions = 2; // Total number of menu options

	while (true) {
		system("cls"); // Clear the screen at the start of the main loop

		std::cout << "\You are Attacking!\n";
		std::cout << "\nWhat are you going to do?\n";

		// Print menu options with highlighting

		HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);

		std::cout << "+-------------------------------------------------------+\n";
		std::cout << "|                                                       |\n";
		std::cout << "|                                                       |\n";
		std::cout << "|          |----------|          |----------|           |\n";
		std::cout << "|        " << ((currentSelection == 0) ? "> |" : "  |") << "  ";
		SetConsoleTextAttribute(h, 3);
		std::cout << "Block";
		SetConsoleTextAttribute(h, 7);
		std::cout << "   |        " << ((currentSelection == 1) ? "> |" : "  |") << "  ";

		SetConsoleTextAttribute(h, 6);
		std::cout << "Evade";
		SetConsoleTextAttribute(h, 7);
		std::cout << "   |           |\n";

		std::cout << "|          |----------|          |----------|           |\n";
		std::cout << "|                                                       |\n";
		std::cout << "|                                                       |\n";
		std::cout << "+-------------------------------------------------------+\n";

		std::cout << "\nUse W/S to navigate, Z to select. X to go back\n";

		keyInput = _getch();

		switch (keyInput) {
		case 'w':
			currentSelection = (currentSelection > 0) ? currentSelection - 1 : numOptions - 1;
			break;
		case 's':
			currentSelection = (currentSelection < numOptions - 1) ? currentSelection + 1 : 0;
			break;
		case 'z':
			switch (currentSelection) {
			case 0:
				system("cls");
				std::cout << "\nYou chose to Block\n";
				if (confirmSelection()) {
					// Logic to do the said action

					std::cout << "\nYou decided to block\n";
					return; // Exit the function to start the game
				}
				break;
			case 1:
				system("cls");
				std::cout << "\nYou chose to Evade\n";
				if (confirmSelection()) {

					std::cout << "\nYou attempted to Evade\n";
					return;
				}
				break;
			}
		case 'x':
			system("cls");
			attacking();
			return; // Exit the function immediately
		default:
			break; // Ignore invalid key presses
		}
	}
}
