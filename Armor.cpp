#include "Armor.h"
#include <iostream>

Armor::Armor()
{
	price = 0;
	def = 0;
	hp = 0;
	spd = 0;
	type = "ARMOR";
}

void Armor::displayStats() const
{
	std::cout << "  -- Armor Stats --\n";
	std::cout << "  Name: " << name << "\n";
	std::cout << "  Type: " << getType() << "\n";
	std::cout << "  Price: " << price << " gold\n";
	std::cout << "  Base Defense: " << def << "\n";
	std::cout << "  Base Speed: " << spd << "\n";
	std::cout << "  Tier: " << tier << "\n";
}

int Armor::getPrice() const
{
	return price;
}

int Armor::getHealth() const
{
	return hp;
}

int Armor::getDefense() const
{
	return def;
}

int Armor::getSpeed() const
{
	return spd;
}