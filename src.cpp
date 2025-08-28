#include <iostream>
#include "Game.h"

#include <Windows.h> 

#include <random>
#include <string>
#include <chrono>
#include <thread>

void slowPrint(const std::string& text, int delayMs = 50) {
	for (char c : text) {
		std::cout << c << std::flush;               // print each character
		std::this_thread::sleep_for(std::chrono::milliseconds(delayMs)); // wait
	}
}

int main(void) {

	srand(static_cast<unsigned int>(time(nullptr)));

	Game* gamePtr = new Game;
	gamePtr->initGame();
	gamePtr->startingScreen();
	delete gamePtr;


	// Treasure Chest
	std::cout << "  |             |             |             |             |           \n";
	std::cout << "__|_____________|_______._.==_._____________|_____________|___________\n";
	std::cout << "         |         _.==` __.--'-,    |             |              |   \n";
	std::cout << "_________|________;   .=`        `=._._____________|______________|___\n";
	std::cout << "                |   `._ o '._           `=._|             |           \n";
	std::cout << "________________|______'-_  `--.            `=____________|___________\n";
	std::cout << "         |              `=_   `-._    __-'`'=.     |              |   \n";
	std::cout << "_________|_________.--'``` `=._ o  `-.`  _.--. `.__|______________|___\n";
	std::cout << "            ._.--`             `=._ .' ,`     ; '         |           \n";
	std::cout << "____________|o`-._                 `=._ `-._  ; '_________|___________\n";
	std::cout << "         |  | ;=. `--.                 `-._ ``` ;  |              |   \n";
	std::cout << "_________|__|o;  `-._ `-._                 `-._/___|______________|___\n";
	std::cout << "            | ;      (#). `-._          ___.--o|          |           \n";
	std::cout << "____________|o.`-.    `  `=_. `=-.__.--`o__.-; |__________|___________\n";
	std::cout << "________/_____'_ o`-_.      `-..o|o_.--'     ; |______/_______/_______\n";
	std::cout << "___/________/___`-.__ `=._     ; | ;         ; |/________/________/___\n";
	std::cout << "________/________/___`=._ `-.  ;o|o;    ,__.-; |______/_______/_______\n";
	std::cout << "___/________/________/___`=._`.; | ;_.--`o___.o|/________/________/___\n";
	std::cout << "________/________/________/__`=_o|o_.----`__/_________/_______/_______\n";
	std::cout << "___/________/________/________/________/________/________/________/___\n";
	std::cout << "________/________/________/________/________/________/________/_______\n";

	return 0;
}

