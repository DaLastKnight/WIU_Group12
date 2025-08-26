#include "HeavyArmor.h"
#include <iostream>
#include <string>

HeavyArmor::HeavyArmor(int tier)
{
	armorName = "HeavyArmor";
	def = 10;
	hp = 15;
	spd = -2;
	this->tier = tier;
	if (tier == 1) {
		price = 125;
		def = def;
		hp = hp;
	}
	else if (tier == 2) {
		price = 300;
		def *= 2;
		hp *= 2;
	}
	else if (tier == 3) {
		price = 600;
		def *= 3;
		hp *= 3;
	}
}

void HeavyArmor::displayStats() const
{
	std::cout << "  Name: " << armorName << "\n";
	std::cout << "  Type: HeavyArmor (ARMOR)\n";
	std::cout << "  Tier: " << tier << "\n";
	std::cout << "  Base Defense: " << def << "\n";
	std::cout << "  Base Speed: " << spd << "\n";
	std::cout << "  Price: " << price << " gold\n";
}

std::string HeavyArmor::getName() const
{
	return armorName + " Tier " + std::to_string(tier);
}
