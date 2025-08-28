#include "Sword.h"
#include <iostream>

Sword::Sword(int tier)
{
    name = "Sword";

    baseAttack = 5;

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

void Sword::displayStats() const
{
    std::cout << "  Name: " << name << " Tier " << tier << "\n";
    std::cout << "  Type: Sword (WEAPON)\n";
    std::cout << "  Tier: " << tier << "\n";
    std::cout << "  Attack: " << baseAttack << "\n";
    std::cout << "  Price: " << price << " gold\n";
}

void Sword::weaponSprite(int tier)
{
    if (tier == 1) {
        std::cout << "                                    \n";
        std::cout << "          |\\___________________     \n";
        std::cout << "    )====={ __________________/     \n";
        std::cout << "          |/                        \n";
        std::cout << "                                    \n";
    }
    else if (tier == 2) {
        std::cout << "     _                                   \n";
        std::cout << "    | |   /|----------------------.      \n";
        std::cout << "    | )===(|---------------------/       \n";
        std::cout << "    |_|   \\|--------------------`        \n";
        std::cout << "                                         \n";
    }
    else if (tier == 3) {
        std::cout << "    __      /|                                 \n";
        std::cout << "   |  |    | |----------------------------\\   \n";
        std::cout << "   | :-{===|=[]============================>   \n";
        std::cout << "   |__|    | |----------------------------/    \n";
        std::cout << "            \\|                                \n";
        std::cout << "                                               \n";
    }
    }
    
