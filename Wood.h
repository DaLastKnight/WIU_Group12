#pragma once
#include "Materials.h"
class Wood : public Materials
{
private:
	int woodCount;
public:
	Wood(int woodCount);

	void displayStats() const;
};

