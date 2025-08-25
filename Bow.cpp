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
