#pragma once
#include "Armor.h"

class LightArmor : public Armor
{
protected:
public:
	LightArmor(int tier);

	// For Inventory
	void displayStats() const;
	std::string getName() const;
};

