//
// Created by CYPONE on 25.12.10.
//

#include <bits/stdc++.h>

class Character {

    struct armor {
        std::string Name = "";
        float defence = 0;
    };

public:
    Character (armor helmet, armor chestplate, armor leggings, armor boots){
        this->boots=boots;
        this->helmet=helmet;
        this->chestplate=chestplate;
        this->leggings=leggings;
    }
private:
    armor helmet;
    armor chestplate;
    armor leggings;
    armor boots;
}