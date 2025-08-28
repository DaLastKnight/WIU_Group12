#include "Armor.h"
#include <iostream>

Armor::Armor()
{
	armorName = "";
	tier = 0;
	price = 0;
	def = 0;
	hp = 0;
	spd = 0;
}

void Armor::displayStats() const
{
	std::cout << "  -- Armor Stats --\n";
	std::cout << "  Name: " << armorName << "\n";
	std::cout << "  Type: " << getType() << "\n";
	std::cout << "  Price: " << price << " gold\n";
	std::cout << "  Base Defense: " << def << "\n";
	std::cout << "  Base Speed: " << spd << "\n";
	std::cout << "  Tier: " << tier << "\n";
}

int Armor::getTier() const
{
	return tier;
}

int Armor::getPrice() const
{
	return price;
}