#include <iostream>
#include "Player.h"

#include <Windows.h> 
#include <conio.h>
#include <ctype.h>
#include <cstdlib>

Player::Player()
{
	specialty = nullptr;
	input = '-';
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
}

void Player::setClassStats(PlayerClass* playerclass)
{
	specialty = playerclass;
	playerclass->setClassStats(*this);
}

void Player::useSkill(PlayerClass* playerskill)
{
	specialty = playerskill;
	playerskill->skill(*this, playerskill->bonusValue());
}

void Player::attacking()
{
	int currentSelection = 0;
	char keyInput;
	const int numOptions = 4; // Total number of menu options

	while (true) {
		system("cls"); // Clear the screen at the start of the main loop

		std::cout << "\nYou are Attacking!\n";
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
					useSkill(specialty);
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

		std::cout << "\nYou are Attacking!\n";
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
