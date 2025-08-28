#include <iostream>
#include "Wizard.h"

Wizard::Wizard()
{
    className = "Wizard";
}

int Wizard::bonusMultiplier() const
{
    return 4;
}

void Wizard::setClassStats(Entity& entity)
{
    entity.setStats(75, 25, 4, 9);
}
