#pragma once
#include "Weapons.h"

class Dagger : public Weapons
{
protected:

public:
    Dagger(int daggerTier);
    void displayStats() const;
    std::string getName() const;
    void weaponSprite(int tier) override;
};