#ifndef Boatman_H
#define Boatman_H

#include <string>
#include "Soldiers.h"

class Boatman : public Soldiers {
public:
    Boatman() {
        setHealthPerSoldier(90);
        setDamagePerSoldier(60);
        setDefencePerSoldier(20);
        setAmountOfSoldiersPerUnit(12);
        setUnitName("Boatman");
    }
};
#endif
