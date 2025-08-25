#include "Materials.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

// Constructor implementation
Materials::Materials(int normalWood, int normalStone, int eliteWood, int eliteStone, int bossWood, int bossStone)
    : normalWoodAmount(normalWood), normalStoneAmount(normalStone),
    eliteWoodAmount(eliteWood), eliteStoneAmount(eliteStone),
    bossWoodAmount(bossWood), bossStoneAmount(bossStone),
    wood(normalWood + eliteWood + bossWood),
    stone(normalStone + eliteStone + bossStone)
{
}

void Materials::generateRandomMaterials()
{
    normalWoodAmount = rand() % 10 + 1;
    normalStoneAmount = rand() % 10 + 1;
    eliteWoodAmount = rand() % 10 + 11;
    eliteStoneAmount = rand() % 10 + 11;
    bossWoodAmount = rand() % 10 + 21;
    bossStoneAmount = rand() % 10 + 21;
}

void Materials::updateTotals()
{
    wood = normalWoodAmount + eliteWoodAmount + bossWoodAmount;
    stone = normalStoneAmount + eliteStoneAmount + bossStoneAmount;
}

// This function now handles displaying the individual and total amounts
void Materials::displayMaterials() const
{
    std::cout << "--- Materials ---" << std::endl;
    std::cout << "\nNormal Wood: " << normalWoodAmount << std::endl;
    std::cout << "Elite Wood: " << eliteWoodAmount << std::endl;
    std::cout << "Boss Wood: " << bossWoodAmount << std::endl;
    std::cout << "--------------------------" << std::endl;

    std::cout << "Normal Stone: " << normalStoneAmount << std::endl;
    std::cout << "Elite Stone: " << eliteStoneAmount << std::endl;
    std::cout << "Boss Stone: " << bossStoneAmount << std::endl;
    std::cout << "--------------------------" << std::endl;

    std::cout << "\nTotal Wood: " << wood << std::endl;
    std::cout << "Total Stone: " << stone << std::endl;
    std::cout << "--------------------------" << std::endl;
}