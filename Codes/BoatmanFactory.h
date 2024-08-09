#ifndef BoatmanFactory_H
#define BoatmanFactory_H

#include "SoldierFactory.h"
#include "Boatman.h"

class BoatmanFactory : public SoldierFactory {
public:
    Soldiers* createUnit() override {
        setSoldiers(new Boatman());
        return getSoldiers();
    }

    int calculateTotalHealthPerUnit() override {
        return getSoldiers()->getHealthPerSoldier() * getSoldiers()->getAmountOfSoldiersPerUnit();
    }

    int calculateTotalDamagePerUnit() override {
        return getSoldiers()->getDamagePerSoldier() * getSoldiers()->getAmountOfSoldiersPerUnit();
    }

    int calculateTotalDefencePerUnit() override {
        return getSoldiers()->getDefencePerSoldier() * getSoldiers()->getAmountOfSoldiersPerUnit();
    }
};
#endif
