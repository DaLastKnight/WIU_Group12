#pragma once
#include "Buildings.h"

class Game;

class Hospital : public Buildings
{
public:
	Hospital(Game* gamePtr);
	void printBuilding();
};

