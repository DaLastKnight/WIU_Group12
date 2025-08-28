#include "Armory.h"
#include "Game.h"

Armory::Armory(Game* gamePtr) : Buildings(gamePtr)
{
	position.setRow(7);
	position.setColumn(5);
	woodPrice = 50;
	stonePrice = 130;
	buildingName = "Blacksmith";
	buffDescription = "Adds 5def to base def.";
	def = 5;
}

void Armory::printBuilding()
{
	if (!isBuildingUpgraded)
	{
		// Broken Armory (Defense buff)
		std::cout << "                             \n";
		std::cout << "           ___               \n";
		std::cout << "              \\              \n";
		std::cout << "       |. ]--- \\             \n";
		std::cout << "       || rmxry|\\            \n";
		std::cout << "      / `--x --` \\           \n";
		std::cout << "     |    _       |          \n";
		std::cout << "     | x | \\  ' x |          \n";
		std::cout << "     |   |  |     |[|= o= !  \n";
		std::cout << "'````'``'```'``'```'```'````'\n";
	}
	else
	{
		// Armory (Defense buff)
		std::cout << "       `:.                   \n";
		std::cout << "        _[]_____             \n";
		std::cout << "       /        \\            \n";
		std::cout << "       |.------.|            \n";
		std::cout << "       ||Armory||            \n";
		std::cout << "      / `------` \\           \n";
		std::cout << "     |    __      |          \n";
		std::cout << "     | ' | .| ' ' |[]  o  o  \n";
		std::cout << "     |   |  |     |[]==!==!  \n";
		std::cout << "'````'``'```'``'```'```'````'\n";
	}
}
