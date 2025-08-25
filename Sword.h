#pragma once
#include "Weapons.h"

class Sword : public Weapons
{
protected:
    
public:
    Sword(int tier);
    void weaponSprite(int tier) override;
};