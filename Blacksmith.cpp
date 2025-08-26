#include "Blacksmith.h"
#include "Game.h"

Blacksmith::Blacksmith(Game* gamePtr) : Buildings(gamePtr)
{
	position.setRow(5);
	position.setColumn(2);
	woodPrice = 25;
	stonePrice = 150;
	buildingName = "Blacksmith";
	buffDescription = "Adds 10atk to base atk.";
}

void Blacksmith::printBuilding()
{
	if (!isBuildingUpgraded)
	{
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
	}
	else
	{
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
	}
}