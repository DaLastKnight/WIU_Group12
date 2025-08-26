#include "Weapons.h"
#include <iostream>

Weapons::Weapons()
{
	name = "";
	price = 0;
	baseAttack = 0;
	tier = 0;
}

std::string Weapons::getName() const
{
	return name;
}

int Weapons::getBaseAttack() const
{
	return baseAttack;
}

int Weapons::getTier() const
{
	return tier;
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