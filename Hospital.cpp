#include "Hospital.h"
#include "Game.h"

Hospital::Hospital(Game* gamePtr) : Buildings(gamePtr)
{
	position.setRow(6);
	position.setColumn(7);
	woodPrice = 75;
	stonePrice = 100;
	buildingName = "Hospital";
	buffDescription = "Adds 20hp to base hp.";
	hp = 20;
}

void Hospital::printBuilding()
{
	if (!isBuildingUpgraded)
	{
		// Broken Hospital (Hp buff)
		std::cout << "           __---_---__              \n";
		std::cout << "    .__--_| '  x |  | ' ' |__--_.   \n";
		std::cout << "    | 'x' |=====|=/=|=====| 'x' |   \n";
		std::cout << "    | ' ' |     | + |     |x'   |   \n";
		std::cout << "    | ' ' |==/==|=x=|=====/ ' ' |   \n";
		std::cout << "    | 'x' | ' ' | | | 'x' | ' ' |   \n";
		std::cout << "    |_____|__x__|_|_|__x__|_____|   \n";
	}
	else
	{
		// Hospital (Hp buff)
		std::cout << "           _______________           \n";
		std::cout << "    .-----| ' ' |   | ' ' |-----.     \n";
		std::cout << "    | ' ' |=====|===|=====| ' ' |    \n";
		std::cout << "    | ' ' |     | + |     | ' ' |    \n";
		std::cout << "    | ' ' |=====|===|=====| ' ' |    \n";
		std::cout << "    | ' ' | ' ' | | | ' ' | ' ' |    \n";
		std::cout << "    |_____|_____|_|_|_____|_____|    \n";
	}
}
