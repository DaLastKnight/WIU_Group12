#pragma once
#include "Items.h"
#include <string>

class Potions : public Items
{
protected:
	std::string potionName;
	std::string potionInfo;
	int price;
public:
	Potions();

	// For Inventory
	std::string getName() const override { return potionName; }
	std::string getType() const override { return "POTION"; }
	void displayStats() const;
	//virtual void potionSprite() = 0;
	/*virtual void itemSprite();*/
	int getPrice() const;
};

