#include "Weapons.h"

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