#pragma once
#include "Buildings.h"

class Game;

class Bakery : public Buildings
{
public:
	Bakery(Game* gamePtr);
	void printBuilding();
};