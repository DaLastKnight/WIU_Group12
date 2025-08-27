#pragma once
#include "Items.h"

class Charms : public Items
{
private:
	int maxCharms = 3; // In-class initializer

public:
	// New constructor for Charms
	Charms(const std::string& name);

	// New getter for the max charm count
	int getMaxCharms() const;
	
	void displayMaxCharms() const;
};