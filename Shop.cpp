#include "Shop.h"
#include <random>
#include <iostream>
#include <conio.h>
#include <cstdlib>
#include "Gold.h"
#include "Weapons.h"
#include "Sword.h"
#include "Dagger.h"
#include "Bow.h"
#include "Armor.h"
#include "HeavyArmor.h"
#include "LightArmor.h"
#include "HealthPotions.h"
#include "Rope.h"

Shop::Shop(Gold* goldPtr)
{
    for (int i = 0; i < 3; i++)
    {
        isWeaponBought[i] = false;
    }

    for (int i = 0; i < 3; i++)
    {
        isArmorBought[i] = false;
    }

    for (int i = 0; i < 2; i++)
    {
        isPotionBought[i] = false;
    }

    for (int i = 0; i < 2; i++)
    {
        isMiscellaneousItemBought[i] = false;
    }

    this->goldPtr = goldPtr;
    int randomNumber = 0;
    std::mt19937 generator(std::random_device{}());
    std::uniform_int_distribution<int> distr(1, 3);
    std::uniform_int_distribution<int> distrA(1, 2);

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
            randomNumber = distr(generator);
            weaponList[i] = new Dagger(randomNumber);
            break;
        case 3:
            randomNumber = distr(generator);
            weaponList[i] = new Bow(randomNumber);
            break;
        default:
            weaponList[i] = nullptr;
            break;
        }
    }

    // Repeat the above for the other different arrays of items
    for (int i = 0; i < 3; i++)
    {
        randomNumber = distrA(generator);

        switch (randomNumber)
        {
        case 1:
            randomNumber = distr(generator);
            armorList[i] = new LightArmor(randomNumber);
            break;
        case 2:
            randomNumber = distr(generator);
            armorList[i] = new HeavyArmor(randomNumber);
            break;
        default:
            armorList[i] = nullptr;
            break;
        }
    }

    for (int i = 0; i < 2; i++)
    {
        potionList[i] = new HealthPotions(1);
        itemList[i] = new Rope(1);
    }
}

Shop::~Shop()
{
    for (int i = 0; i < 3; i++)
    {
        delete weaponList[i];
        delete armorList[i];
    }
    //
    // Repeat for the other different arrays of items
    // 
    for (int i = 0; i < 2; i++)
    {
        delete potionList[i];
        delete itemList[i];
    }

    delete goldPtr;
}

void Shop::handlePurchase(Weapons* weaponPtr, bool& weaponIsBought)
{
    int currentSelection = 0;
    char keyInput = '-';
    const int numOptions = 2; // For Yes and No options

    while (true) {
        system("cls"); // Clear the screen at the start of the loop

        std::cout << "\nWould you like to buy a Tier " << weaponPtr->getTier() << " " << weaponPtr->getName() << " for " << weaponPtr->getPrice() << "G?" << '\n';

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
                if (goldPtr->getTotalGold() < weaponPtr->getPrice())
                {
                    weaponIsBought = false;
                    std::cout << "\nYou have insufficient gold!\n";
                    return;
                }
                else
                {
                    system("cls");
                    goldPtr->setTotalGold(goldPtr->getTotalGold() - weaponPtr->getPrice());
                    weaponIsBought = true;
                    std::cout << "\nYou have bought a " << weaponPtr->getName() << "!\n";
                    std::cout << "Returning to shop menu...\n";
                    return; // Return to the showChoices() loop
                }
            }
            else { // No
                system("cls");
                std::cout << "Returning to shop menu...\n";
                return;
            }
            break;
        case 'x':
            system("cls");
            return; // Immediately return to the showChoices() loop
            break;
        default:
            break; // Ignore invalid keys
        }
    }
}

