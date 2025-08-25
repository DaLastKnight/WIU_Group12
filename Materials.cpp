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
