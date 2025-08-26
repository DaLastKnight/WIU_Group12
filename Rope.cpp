#include "Rope.h"
#include <iostream>

Rope::Rope(int count)
{
	itemName = "Rope";
	ropeCount = count;
	price = 60;
	ropeInfo = "Exit the dungeon, regardless of in and out of battle (cannot be used in boss battles)";
}

void Rope::displayStats() const
{
	std::cout << "  Name: " << itemName << "\n";
	std::cout << "  Type: Miscellaneous\n";
	std::cout << "  Description: " << ropeInfo << "\n";
	std::cout << "  Price: " << price << " gold\n";
}