void Shop::handlePurchase(Armor* armorPtr, bool& armorIsBought)
{
    int currentSelection = 0;
    char keyInput = '-';
    const int numOptions = 2; // For Yes and No options

    while (true) {
        system("cls"); // Clear the screen at the start of the loop

        std::cout << "\nWould you like to buy a Tier " << armorPtr->getTier() << " " << armorPtr->getName() << " for " << armorPtr->getPrice() << "G?" << '\n';

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
                if (goldPtr->getTotalGold() < armorPtr->getPrice())
                {
					armorIsBought = false;
                    std::cout << "\nYou have insufficient gold!\n";
                    return;
                }
                else
                {
                    system("cls");
                    goldPtr->setTotalGold(goldPtr->getTotalGold() - armorPtr->getPrice());
					armorIsBought = true;
                    std::cout << "\nYou have bought a " << armorPtr->getName() << "!\n";
                    std::cout << "Returning to shop menu...\n";
                    return; // Return to the showChoices() loop
                }
            }
            else { // No
                system("cls");
                std::cout << "Returning to shop menu...\n";
                return;
            }
            break;
        case 'x':
            system("cls");
            return; // Immediately return to the showChoices() loop
            break;
        default:
            break; // Ignore invalid keys
        }
    }
}

void Shop::handlePurchase(Potions* potionPtr, bool& potionIsBought)
{
    int currentSelection = 0;
    char keyInput = '-';
    const int numOptions = 2; // For Yes and No options

    while (true) {
        system("cls"); // Clear the screen at the start of the loop

        std::cout << "\nWould you like to buy a " << potionPtr->getName() << " for " << potionPtr->getPrice() << "G?" << '\n';

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
                if (goldPtr->getTotalGold() < potionPtr->getPrice())
                {
                    potionIsBought = false;
                    std::cout << "\nYou have insufficient gold!\n";
                    return;
                }
                else
                {
                    system("cls");
                    goldPtr->setTotalGold(goldPtr->getTotalGold() - potionPtr->getPrice());
                    potionIsBought = true;
                    std::cout << "\nYou have bought a " << potionPtr->getName() << "!\n";
                    std::cout << "Returning to shop menu...\n";
                    return; // Return to the showChoices() loop
                }
            }
            else { // No
                system("cls");
                std::cout << "Returning to shop menu...\n";
                return;
            }
            break;
        case 'x':
            system("cls");
            return; // Immediately return to the showChoices() loop
            break;
        default:
            break; // Ignore invalid keys
        }
    }
}

