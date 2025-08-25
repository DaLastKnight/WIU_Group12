#include <iostream>
#include <conio.h>
#include <cstdlib>
#include <random>
#include "Gold.h"
#include "Shop.h"
#include "Weapons.h"
#include "Sword.h"
#include "Dagger.h"
#include "Bow.h"

Shop::Shop(Gold* goldPtr)
{
    this->goldPtr = goldPtr;
    int randomNumber = 0;
    std::mt19937 generator(std::random_device{}());
    std::uniform_int_distribution<int> distr(1, 3);
    
    for (int i = 0; i < 3; i++)
    {
          randomNumber = distr(generator);
     
          switch (randomNumber)
          {
          case 1:
              randomNumber = distr(generator);
              weaponList[i] = new Sword(randomNumber);
              break;
          case 2:
              weaponList[i] = new Dagger(randomNumber);
              break;
          case 3:
              weaponList[i] = new Bow(randomNumber);
              break;
          default:
              weaponList[i] = nullptr;
              break;
          }
    }
    
    // Repeat the above for the other different arrays of items
}

Shop::~Shop()
{
    for (int i = 0; i < 3; i++)
    {
        delete weaponList[i];
    }
    //
    // Repeat for the other different arrays of items
    // 
    delete goldPtr;
}

void Shop::handlePurchase(const std::string& itemType)
{
    int currentSelection = 0;
    char keyInput = '-';
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
            currentSelection = (currentSelection < numOptions - 1) ? currentSelection + 1 : 0; // When going below bottommost option, wraps around to the top
            break;
        case 'z':
            if (currentSelection == 0) { // Yes
                goldPtr->setTotalGold(-100);
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

void Shop::showChoices(const std::string& itemType)
{
    int currentSelection = 0;
    char keyInput = '-';
    const int numOptions = 3; // Total number of menu options

    while (true)
    {
        system("cls");
        std::cout << "Weapons on sale:\n";
        
        for (int i = 0; i < 3; i++)
        {
            std::cout << ((currentSelection == i) ? "> " : "  ") << weaponList[i]->getName() << " tier " << weaponList[i]->getTier() << '\n';
        }

        std::cout << "\nCurrent amount of gold: " << goldPtr->getTotalGold() << '\n';

        std::cout << "\nUse W/S to navigate, Z to select, X to exit.\n";

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
            }
            break;
        case 'x':
            return; // Exit the function to leave the shop
        default:
            // Ignore invalid key presses
            system("cls");
            break;
        }
    }
}

void Shop::interactShop()
{
    int currentSelection = 0;
    char keyInput = '-';
    const int numOptions = 5; // Total number of menu options

    while (true) {

        system("cls");
        
        std::cout << "\nWelcome to the General Shop!\n";
        std::cout << "\nWhat would you like to browse today?\n";

        // Print menu options with highlighting based on currentSelection
        std::cout << ((currentSelection == 0) ? "> " : "  ") << "Weapon\n";
        std::cout << ((currentSelection == 1) ? "> " : "  ") << "Armor\n";
        std::cout << ((currentSelection == 2) ? "> " : "  ") << "Potion\n";
        std::cout << ((currentSelection == 3) ? "> " : "  ") << "Miscellaneous\n";
        std::cout << ((currentSelection == 4) ? "> " : "  ") << "Exit Shop\n";

        std::cout << "\nCurrent amount of gold: " << goldPtr->getTotalGold() << '\n';

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
                showChoices("Weapon");
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