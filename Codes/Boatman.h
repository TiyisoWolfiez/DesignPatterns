#ifndef Boatman_H
#define Boatman_H

#include <string>
#include "Soldiers.h"

class Boatman{
    private:
        int healthPerSoldier;
        int damagePerSoldier;
        int defencePerSoldier;
        int amountOfSoldiersPerUnit;
        std::string unitName;
};
#endif