void Shop::handlePurchase(Items* itemPtr, bool& itemIsBought)
{
    int currentSelection = 0;
    char keyInput = '-';
    const int numOptions = 2; // For Yes and No options

    while (true) {
        system("cls"); // Clear the screen at the start of the loop

        std::cout << "\nWould you like to buy a " << itemPtr->getName() << " for " << itemPtr->getPrice() << "G?" << '\n';

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
                if (goldPtr->getTotalGold() < itemPtr->getPrice())
                {
                    itemIsBought = false;
                    std::cout << "\nYou have insufficient gold!\n";
                    return;
                }
                else
                {
                    system("cls");
                    goldPtr->setTotalGold(goldPtr->getTotalGold() - itemPtr->getPrice());
                    itemIsBought = true;
                    std::cout << "\nYou have bought a " << itemPtr->getName() << "!\n";
                    std::cout << "Returning to shop menu...\n";
                    return; // Return to the showChoices() loop
                }
            }
            else { // No
                system("cls");
                std::cout << "Returning to shop menu...\n";
                return;
            }
            break;
        case 'x':
            system("cls");
            return; // Immediately return to the showChoices() loop
            break;
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
    const int numOptions1 = 2; // For Potion and Rope shop

    if (itemType == "Weapon") {
        while (true)
        {
            system("cls");
            std::cout << "Weapons on sale:\n";

            for (int i = 0; i < 3; i++)
            {
                if (isWeaponBought[i])
                {
                    std::cout << ((currentSelection == i) ? "> " : "  ") << "Sold!" << '\n';
                }
                else
                {
                    std::cout << ((currentSelection == i) ? "> " : "  ") << weaponList[i]->getName() << " Tier " << weaponList[i]->getTier() << '\n';
                    weaponList[i]->weaponSprite(weaponList[i]->getTier());
                }
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
                if (!isWeaponBought[currentSelection])
                {
                    handlePurchase(weaponList[currentSelection], isWeaponBought[currentSelection]);
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
    else if (itemType == "Armor") {
        while (true)
        {
            system("cls");
            std::cout << "Armor on sale:\n";

            for (int i = 0; i < 3; i++)
            {
                if (isArmorBought[i])
                {
                    std::cout << ((currentSelection == i) ? "> " : "  ") << "Sold!" << '\n';
                }
                else
                {
                    std::cout << ((currentSelection == i) ? "> " : "  ") << armorList[i]->getName() << " Tier " << armorList[i]->getTier() << '\n';
                    armorList[i]->armorSprite(armorList[i]->getTier());
                }
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
                if (!isArmorBought[currentSelection])
                {
                    handlePurchase(armorList[currentSelection], isArmorBought[currentSelection]);
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
    else if (itemType == "Potion") {
        while (true)
        {
            system("cls");
            std::cout << "Potions on sale:\n";

            for (int i = 0; i < 2; i++)
            {
                if (isPotionBought[i])
                {
                    std::cout << ((currentSelection == i) ? "> " : "  ") << "Sold!" << '\n';
                }
                else
                {
                    std::cout << ((currentSelection == i) ? "> " : "  ") << potionList[i]->getName() << '\n';
                    potionList[i]->itemSprite();
                }
            }

            std::cout << "\nCurrent amount of gold: " << goldPtr->getTotalGold() << '\n';

            std::cout << "\nUse W/S to navigate, Z to select, X to exit.\n";

            keyInput = _getch();

            switch (keyInput) {
            case 'w':
                currentSelection = (currentSelection > 0) ? currentSelection - 1 : numOptions1 - 1;
                system("cls");
                break;
            case 's':
                currentSelection = (currentSelection < numOptions1 - 1) ? currentSelection + 1 : 0;
                system("cls");
                break;
            case 'z':
                // Handle the action for the selected option
                if (!isPotionBought[currentSelection])
                {
                    handlePurchase(potionList[currentSelection], isPotionBought[currentSelection]);
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
    else if (itemType == "Miscellaneous") {
        while (true)
        {
            system("cls");
            std::cout << "Miscellaneous Items on sale:\n";

            for (int i = 0; i < 2; i++)
            {
                if (isMiscellaneousItemBought[i])
                {
                    std::cout << ((currentSelection == i) ? "> " : "  ") << "Sold!" << '\n';
                }
                else
                {
                    std::cout << ((currentSelection == i) ? "> " : "  ") << itemList[i]->getName() << '\n';
                    itemList[i]->itemSprite();
                }
            }

            std::cout << "\nCurrent amount of gold: " << goldPtr->getTotalGold() << '\n';

            std::cout << "\nUse W/S to navigate, Z to select, X to exit.\n";

            keyInput = _getch();

            switch (keyInput) {
            case 'w':
                currentSelection = (currentSelection > 0) ? currentSelection - 1 : numOptions1 - 1;
                system("cls");
                break;
            case 's':
                currentSelection = (currentSelection < numOptions1 - 1) ? currentSelection + 1 : 0;
                system("cls");
                break;
            case 'z':
                // Handle the action for the selected option
                if (!isMiscellaneousItemBought[currentSelection])
                {
                    handlePurchase(itemList[currentSelection], isMiscellaneousItemBought[currentSelection]);
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
}

void Shop::interactShop()
{
    int currentSelection = 0;
    char keyInput = '-';
    const int numOptions = 5; // Total number of menu options

    while (true) {

        system("cls");

        std::cout << "      . .                     \n";
        std::cout << "        .:                    \n";
        std::cout << "       __[]_________          \n";
        std::cout << "      /\\____________\\       \n";
        std::cout << "      ||   |Shop|   |         \n";
        std::cout << "      ||     __     |         \n";
        std::cout << "      || '' | .| '' |         \n";
        std::cout << "      ||    |  |    |         \n";
        std::cout << "    `'``````''`````''``       \n";

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
                showChoices("Weapon");
                break;
            case 1:
                showChoices("Armor");
                break;
            case 2:
                showChoices("Potion");
                break;
            case 3:
                showChoices("Miscellaneous");
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