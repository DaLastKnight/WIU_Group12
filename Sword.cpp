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