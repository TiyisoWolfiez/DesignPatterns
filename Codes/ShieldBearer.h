#ifndef ShieldBearer_H
#define ShieldBearer_H

#include <string>
#include "Soldiers.h"

class ShieldBearer {
    private:
        int healthPerSoldier;
        int damagePerSoldier;
        int defencePerSoldier;
        int amountOfSoldiersPerUnit;
        std::string unitName;
};
#endif
