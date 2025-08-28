#include <iostream>
#include "Player.h"
#include "Equipments.h"
#include "Weapons.h"
#include "Armor.h"
#include "Sword.h"
#include "Bow.h"
#include "Dagger.h"
#include "LightArmor.h"
#include "HeavyArmor.h"

#include <Windows.h> 
#include <conio.h>
#include <ctype.h>
#include <cstdlib>

Player::Player()
{
	specialty = nullptr;
	equippedWeaponPtr = nullptr;
	equippedArmorPtr = nullptr;

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

		std::cout << "\nUse Arrow keys to navigate, Z to select, X to go back.\n";

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

void Player::equipEquipment(Equipments* equipmentPtr)
{
	if (equipmentPtr != nullptr)
	{
		if (equipmentPtr->getType() == "WEAPON")
		{
			if (equipmentPtr->getName() == "Sword")
			{
				equippedWeaponPtr = new Sword(equipmentPtr->getTier());
			}
			else if (equipmentPtr->getName() == "Dagger")
			{
				equippedWeaponPtr = new Dagger(equipmentPtr->getTier());
			}
			else if (equipmentPtr->getName() == "Bow")
			{
				equippedWeaponPtr = new Bow(equipmentPtr->getTier());
			}
		}
		else if (equipmentPtr->getType() == "ARMOR")
		{
			if (equipmentPtr->getName() == "LightArmor")
			{
				equippedArmorPtr = new LightArmor(equipmentPtr->getTier());
			}
			else if (equipmentPtr->getName() == "HeavyArmor")
			{
				equippedArmorPtr = new HeavyArmor(equipmentPtr->getTier());
			}
		}
	}
}

void Player::unequipEquipment(Equipments* equipmentPtr)
{
	if (equipmentPtr != nullptr)
	{
		if (equipmentPtr->getType() == "WEAPON")
		{
			if (equippedWeaponPtr != nullptr)
			{
				delete equippedWeaponPtr;
				equippedArmorPtr = nullptr;
			}
		}
		else if (equipmentPtr->getType() == "ARMOR")
		{
			if (equippedArmorPtr != nullptr)
			{
				delete equippedArmorPtr;
				equippedArmorPtr = nullptr;
			}
		}
	}
}

void Player::attacking()
{
	
}

//void Player::defending()
//{
//	int currentSelection = 0;
//	char keyInput;
//	const int numOptions = 2; // Total number of menu options
//
//	while (true) {
//		system("cls"); // Clear the screen at the start of the main loop
//
//		std::cout << "\nYou are Attacking!\n";
//		std::cout << "\nWhat are you going to do?\n";
//
//		// Print menu options with highlighting
//
//		HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
//
//		std::cout << "+-------------------------------------------------------+\n";
//		std::cout << "|                                                       |\n";
//		std::cout << "|                                                       |\n";
//		std::cout << "|          |----------|          |----------|           |\n";
//		std::cout << "|        " << ((currentSelection == 0) ? "> |" : "  |") << "  ";
//		SetConsoleTextAttribute(h, 3);
//		std::cout << "Block";
//		SetConsoleTextAttribute(h, 7);
//		std::cout << "   |        " << ((currentSelection == 1) ? "> |" : "  |") << "  ";
//
//		SetConsoleTextAttribute(h, 6);
//		std::cout << "Evade";
//		SetConsoleTextAttribute(h, 7);
//		std::cout << "   |           |\n";
//
//		std::cout << "|          |----------|          |----------|           |\n";
//		std::cout << "|                                                       |\n";
//		std::cout << "|                                                       |\n";
//		std::cout << "+-------------------------------------------------------+\n";
//
//		std::cout << "\nUse Arrow keys to navigate, Z to select. X to go back\n";
//
//		keyInput = _getch();
//
//		switch (keyInput) {
//		case 'w':
//			currentSelection = (currentSelection > 0) ? currentSelection - 1 : numOptions - 1;
//			break;
//		case 's':
//			currentSelection = (currentSelection < numOptions - 1) ? currentSelection + 1 : 0;
//			break;
//		case 'z':
//			switch (currentSelection) {
//			case 0:
//				system("cls");
//				std::cout << "\nYou chose to Block\n";
//				if (confirmSelection()) {
//					// Logic to do the said action
//
//					std::cout << "\nYou decided to block\n";
//					return; // Exit the function to start the game
//				}
//				break;
//			case 1:
//				system("cls");
//				std::cout << "\nYou chose to Evade\n";
//				if (confirmSelection()) {
//
//					std::cout << "\nYou attempted to Evade\n";
//					return;
//				}
//				break;
//			}
//		case 'x':
//			system("cls");
//			attacking();
//			return; // Exit the function immediately
//		default:
//			break; // Ignore invalid key presses
//		}
//	}
//}
