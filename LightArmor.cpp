#include "LightArmor.h"
#include <iostream>
#include <string>

LightArmor::LightArmor(int tier)
{
	armorName = "LightArmor";
	def = 7;
	hp = 12;
	spd = 0;

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

void LightArmor::displayStats() const
{
	std::cout << "  Name: " << armorName << "\n";
	std::cout << "  Type: LightArmor (ARMOR)\n";
	std::cout << "  Tier: " << tier << "\n";
	std::cout << "  Base Defense: " << def << "\n";
	std::cout << "  Base Speed: " << spd << "\n";
	std::cout << "  Price: " << price << " gold\n";
}

std::string LightArmor::getName() const
{
	return armorName;
}

void LightArmor::armorSprite(int tier)
{
	if (tier == 1) {
		// Light Armour Tier 1
		std::cout << "    __         __      \n";
		std::cout << "   /  |-_.-._-|  \\     \n";
		std::cout << "    \\     +     /      \n";
		std::cout << "     |  | # |  |       \n";
		std::cout << "     |  | # |  |       \n";
		std::cout << "     |  | # |  |       \n";
		std::cout << "                       \n";
	}
	else if (tier == 2) {
		// Light Armour Tier 2
		std::cout << "    __  ]   [  __      \n";
		std::cout << "   /  |-_.-._-|  \\     \n";
		std::cout << "    \\     |     /      \n";
		std::cout << "     [--|=#=|--]       \n";
		std::cout << "     [--|=#=|--]       \n";
		std::cout << "     [--|=#=|--]       \n";
		std::cout << "                       \n";
	}
	else if (tier == 3) {
		// Light Armour Tier 3
		std::cout << "    __  ]   [  __      \n";
		std::cout << "   /  |-_.-._-|  \\     \n";
		std::cout << "    \\   |   |   /      \n";
		std::cout << "     ]::|=#=|::[       \n";
		std::cout << "     ]::|=#=|::[       \n";
		std::cout << "     ]::|=#=|::[       \n";
		std::cout << "    /||#=#=#=#||\\      \n";
		std::cout << "   `             `     \n";
	}
}
