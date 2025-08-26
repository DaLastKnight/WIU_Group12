#pragma once
#include "Buildings.h"

class Game;

class Blacksmith : public Buildings
{
public:
	Blacksmith(Game* gamePtr);
	void printBuilding();
};

