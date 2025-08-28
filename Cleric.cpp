#include <iostream>
#include "Cleric.h"

Cleric::Cleric()
{
    className = "Cleric";
}

int Cleric::bonusMultiplier() const
{
    return 15;
}

void Cleric::setClassStats(Entity& entity)
{
    entity.setStats(85, 15, 6, 10);
}
