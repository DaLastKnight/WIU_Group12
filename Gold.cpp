#include "Gold.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

Gold::Gold(int startingGold): totalGold(startingGold)
{
	totalGold = startingGold;
}

int Gold::getTotalGold() const
{
	return totalGold;
}

void Gold::setTotalGold(int total)
{
	totalGold += total;
}

void Gold::displayAllGold()
{
	std::cout << "Total amount of gold player has: " << totalGold << std::endl;
}
