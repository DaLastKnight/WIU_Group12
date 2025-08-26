#include "Materials.h"

Materials::Materials()
{
	materialAmount = 0;
	materialName = "";
}

Materials::~Materials()
{

}

int Materials::getMaterialAmount() const
{
	return materialAmount;
}

void Materials::setMaterialAmount(int total)
{
	materialAmount = total;
}

void Materials::displayStats() const
{
	std::cout << "  -- Material Info --\n";
	std::cout << "  Name: " << materialName << "\n";
	std::cout << "  Type: " << getType() << "\n";
	std::cout << "  Amount: " << materialAmount << "\n";
}
