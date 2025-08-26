#pragma once
#include "Potions.h"
#include <string>
class HealthPotions: public Potions
{
protected:
	int healthPotionCount;
	//int heal;
public:
	HealthPotions(int potionCount);
	void displayStats() const;
};

