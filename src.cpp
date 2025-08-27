#include <iostream>
#include "selectClass.h"
#include "Player.h"
#include "Warrior.h"
#include "Rogue.h"
#include "Wizard.h"
#include "Cleric.h"
#include "Game.h"
#include "Inventory.h"

#include <Windows.h> 

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

	//char gametable[20][20];

	//for (int i = 0; i < 20; i++) {
	//	for (int j = 0; j < 20; j++) {
	//		gametable[i][j] = ' ';
	//	}
	//}

	//slowPrint("This is a test", 10);

	//SelectClass slc;
	//Player p;

	//slc.chooseClass(p);
	//p.viewCurrentStats();
	//p.attacking();

	Game* gamePtr = new Game;
	/*Inventory iven;

	iven.openInventory();*/
	gamePtr->initGame();
	gamePtr->startingScreen();
	delete gamePtr;

	/*gamePtr->initGame();
	gamePtr->startGame();


	selectClass choice;
	Player* myPlayer;

	choice.chooseClass();

	myPlayer = choice.getPlayer();

	std::cout << "\nViewing your player's stats:\n";
	myPlayer->viewCurrentStats();

		myPlayer->attacking();
	*/

	//myPlayer->useSkill();



	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);

	/*std::cout << "+-------------------------------------------------------+\n";
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
	std::cout << "|          |  ";
	SetConsoleTextAttribute(h, 4);
	std::cout << "Attack";
	SetConsoleTextAttribute(h, 7);
	std::cout << "  |          |  ";

	SetConsoleTextAttribute(h, 3);
	std::cout << "Skill";
	SetConsoleTextAttribute(h, 7);
	std::cout << "   |           |\n";

	std::cout << "|          |----------|          |----------|           |\n";
	std::cout << "|                                                       |\n";

	std::cout << "|          |----------|          |----------|           |\n";
	std::cout << "|          |  ";
	SetConsoleTextAttribute(h, 2);
	std::cout << "Items";
	SetConsoleTextAttribute(h, 7);
	std::cout << "   |          |  ";

	SetConsoleTextAttribute(h, 6);
	std::cout << "Defend";
	SetConsoleTextAttribute(h, 7);
	std::cout << "  |           |\n";

	std::cout << "|          |----------|          |----------|           |\n";
	std::cout << "|                                                       |\n";
	std::cout << "|                                                       |\n";
	std::cout << "+-------------------------------------------------------+\n";

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
	std::cout << "|          |---------|           |---------|            |\n";
	std::cout << "|          |  ";

	SetConsoleTextAttribute(h, 3);
	std::cout << "Evade";
	SetConsoleTextAttribute(h, 7);

	std::cout << "  |           |  ";

	SetConsoleTextAttribute(h, 6);
	std::cout << "Block";
	SetConsoleTextAttribute(h, 7);
	std::cout << "  |            |\n";

	std::cout << "|          |---------|           |---------|            |\n";
	std::cout << "|                                                       |\n";
	std::cout << "|                                                       |\n";
	std::cout << "+-------------------------------------------------------+\n";*/

	/*std::cout << "+---------------------------------------------------------------------------------------------------------+\n";
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
	std::cout << "|                           |  ";

	SetConsoleTextAttribute(h, 3);
	std::cout << "Start";
	SetConsoleTextAttribute(h, 7);

	std::cout << "  |                           |  ";

	SetConsoleTextAttribute(h, 6);
	std::cout << "Exit";
	SetConsoleTextAttribute(h, 7);
	std::cout << "   |                             |\n";

	std::cout << "|                           |---------|                           |---------|                             |\n";
	std::cout << "|                                                                                                         |\n";
	std::cout << "|                                                                                                         |\n";
	std::cout << "+---------------------------------------------------------------------------------------------------------+\n*/

	// House
	std::cout << "         : .                        \n";
	std::cout << "           .:                       \n";
	std::cout << "          __[]____                  \n";
	std::cout << "         /\\       \\______         \n";
	std::cout << "     ___/  \\_______\\_____\\_____  \n";
	std::cout << "    /\\___\\ | ' ' ' | ' ' |_____\\ \n";
	std::cout << "    ||'''| |       |     | ' ' |    \n";
	std::cout << "  '````''```'''```''''````'````'``  \n";

	// Broken House
	std::cout << "          __                        \n";
	std::cout << "         /\\ \\[]        __         \n";
	std::cout << "     ___/  \\  _\\__    |  \\_      \n";
	std::cout << "    /\\___\\ | /   x\\  x|  |_\\_   \n";
	std::cout << "    ||'x'| | | x   \\  |  | x \\__  \n";
	std::cout << "  '````''```'''```''''````'````'``  \n";

	// Shop
	std::cout << "      . .                     \n";
	std::cout << "        .:                    \n";
	std::cout << "       __[]_________          \n";
	std::cout << "      /\\____________\\       \n";
	std::cout << "      ||   |Shop|   |         \n";
	std::cout << "      ||     __     |         \n";
	std::cout << "      || '' | .| '' |         \n";
	std::cout << "      ||    |  |    |         \n";
	std::cout << "    `'``````''`````''``       \n";

	// Broken Hospital (Hp buff)
	std::cout << "           __---_---__              \n";
	std::cout << "    .__--_| '  x |  | ' ' |__--_.   \n";
	std::cout << "    | 'x' |=====|=/=|=====| 'x' |   \n";
	std::cout << "    | ' ' |     | + |     |x'   |   \n";
	std::cout << "    | ' ' |==/==|=x=|=====/ ' ' |   \n";
	std::cout << "    | 'x' | ' ' | | | 'x' | ' ' |   \n";
	std::cout << "    |_____|__x__|_|_|__x__|_____|   \n";


	// Hospital (Hp buff)
	std::cout << "           _______________           \n";
	std::cout << "    .-----| ' ' |   | ' ' |-----.     \n";
	std::cout << "    | ' ' |=====|===|=====| ' ' |    \n";
	std::cout << "    | ' ' |     | + |     | ' ' |    \n";
	std::cout << "    | ' ' |=====|===|=====| ' ' |    \n";
	std::cout << "    | ' ' | ' ' | | | ' ' | ' ' |    \n";
	std::cout << "    |_____|_____|_|_|_____|_____|    \n";


	// Houses
	std::cout << "        ..                        \n";
	std::cout << "          `:.                     \n";
	std::cout << "           _[]______              \n";
	std::cout << "          / \\_______\\_____      \n";
	std::cout << "       ___|'| ' ' ' |_____\\      \n";
	std::cout << "      /\\___\\| ' ' ' | ' ' | []  \n";
	std::cout << "      ||'''||       |     |[][]   \n";
	std::cout << " '````''```'''```''''````'````'`` \n";

	// More Houses
	std::cout << "        ..                        \n";
	std::cout << "         `:.                      \n";
	std::cout << "          _[]__ __                \n";
	std::cout << "         / \\__x___\\____         \n";
	std::cout << "     _ _|'| x ' ' |____x\\        \n";
	std::cout << "    /\\__X\\| ' ' ' |  x  |       \n";
	std::cout << "    ||'x'||     x |     |[]  [    \n";
	std::cout << " '````'`''``'```'`''`````'````'`` \n";

	// Blacksmith (Attack Buff)
	std::cout << "         .----------.          \n";
	std::cout << "        /-BLACKSMITH-\\        \n";
	std::cout << "   .___/              \\___.   \n";
	std::cout << "  /    | [==========] |    \\  \n";
	std::cout << " /_____| (__)         |_____\\ \n";
	std::cout << " | ' ' |      __      | ' ' |  \n";
	std::cout << " | ' ' | ' ' | .| ' ' | ' ' |  \n";
	std::cout << " |     |     |  |     |     |  \n";
	std::cout << "'````'`''``'```'`''`````'````' \n";

	// Broken Blacksmith (Attack Buff)
	std::cout << "         ____---____          \n";
	std::cout << "        /-BLAC\\SMI-\\__       \n";
	std::cout << "   ___x/      x       \\__x   \n";
	std::cout << "  /   x| [==  ==x==]  |   \\  \n";
	std::cout << " /__x__| (xx)     x   |__x_\\ \n";
	std::cout << " | 'x' |   x  __   x  | ' ' | \n";
	std::cout << " | ' ' | ' ' |x.| 'x' | 'x' | \n";
	std::cout << " |     |  x  |  |     |  x  | \n";
	std::cout << "'````'``'```'``'```'```'`````'\n";

	// Bakery
	std::cout << "                              \n";
	std::cout << "    .-----.________.-----.    \n";
	std::cout << "    |=====| Bakery |=====|    \n";
	std::cout << "    |     :--`__`--:     |    \n";
	std::cout << "    | [ ] |  | .|  | [ ] |    \n";
	std::cout << "    |     |  |  |  |     |    \n";
	std::cout << "'````'``'```'``'```'```'`````'\n";
	std::cout << "                              \n";

	// Bakery
	std::cout << "                              \n";
	std::cout << "     ._---.____  __.---_.  \n";
	std::cout << "    /  ===| B kx y |=   |    \n";
	std::cout << "    |     :-    `--:     \    \n";
	std::cout << "    | [x  |   / |  |     |    \n";
	std::cout << "    |     |  |  |  |     |    \n";
	std::cout << "'````'``'```'``'```'```'`````'\n";
	std::cout << "                              \n";

	// Armory
	std::cout << "       `:.                   \n";
	std::cout << "        _[]_____             \n";
	std::cout << "       /        \            \n";
	std::cout << "       |.------.|            \n";
	std::cout << "       ||Armory||            \n";
	std::cout << "      / `------` \           \n";
	std::cout << "     |    __      |          \n";
	std::cout << "     | ' | .| ' ' |[]  o  o  \n";
	std::cout << "     |   |  |     |[]==!==!  \n";
	std::cout << "'````'``'```'``'```'```'````'\n";

	// Broken Armory
	std::cout << "                             \n";
	std::cout << "           ___               \n";
	std::cout << "              \              \n";
	std::cout << "       |. ]--- \             \n";
	std::cout << "       || rmxry|\            \n";
	std::cout << "      / `--x --` \           \n";
	std::cout << "     |    _       |          \n";
	std::cout << "     | x | \  ' x |          \n";
	std::cout << "     |   |  |     |[|= o= !  \n";
	std::cout << "'````'``'```'``'```'```'````'\n";

	// Tier 3 Sword
	std::cout << "    __      /|                                 \n";
	std::cout << "   |  |    | |----------------------------\\   \n";
	std::cout << "   | :-{===|=[]============================>   \n";
	std::cout << "   |__|    | |----------------------------/    \n";
	std::cout << "            \\|                                \n";
	std::cout << "                                               \n";


	// Tier 2 Sword
	std::cout << "     _                                   \n";
	std::cout << "    | |   /|----------------------.      \n";
	std::cout << "    | )===(|---------------------/       \n";
	std::cout << "    |_|   \\|--------------------`       \n";
	std::cout << "                                         \n";

	// Tier 1 Sword
	std::cout << "                                    \n";
	std::cout << "          |\\___________________     \n";
	std::cout << "    )====={ __________________/     \n";
	std::cout << "          |/                        \n";
	std::cout << "                                    \n";

	// Tier 3 Dagger
	std::cout << "    ____________________________   \n";
	std::cout << "   | _____ |___               ./   \n";
	std::cout << "   |/     \\|   \\_____________/    \n";
	std::cout << "                                   \n";

	// Tier 2 Dagger
	std::cout << "    ____________________________  \n";
	std::cout << "   |/-----\\|`---....._________-`  \n";
	std::cout << "                                  \n";

	// Tier 1 Dagger
	std::cout << "    ____________________  \n";
	std::cout << "   |/---\\|`---.....__-`  \n";
	std::cout << "                          \n";

	// Tier 3 Bow
	std::cout << "                /             \n";
	std::cout << "               /\\.           \n";
	std::cout << "             /    |.          \n";
	std::cout << "           /      `|.         \n";
	std::cout << "         /         |.         \n";
	std::cout << "       /           |\\         \n";
	std::cout << "     /             ##         \n";
	std::cout << "   >>==============##=======> \n";
	std::cout << "     \\             ##       \n";
	std::cout << "       \\           |/       \n";
	std::cout << "         \\        |`       \n";
	std::cout << "           \\     ,|`       \n";
	std::cout << "             \\   |`        \n";
	std::cout << "               \\/`          \n";
	std::cout << "                \\           \n";

	// Tier 2 Bow
	std::cout << "           .-:\\               \n";
	std::cout << "        ./    :\\             \n";
	std::cout << "     ./        :.             \n";
	std::cout << "   /            :\\           \n";
	std::cout << "  >>-------------||-->>       \n";
	std::cout << "   \\            :/           \n";
	std::cout << "     `\\        :`            \n";
	std::cout << "        `\\    :/             \n";
	std::cout << "          `-:/                \n";

	// Tier 1 Bow
	std::cout << "          /(           \n";
	std::cout << "        /   \\          \n";
	std::cout << "      /      )         \n";
	std::cout << "   >>>-------<--->     \n";
	std::cout << "      \\      )         \n";
	std::cout << "        \\   /          \n";
	std::cout << "          \\(           \n";
	std::cout << "                       \n";

	// Potion
	std::cout << "          __            \n";
	std::cout << "         (__)           \n";
	std::cout << "         <  >           \n";
	std::cout << "         }  {           \n";
	std::cout << "         /  \\          \n";
	std::cout << "        /    \\         \n";
	std::cout << "      .`      `.        \n";
	std::cout << "     .:        :.       \n";
	std::cout << "     |   [HP]   |       \n";
	std::cout << "     |          |       \n";
	std::cout << "     `:.      .:`       \n";
	std::cout << "       `'----'`         \n";


	// Armour tier 3
	std::cout << "                           \n";
	std::cout << "    ___    ]   [    ___    \n";
	std::cout << "   /   <--< '-' >-->   \\   \n";
	std::cout << "   \\   |   \\___/   |   /   \n";
	std::cout << "    \\__/    | |    \\__/    \n";
	std::cout << "        \\.-.| |.-./        \n";
	std::cout << "         [..| |..]         \n";
	std::cout << "         [..| |..]         \n";
	std::cout << "         [..| |..]         \n";
	std::cout << "        /###|_|###\\        \n";
	std::cout << "       /  /     \\  \\       \n";
	std::cout << "      `  `       `  `      \n";

	// Armour tier 2
	std::cout << "      __   ]   [   __    \n";
	std::cout << "     /  <-< '-' >->  \\   \n";
	std::cout << "     \\__/  \\___/  \\__/    \n";
	std::cout << "        \\.-.| |.-./        \n";
	std::cout << "         [..| |..]         \n";
	std::cout << "         [..| |..]         \n";
	std::cout << "        /###|_|###\\        \n";
	std::cout << "                           \n";

	// Armour tier 1
	std::cout << "      __   ]   [   __    \n";
	std::cout << "     /  <-< '-' >->  \\   \n";
	std::cout << "     \\__/  \\___/  \\__/    \n";
	std::cout << "        \\.-.| |.-./        \n";
	std::cout << "         [##|=|##]         \n";
	std::cout << "         [##|=|##]         \n";
	std::cout << "         [##|=|##]         \n";
	std::cout << "                           \n";


	// Armour 2 tier 3
	std::cout << "     ___ ]   [ ___      \n";
	std::cout << "    /  |-_.-._-|  \\     \n";
	std::cout << "     \\   |   |   /      \n";
	std::cout << "      ]::|=#=|::[       \n";
	std::cout << "      ]::|=#=|::[       \n";
	std::cout << "      ]::|=#=|::[       \n";
	std::cout << "     /||#=#=#=#||\\      \n";
	std::cout << "    `             `     \n";

	// Armour 2 tier 2
	std::cout << "     ___ ]   [ ___      \n";
	std::cout << "    /  |-_.-._-|  \\     \n";
	std::cout << "     \\     |     /      \n";
	std::cout << "      [--|=#=|--]       \n";
	std::cout << "      [--|=#=|--]       \n";
	std::cout << "      [--|=#=|--]       \n";
	std::cout << "                        \n";

	/*std::cout  << R"(    
        ___    ]   [    ___
	   /   <--< '-' >-->   \
	   \   |   \___/   |   /
	    \__/    | |    \__/
	        \.-.| |.-./
	         [..| |..]
	         [..| |..]
	         [..| |..]
	        /###|_|###\
	       /   /    \  \
	      `   `      `  `       )";*/

	// Armour 2 tier 1
	std::cout << "     ___       ___      \n";
	std::cout << "    /  |-_.-._-|  \\     \n";
	std::cout << "     \\     +     /      \n";
	std::cout << "      |  | # |  |       \n";
	std::cout << "      |  | # |  |       \n";
	std::cout << "      |  | # |  |       \n";
	std::cout << "                        \n";

	// Rope
	std::cout << "      | /|          \n";
	std::cout << "      |/ |          \n";
	std::cout << "      (__)          \n";
	std::cout << "      (__)          \n";
	std::cout << "      | /|          \n";
	std::cout << "      |/ |          \n";
	std::cout << "      (__)          \n";
	std::cout << "      (__)          \n";
	std::cout << "      (__)          \n";
	std::cout << "     ./  \\.          \n";
	std::cout << "   ./  ..  \\.       \n";
	std::cout << "   |  /  \\  |     \n";
	std::cout << "   |  \\  /  |         \n";
	std::cout << "   `\\  ``  /`      \n";
	std::cout << "     \\____/       \n";

	std::cout << R"(                                                                            
)";

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

	// Charm
	std::cout << "        .--...--.          \n";
	std::cout << "     .:`         `:.       \n";
	std::cout << "     :             :       \n";
	std::cout << "     `:           :`       \n";
	std::cout << "      `:.       .:`        \n";
	std::cout << "         `.-.-.`           \n";
	std::cout << "           .^.             \n";
	std::cout << "         .:` `:.           \n";
	std::cout << "        .`     `.          \n";
	std::cout << "        :.     .:          \n";
	std::cout << "          `-^-`            \n";


	return 0;
}

