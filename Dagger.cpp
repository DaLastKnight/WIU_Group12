#include "Dagger.h"
#include <iostream>

Dagger::Dagger(int tier)
{
    name = "Dagger";

    baseAttack = 4;

    this->tier = tier;

    if (tier == 1)
    {
        baseAttack = baseAttack;
        price = 75;

    }
    else if (tier == 2)
    {
        baseAttack *= 2;
        price = 200;
    }
    else if (tier == 3)
    {
        baseAttack *= 3;
        price = 500;
    }
}

void Dagger::weaponSprite(int tier)
{
    if (tier == 1) {
        std::cout << "    ____________________  \n";
        std::cout << "   |/---\\|`---.....__-`  \n";
        std::cout << "                          \n";
    }
    else if (tier == 2) {
        std::cout << "    ____________________________  \n";
        std::cout << "   |/-----\\|`---....._________-`  \n";
        std::cout << "                                  \n";
    }
    else if (tier == 3) {
        std::cout << "                                   \n";
        std::cout << "    ____________________________   \n";
        std::cout << "   | _____ |___               ./   \n";
        std::cout << "   |/     \\|   \\_____________/   \n";
        std::cout << "                                   \n";
    }
}
