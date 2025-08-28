#include "Weapons.h"
#include <iostream>

Weapons::Weapons()
{
	price = 0;
	type = "WEAPON";
	baseAttack = 0;
}

int Weapons::getBaseAttack() const
{
	return baseAttack;
}

int Weapons::getPrice() const
{
	return price;
}

void Weapons::displayStats() const
{
	std::cout << "  -- Weapon Stats --\n";
	std::cout << "  Name: " << name << "\n";
	std::cout << "  Type: " << getType() << "\n";
	std::cout << "  Price: " << price << " gold\n";
	std::cout << "  Base Attack: " << baseAttack << "\n";
	std::cout << "  Tier: " << tier << "\n";
}