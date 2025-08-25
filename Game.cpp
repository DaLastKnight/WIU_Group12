#include "Game.h"
#include "Gold.h"
#include "Town.h"
#include "Dungeon.h"

#include <Windows.h> 
#include <conio.h>
#include <ctype.h>
#include <cstdlib>

bool Game::confirmSelection() {
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
            break;
        case 'x':
            return false; // Return false to go back to the previous menu
        default:
            break; // Ignore invalid keys
        }
    }
}

Game::Game()
{
    currentSymbol = 'T';
    goldPtr = nullptr;
    currentWorld = nullptr;
    townPtr = nullptr;
	dungeonPtr = nullptr;
}

Game::~Game()
{
    delete goldPtr;
    delete currentWorld;
    delete townPtr;
    delete dungeonPtr;
}

void Game::initGame()
{
    goldPtr = new Gold(1000);
    townPtr = new Town(this);
    dungeonPtr = new Dungeon(this);
    townPtr->initWorld();
    dungeonPtr->initWorld();
}

void Game::startingScreen()
{
    int currentSelection = 0;
    char keyInput;
    const int numOptions = 2; // Total number of menu options

    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);

    while (true) {
        system("cls"); // Clear the screen at the start of the main loop

        std::cout << "+---------------------------------------------------------------------------------------------------------+\n";
        std::cout << "|  ______     ___      ___   ___       ___      _______   __________   ________     __          __        |\n";
        std::cout << "| |      \\    \\  \\    /  /   |  \\      | |     |   ____|  |  ______|  |   __   |   |  |        |  |       |\n";
        std::cout << "| |   _   \\    \\  \\  /  /    |   \\     | |     |  |       |  |        |  |  |  |   |  |        |  |       |\n";
        std::cout << "| |  | \\   |    \\  \\/  /     | |\\ \\    | |     |  |       |  |        |  |  |  |   |  |	       |  |       |\n";
        std::cout << "| |  |  |  |     \\    /      | | \\ \\   | |     |  |___    |  |___     |  |__|  |   |  |        |  |       |\n";
        std::cout << "| |  |  |  |      |  |       | |  \\ \\  | |     |   ___|   |   ___|    |   __   |   |  |	       |  |       |\n";
        std::cout << "| |  |  |  |      |  |       | |   \\ \\ | |     |  |       |  |        |  |  |  |   |  |        |  |       |\n";
        std::cout << "| |  |_/   |      |  |       | |    \\ \\| |     |  |       |  |        |  |  |  |   |  |        |  |       |\n";
        std::cout << "| |       /       |  |       | |     \\   |     |  |____   |  |        |  |  |  |   |  |_____   |  |_____  |\n";
        std::cout << "| |______/        |__|       |_|      \\__|     |_______|  |__|        |__|  |__|   |________|  |________| |\n";
        std::cout << "|                                                                                                         |\n";
        std::cout << "+---------------------------------------------------------------------------------------------------------+\n";
        std::cout << "|                                                                                                         |\n";
        std::cout << "|                                                                                                         |\n";
        std::cout << "|                           |---------|                           |---------|                             |\n";

        std::cout << "|                         " << ((currentSelection == 0) ? "> |" : "  |") << "  ";

        SetConsoleTextAttribute(h, 3);
        std::cout << "Start";
        SetConsoleTextAttribute(h, 7);

        std::cout << "  |                         " << ((currentSelection == 1) ? "> |" : "  |") << "  ";

        SetConsoleTextAttribute(h, 4);
        std::cout << "Exit";
        SetConsoleTextAttribute(h, 7);
        std::cout << "   |                             |\n";

        std::cout << "|                           |---------|                           |---------|                             |\n";
        std::cout << "|                                                                                                         |\n";
        std::cout << "|                                                                                                         |\n";
        std::cout << "+---------------------------------------------------------------------------------------------------------+\n";

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
                std::cout << "\nStart Game?\n";
                if (confirmSelection()) {
                    diffselect.selectDifficulty();
                    diffselect.setDifficulty();
                    startGame();
                    std::cout << "\nYou have started the game\n";
                    return; // Exit the function to start the game
                }
                break;
            case 1:
                system("cls");
                std::cout << "\nExit?\n";
                if (confirmSelection()) {

                    std::cout << "\nYou left the game ;-;\n";
                    return;
                }
                break;
            }
        case 'x':
            system("cls");
            std::cout << "\nExiting Game.\n";
            return; // Exit the function immediately
        default:
            break; // Ignore invalid key presses
        }
    }
}

void Game::startGame()
{
    currentWorld = townPtr;
    currentWorld->loopWorld();
}

Gold* Game::getGoldPtr() const
{
    return goldPtr;
}

void Game::switchWorld(char newSymbol)
{
    if (currentSymbol == newSymbol)
    {
        std::cout << "You are already in this world!" << '\n';
    }
    else
    {
        currentSymbol = newSymbol;

        if (currentSymbol == 'T')
        {
            currentWorld = townPtr;

        }
        else if (currentSymbol == 'N')
        {
            currentWorld = dungeonPtr;
        }
    }

    currentWorld->loopWorld();
}