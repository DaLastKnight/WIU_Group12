#include "SelectClass.h"
#include "Player.h"
#include "Warrior.h"
#include "Rogue.h"
#include "Wizard.h"
#include "Cleric.h"
#include <iostream>

#include <conio.h>
#include <ctype.h>
#include <cstdlib>

bool SelectClass::confirmSelection() {
    int currentSelection = 0;
    char keyInput;
    const int numOptions = 2; // For Yes and No options

    while (true) {
        system("cls"); // Clear the screen

        std::cout << "\nConfirm selection?\n";

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

Player* SelectClass::getPlayer()
{
    return player;
}

// This is the main class selection menu, also using the new control scheme.
void SelectClass::chooseClass() {
    int currentSelection = 0;
    char keyInput;
    const int numOptions = 5; // Total number of menu options

    while (true) {
        system("cls"); // Clear the screen at the start of the main loop

        std::cout << "\nWelcome to the Classes Selection Building!\n";
        std::cout << "\nChoose your class:\n";

        // Print menu options with highlighting
        std::cout << ((currentSelection == 0) ? "> " : "  ") << "Warrior/Fighter\n";
        std::cout << ((currentSelection == 1) ? "> " : "  ") << "Thief/Rogue\n";
        std::cout << ((currentSelection == 2) ? "> " : "  ") << "Mage/Wizard\n";
        std::cout << ((currentSelection == 3) ? "> " : "  ") << "Cleric/Priest\n";
        std::cout << ((currentSelection == 4) ? "> " : "  ") << "Exit Building\n";

        std::cout << "\nUse W/S to navigate, Z to select, X to exit.\n";

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
                std::cout << "\nYou have chosen Warrior/Fighter.\n";
                std::cout << "Assigned stats: HP: 100, ATK: 25, DEF: 5, SPD: 12.\n";
                if (confirmSelection()) {
                    // Logic to save the selected class
                    delete player;
                    player = new Warrior();
                    player->setClassStats();
                    std::cout << "\nWarrior/Fighter has been selected. Starting your adventure...\n";
                    return; // Exit the function to start the game
                }
                break;
            case 1:
                system("cls");
                std::cout << "\nYou have chosen Thief/Rogue.\n";
                std::cout << "Assigned stats: HP: 80, ATK: 20, DEF: 3, SPD: 15.\n";
                if (confirmSelection()) {
                    delete player;
                    player = new Rogue();
                    player->setClassStats();
                    std::cout << "\nThief/Rogue has been selected. Starting your adventure...\n";
                    return;
                }
                break;
            case 2:
                system("cls");
                std::cout << "\nYou have chosen Mage/Wizard.\n";
                std::cout << "Assigned stats: HP: 50, ATK: 35, DEF: 2, SPD: 7.\n";
                if (confirmSelection()) {
                    delete player;
                    player = new Wizard();
                    player->setClassStats();
                    std::cout << "\nMage/Wizard has been selected. Starting your adventure...\n";
                    return;
                }
                break;
            case 3:
                system("cls");
                std::cout << "\nYou have chosen Cleric/Priest.\n";
                std::cout << "Assigned stats: HP: 65, ATK: 15, DEF: 7, SPD: 10.\n";
                if (confirmSelection()) {
                    delete player;
                    player = new Cleric();
                    player->setClassStats();
                    std::cout << "\nCleric/Priest has been selected. Starting your adventure..\n";
                    return;
                }
                break;
            case 4:
                std::cout << "Exiting class selection. You have not chosen a class.\n";
                return; // Exit the function
            }
            break;
        case 'x':
            system("cls");
            std::cout << "\nExiting class selection.\n";
            return; // Exit the function immediately
        default:
            break; // Ignore invalid key presses
        }
    }
}

