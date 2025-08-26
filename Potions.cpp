#include "Potions.h"
#include <iostream>

Potions::Potions()
{
	potionName = "";
	potionInfo = "";
	price = 0;
}

void Potions::displayStats() const
{
	std::cout << "  -- Potion Stats --\n";
	std::cout << "  Name: " << potionName << "\n";
	std::cout << "  Type: " << getType() << "\n";
	std::cout << "  Description: " << potionInfo << "\n";
	std::cout << "  Price: " << price << " gold\n";
}
