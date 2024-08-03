#ifndef Infantry_H
#define Infantry_H

#include "Soldiers.h"

class Infantry : public Soldiers {
    public:
        Infantry() {
        healthPerSoldier = 100;
        damagePerSoldier = 50;
        defencePerSoldier = 30;
        amountOfSoldiersPerUnit = 10;
        unitName = "Infantry";
    }

    int getHealthPerSoldier() const override {
        return healthPerSoldier;
    }
    int getDamagePerSoldier() const override {
        return damagePerSoldier;
    }
    int getDefencePerSoldier() const override {
        return defencePerSoldier;
    }
    int getAmountOfSoldiersPerUnit() const override {
        return amountOfSoldiersPerUnit;
    }
    std::string getUnitName() const override {
        return unitName;
    }
};
#endif
