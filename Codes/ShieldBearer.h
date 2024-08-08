#ifndef ShieldBearer_H
#define ShieldBearer_H

#include <string>
#include "Soldiers.h"

class ShieldBearer : public Soldiers {
    public:
    ShieldBearer() {
        setHealthPerSoldier(120);
        setDamagePerSoldier(40);
        setDefencePerSoldier(50);
        setAmountOfSoldiersPerUnit(8);
        setUnitName("ShieldBearer");
    }
};
#endif
