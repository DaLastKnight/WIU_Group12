#include "Wood.h"

Wood::Wood(int woodCount)
{
	this->woodCount = woodCount;
	materialAmount = woodCount;
	materialName = "Wood";
}

void Wood::displayStats() const
{
	std::cout << "  Name: " << materialName << "\n";
	std::cout << "  Type: Materials\n";
	std::cout << "  Amount: " << materialAmount << "\n";
}
