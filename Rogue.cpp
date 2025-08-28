#include <iostream>
#include "Rogue.h"

Rogue::Rogue()
{
    className = "Rogue";
}

int Rogue::bonusMultiplier() const
{
    return 3;
}

void Rogue::setClassStats(Entity& entity)
{
    entity.setStats(90, 18, 6, 16);
}
