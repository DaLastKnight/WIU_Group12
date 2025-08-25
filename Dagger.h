#pragma once
#include "Weapons.h"

class Dagger : public Weapons
{
protected:

public:
    Dagger(int tier);
    void weaponSprite(int tier) override;
};