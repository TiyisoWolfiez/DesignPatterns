#ifndef InfantryFactory_H
#define InfantryFactory_H

#include <string>
#include "SoldierFactory.h"
#include "Infantry.h"

class InfantryFactory : public SoldierFactory {
    public:
        Soldiers* createUnit() override {
            setSoldiers(new Infantry());
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
