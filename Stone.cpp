#include "Stone.h"

Stone::Stone(int stoneCount)
{
	materialAmount = stoneCount;
	materialName = "Stone";
}

void Stone::displayStats() const
{
	std::cout << "  Name: " << materialName << "\n";
	std::cout << "  Type: Materials\n";
	std::cout << "  Amount: " << materialAmount << "\n";
}
