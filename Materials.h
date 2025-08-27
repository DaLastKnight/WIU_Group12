#pragma once
#include "Items.h"
#include <iostream>
#include <string>

class Materials : public Items
{
protected:
	int materialAmount;
	std::string materialName;

public:
	Materials();
	~Materials();

	int getMaterialAmount() const;
	void setMaterialAmount(int total);

	// For Inventory
	std::string getName() const { return materialName; }
	std::string getType() const { return "MATERIAL"; }
	void displayStats() const;
};

