#include "Bow.h"
#include <iostream>

Bow::Bow(int tier)
{
    name = "Bow";

    baseAttack = 7;

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

void Bow::displayStats() const
{
    std::cout << "  Name: " << name << "\n";
    std::cout << "  Type: Bow (WEAPON)\n";
    std::cout << "  Tier: " << tier << "\n";
    std::cout << "  Attack: " << baseAttack << "\n";
    std::cout << "  Price: " << price << " gold\n";
}

void Bow::weaponSprite(int tier)
{
    if (tier == 1) {
        std::cout << "          /(           \n";
        std::cout << "        /   \\          \n";
        std::cout << "      /      )         \n";
        std::cout << "   >>>-------<--->     \n";
        std::cout << "      \\      )         \n";
        std::cout << "        \\   /          \n";
        std::cout << "          \\(           \n";
        std::cout << "                       \n";
    }
    else if (tier == 2) {
        std::cout << "        .-:\\               \n";
        std::cout << "      ./    :\\             \n";
        std::cout << "    ./       :.             \n";
        std::cout << "   /          :\\           \n";
        std::cout << "  >>-----------||-->>       \n";
        std::cout << "   \\          :/           \n";
        std::cout << "    `\\       :`            \n";
        std::cout << "      `\\    :/             \n";
        std::cout << "        `-:/                \n";
    }
    else if (tier == 3) {
        std::cout << "                /             \n";
        std::cout << "               /\\.           \n";
        std::cout << "             /    |.          \n";
        std::cout << "           /      `|.         \n";
        std::cout << "         /         |.         \n";
        std::cout << "       /           |\\         \n";
        std::cout << "     /             ##         \n";
        std::cout << "   >>==============##=======> \n";
        std::cout << "     \\             ##       \n";
        std::cout << "       \\           |/       \n";
        std::cout << "         \\        |`       \n";
        std::cout << "           \\     ,|`       \n";
        std::cout << "             \\   |`        \n";
        std::cout << "               \\/`          \n";
        std::cout << "                \\           \n";
    }
    
}
