#include "Equipments.h"

Equipments::Equipments()
{
	name = "";
	type = "";
	tier = 0;
}

std::string Equipments::getName() const
{
	return name;
}

std::string Equipments::getType() const
{
	return type;
}

int Equipments::getTier() const
{
	return tier;
}
