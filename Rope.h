#pragma once
#include "Items.h" 
#include <string>

class Rope : public Items
{
protected:
	std::string itemName;
	std::string ropeInfo;
	int ropeCount;
public:
	Rope(int count);

	// For Inventory
	std::string getName() const override { return itemName; }
	std::string getType() const override { return "MISCELLANEOUS"; }
	void displayStats() const;

	void itemSprite();
};