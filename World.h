#pragma once
#include <iostream>

class World
{
protected:
	std::string worldType;
	int gridWidth;
	int gridHeight;
	char** world;

public:
	World();
	~World();
	virtual void initWorld() = 0;
	virtual void printWorld();
	virtual void loopWorld() = 0;
	int getGridWidth() const;
	int getGridHeight() const;
};
