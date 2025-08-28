#include <iostream>
#include "Warrior.h"

Warrior::Warrior()
{
    className = "Warrior";
}

int Warrior::bonusMultiplier() const
{
    return 5;
}

void Warrior::setClassStats(Entity& entity)
{
    entity.setStats(100, 20, 8, 12);
}