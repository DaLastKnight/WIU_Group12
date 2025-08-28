#include <conio.h>
#include "Position.h"
#include "Buildings.h"
#include "Game.h"

Buildings::Buildings(Game* gamePtr)
{
    buildingTier = 0;
    woodPrice = 0;
    stonePrice = 0;
    buildingName = "";
    buffDescription = "";
    tileSymbol = '?';
    isBuildingUpgraded = false;
    woodPtr = gamePtr->getWoodPtr();
    stonePtr = gamePtr->getStonePtr();
}

Buildings::~Buildings()
{

}

void Buildings::repairMenu()
{
    int currentSelection = 0;
    char keyInput = '-';
    const int numOptions = 2; // Total number of menu options

    while (true) {

        system("cls");

        std::cout << "\nYou need " << woodPrice << " wood & " << stonePrice << " stone to repair this building \n";

        std::cout << "\nYou currently have " << woodPtr->getMaterialAmount() << " wood & " << stonePtr->getMaterialAmount() << " stone.\n";

        std::cout << "\nProceed to repair?\n";

        // Print menu options with highlighting based on currentSelection
        std::cout << ((currentSelection == 0) ? "> " : "  ") << "Yes\n";
        std::cout << ((currentSelection == 1) ? "> " : "  ") << "No\n";

        std::cout << "\nUse W/S to navigate, Z to select, X to exit.\n";

        // Use _getch() to get instant input without pressing Enter
        keyInput = _getch();

        switch (keyInput) {
        case 72:
            currentSelection = (currentSelection > 0) ? currentSelection - 1 : numOptions - 1;
            system("cls");
            break;
        case 80:
            currentSelection = (currentSelection < numOptions - 1) ? currentSelection + 1 : 0;
            system("cls");
            break;
        case 90:
        case 122:
            // Handle the action for the selected option
            switch (currentSelection) {
            case 0:
                if (woodPtr->getMaterialAmount() < woodPrice || stonePtr->getMaterialAmount() < stonePrice)
                {
                    std::cout << "You don't have enough materials!" << '\n';
                }
                else
                {
                    if (buildingName == "Hospital")
                    {
                        tileSymbol = 'H';
                    }
                    else if (buildingName == "Blacksmith")
                    {
                        tileSymbol = 'B';
                    }
                    else if (buildingName == "Armory")
                    {
                        tileSymbol = 'A';
                    }
                    else if (buildingName == "Bakery")
                    {
                        tileSymbol = 'B';
                    }

                    woodPtr->setMaterialAmount(woodPtr->getMaterialAmount() - woodPrice);
                    stonePtr->setMaterialAmount(stonePtr->getMaterialAmount() - stonePrice);
                    isBuildingUpgraded = true;
                    buildingTier++;
                }
                return;
                break;
            case 1:
                return;
                break;
            default:
                break;
            }
            break;
        case 88:
        case 120:
            return; // Exit the function to leave the shop
        default:
            // Ignore invalid key presses
            system("cls");
            break;
        }
    }
}

void Buildings::showBuildingInfo()
{
    char keyInput = '-';

    while (true)
    {
        system("cls");

        printBuilding();
        if (!isBuildingUpgraded)
        {
            std::cout << "\nThis building is too rundown to be able to see its information...\n";
        }
        else
        {
            std::cout << "\nBuilding name: " << buildingName << '\n';
            std::cout << "\nRestoration buff: " << buffDescription << '\n';
        }

        std::cout << "\nUse X to exit.\n";

        keyInput = _getch();

        switch (keyInput) {
        case 'x':
        case 'X':
            return;
            break;
        }
    }
}

void Buildings::interactBuilding()
{
    int currentSelection = 0;
    char keyInput = '-';
    const int numOptions = 3; // Total number of menu options

    while (true) {

        system("cls");

        printBuilding();

        if (isBuildingUpgraded)
        {
            std::cout << "\nIn front of you lies a " << buildingName << " fully upgraded!\n";
        }
        else
        {
            std::cout << "\nIn front of you lies a rundown building...\n";
        }

        std::cout << "\nWhat would you like to do?\n";

        // Print menu options with highlighting based on currentSelection
        std::cout << ((currentSelection == 0) ? "> " : "  ") << "Repair\n";
        std::cout << ((currentSelection == 1) ? "> " : "  ") << "Info\n";
        std::cout << ((currentSelection == 2) ? "> " : "  ") << "Leave\n";

        std::cout << "\nUse Arrow Keys to navigate, Z to select, X to exit.\n";

        // Use _getch() to get instant input without pressing Enter
        keyInput = _getch();

        switch (keyInput) {
        case 72:
            currentSelection = (currentSelection > 0) ? currentSelection - 1 : numOptions - 1;
            system("cls");
            break;
        case 80:
            currentSelection = (currentSelection < numOptions - 1) ? currentSelection + 1 : 0;
            system("cls");
            break;
        case 90:
        case 122:
            // Handle the action for the selected option
            switch (currentSelection) {
            case 0:
                if (!isBuildingUpgraded)
                {
                    repairMenu();
                }
                break;
            case 1:
                showBuildingInfo();
                break;
            case 2:
                return;
                break;
            default:
                break;
            }
            break;
        case 88:
        case 120:
            return; // Exit the function to leave the shop
        default:
            // Ignore invalid key presses
            system("cls");
            break;
        }
    }
}

Position Buildings::getPosition() const
{
    return position;
}

char Buildings::getTileSymbol() const
{
    return tileSymbol;
}