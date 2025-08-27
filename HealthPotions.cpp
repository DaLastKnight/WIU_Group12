#include "HealthPotions.h"
#include <iostream>

HealthPotions::HealthPotions(int potionCount)
{
	potionName = "HealthPotion";
	price = 75;
	potionInfo = "Heals 50% of Player's Health";
	potionCount = 0;
	healthPotionCount = potionCount;
	// heal = ((50/100) * player total health) + player total health;
}

void HealthPotions::displayStats() const
{
	std::cout << "  Name: " << potionName << "\n";
	std::cout << "  Type: Potion\n";
	std::cout << "  Description: " << potionInfo << "\n";
	std::cout << "  Price: " << price << " gold\n";
}

void HealthPotions::itemSprite()
{
	std::cout << "          __            \n";
	std::cout << "         (__)           \n";
	std::cout << "         <  >           \n";
	std::cout << "         }  {           \n";
	std::cout << "         /  \\          \n";
	std::cout << "        /    \\         \n";
	std::cout << "      .`      `.        \n";
	std::cout << "     .:        :.       \n";
	std::cout << "     |   [HP]   |       \n";
	std::cout << "     |          |       \n";
	std::cout << "     `:.      .:`       \n";
	std::cout << "       `'----'`         \n";
}
