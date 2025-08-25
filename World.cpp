#include <cstdlib>
#include "World.h"

World::World()
{
	gridWidth = 0;
	gridHeight = 0;
	world = nullptr;
	worldType = "null";
}

World::~World()
{
	for (int i = 0; i < gridWidth; i++)
	{
		delete world[i];
	}

	delete[] world;
}

void World::printWorld()
{
	system("cls");

	// This print only works if gridWidth = gridHeight! For others, please override this function
	std::cout << "Currently in: " << worldType;
	if (worldType == "Dungeon")
	{
		std::cout << '\n';
	}
	else
	{
		std::cout << '\n';
	}

	std::cout << '+';
	for (int i = 0; i < gridWidth - 1; i++)
	{
		std::cout << '-' << '-';
	}
	std::cout << '-' << '+' << '\n';

	for (int i = 0; i < gridWidth; i++)
	{
		for (int j = 0; j < gridHeight; j++)
		{
			switch (j)
			{
			case 0:
				std::cout << '|' << world[i][j];
				break;
			default:
				std::cout << ' ' << world[i][j];
				break;
			}
		}
		std::cout << '|' << '\n';
	}

	std::cout << '+';
	for (int i = 0; i < gridWidth - 1; i++)
	{
		std::cout << '-' << '-';
	}
	std::cout << '-' << '+' << '\n';
}

int World::getGridWidth() const
{
	return gridWidth;
}

int World::getGridHeight() const
{
	return gridHeight;
}