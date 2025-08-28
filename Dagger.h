#pragma once
#include "Weapons.h"

class Dagger : public Weapons
{
protected:

public:
    Dagger(int daggerTier);
    void displayStats() const;
    void weaponSprite(int tier) override;
};