#ifndef Infantry_H
#define Infantry_H

#include "Soldiers.h"
#include "InfantryFactory.h"

class Infantry : public Soldiers {
    public:
        Infantry() {
        setHealthPerSoldier(100);
        setDamagePerSoldier(50);
        setDefencePerSoldier(30);
        setAmountOfSoldiersPerUnit(10);
        setUnitName("Infantry");
    }
};
#endif
