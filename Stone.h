#pragma once
#include "Materials.h"
class Stone : public Materials
{
private:
	int stoneCount;
public:
	Stone(int stoneCount);

	void displayStats() const;
};