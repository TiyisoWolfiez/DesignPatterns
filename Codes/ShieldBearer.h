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

    Soldiers* clonis() const override {
        return new ShieldBearer(*this);
    }

    void prepare() override {
        std::cout << "ShieldBearer preparing by raising shields for defense.\n";
    }

    void execute() override {
        std::cout << "ShieldBearer executing defensive maneuvers!\n";
    }

    void retreat() override {
        std::cout << "ShieldBearer retreating slowly with shields up!\n";
    }

    void rest() override {
        std::cout << "ShieldBearer resting and reinforcing shields.\n";
    }
};
#endif
