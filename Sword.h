#pragma once
#include "Weapons.h"

class Sword : public Weapons
{
protected:
    
public:
    Sword(int tier);
    void displayStats() const;
    std::string getName() const;
    void weaponSprite(int tier) override;
};