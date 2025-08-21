#include "Portal.h"
#include <iostream>
#include <conio.h>
#include <cstdlib>

Portal::Portal()
{
    hasTeleported = false;
}

char Portal::mainMenu(std::string& currentLocation)
{
    int currentSelection = 0;
    char keyInput;
    const int numOptions = 3;

    while (true) {


        std::cout << "You are in " << currentLocation << ".\n";
        std::cout << "Where would you like to teleport?\n\n";

        std::cout << ((currentSelection == 0) ? "> " : "  ") << "Go to Normal Dungeon\n";
        std::cout << ((currentSelection == 1) ? "> " : "  ") << "Go to Boss Dungeon\n";
        std::cout << ((currentSelection == 2) ? "> " : "  ") << "Go to Town\n";

        std::cout << "\nUse W/S to navigate, Z to select.\n";

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
            if (currentSelection == 0) { // Go to Normal Dungeon
                if (currentLocation == "Normal Dungeon") {
                    system("cls");
                    std::cout << "You are already in the Normal Dungeon!\n";
                }
                else {
                    //currentLocation = "Normal Dungeon";
                    system("cls");
                    std::cout << "Welcome to Normal Dungeon\n";
                    return 'N';
                }
            }
            else if (currentSelection == 1) { // Go to Boss Dungeon
                if (currentLocation == "Boss Dungeon") {
                    system("cls");
                    std::cout << "You are already in the Boss Dungeon!\n";
                }
                else {
                    //currentLocation = "Boss Dungeon";
                    system("cls");
                    std::cout << "Welcome to Boss Dungeon\n";
                    return 'B';
                }
            }
            else if (currentSelection == 2) { // Go to Town
                if (currentLocation == "Town") {
                    system("cls");
                    std::cout << "You are already in Town!\n";
                }
                else {
                    //currentLocation = "Town";
                    system("cls");
                    std::cout << "Welcome to Town\n";
                    return 'T';
                }
            }
            break;
        default:
			system("cls");
            break;
        }
    }
}

// The teleport function simply calls the unified menu
char Portal::teleport(std::string& currentLocation) {
   return mainMenu(currentLocation);
}