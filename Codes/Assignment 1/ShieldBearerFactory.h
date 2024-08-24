#ifndef ShieldBearerFactory_H
#define ShieldBearerFactory_H

#include <string>
#include "SoldierFactory.h"
#include "ShieldBearer.h"

class ShieldBearerFactory : public SoldierFactory {
    public:
        Soldiers* createUnit() override {
            setSoldiers(new ShieldBearer());
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
