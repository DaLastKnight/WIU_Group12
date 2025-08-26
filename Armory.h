#pragma once
#include "Buildings.h"

class Game;

class Armory : public Buildings
{
public:
	Armory(Game* gamePtr);
	void printBuilding();
};