#include "Shop.h"
#include <iostream>
#include <conio.h>
#include <cstdlib>

void Shop::handlePurchase(const std::string& itemType)
{
    int currentSelection = 0;
    char keyInput;
    const int numOptions = 2; // For Yes and No options

    while (true) {
        system("cls"); // Clear the screen at the start of the loop

        std::cout << "\nWould you like to buy a Random " << itemType << "?\n";

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
                system("cls");
                std::cout << "\nYou have bought a random " << itemType << "!\n";
                std::cout << "Returning to shop menu...\n";
                return; // Return to the interactShop() loop
            }
            else { // No
                system("cls");
                std::cout << "Returning to shop menu...\n";
                return;
            }
        case 'x':
            system("cls");
            return; // Immediately return to the main shop loop
        default:
            break; // Ignore invalid keys
        }
    }
}

void Shop::interactShop()
{
    int currentSelection = 0;
    char keyInput;
    const int numOptions = 5; // Total number of menu options

    while (true) {

        std::cout << "\nWelcome to the General Shop!\n";
        std::cout << "\nWhat would you like to browse today?\n";

        // Print menu options with highlighting based on currentSelection
        std::cout << ((currentSelection == 0) ? "> " : "  ") << "Weapon\n";
        std::cout << ((currentSelection == 1) ? "> " : "  ") << "Armor\n";
        std::cout << ((currentSelection == 2) ? "> " : "  ") << "Potion\n";
        std::cout << ((currentSelection == 3) ? "> " : "  ") << "Miscellaneous\n";
        std::cout << ((currentSelection == 4) ? "> " : "  ") << "Exit Shop\n";

        std::cout << "\nUse W/S to navigate, Z to select, X to exit.\n";

        // Use _getch() to get instant input without pressing Enter
        keyInput = _getch();

        switch (keyInput) {
        case 'w':
            currentSelection = (currentSelection > 0) ? currentSelection - 1 : numOptions - 1;
            system("cls");
            break;
        case 's':
            currentSelection = (currentSelection < numOptions - 1) ? currentSelection + 1 : 0;
            system("cls");
            break;
        case 'z':
            // Handle the action for the selected option
            switch (currentSelection) {
            case 0:
                handlePurchase("Weapon");
                break;
            case 1:
                handlePurchase("Armor");
                break;
            case 2:
                handlePurchase("Potion");
                break;
            case 3:
                handlePurchase("Miscellaneous");
                break;
            case 4:
                std::cout << "\nThank you for visiting the shop! Goodbye!\n";
                return; // Exit the function to leave the shop
            }
            break;
        case 'x':
            std::cout << "\nThank you for visiting the shop! Goodbye!\n";
            return; // Exit the function to leave the shop
        default:
            // Ignore invalid key presses
			system("cls");
            break;
        }
    }
}