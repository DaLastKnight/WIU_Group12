#pragma once
#include "Armor.h"

class HeavyArmor : public Armor
{
protected:
public:
	HeavyArmor(int tier);

	// For Inventory
	void displayStats() const;

	void armorSprite(int tier);
};

