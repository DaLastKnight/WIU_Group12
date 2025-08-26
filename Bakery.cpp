#include "Bakery.h"
#include "Game.h"

Bakery::Bakery(Game* gamePtr) : Buildings(gamePtr)
{
	position.setRow(8);
	position.setColumn(3);
	woodPrice = 120;
	stonePrice = 40;
	buildingName = "Bakery";
	buffDescription = "Adds 8spd to base spd.";
}

void Bakery::printBuilding()
{
	if (!isBuildingUpgraded)
	{
		// Broken Bakery (Speed buff)
		std::cout << "                              \n";
		std::cout << "     ._---.____  __.---_.  \n";
		std::cout << "    /  ===| B kx y |=   |    \n";
		std::cout << "    |     :-    `--:     \\    \n";
		std::cout << "    | [x  |   / |  |     |    \n";
		std::cout << "    |     |  |  |  |     |    \n";
		std::cout << "'````'``'```'``'```'```'`````'\n";
		std::cout << "                              \n";
	}
	else
	{
		// Bakery (Speed buff)
		std::cout << "                              \n";
		std::cout << "    .-----.________.-----.    \n";
		std::cout << "    |=====| Bakery |=====|    \n";
		std::cout << "    |     :--`__`--:     |    \n";
		std::cout << "    | [ ] |  | .|  | [ ] |    \n";
		std::cout << "    |     |  |  |  |     |    \n";
		std::cout << "'````'``'```'``'```'```'`````'\n";
		std::cout << "                              \n";
	}
}