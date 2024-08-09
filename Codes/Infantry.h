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

    Soldiers* clonis() const override {
        return new Infantry(*this);
    }

    void prepare() override {
        std::cout << "Infantry preparing by forming a tight defensive formation.\n";
    }

    void execute() override {
        std::cout << "Infantry executing attack!\n";
    }

    void retreat() override {
        std::cout << "Infantry retreating!\n";
    }

    void rest() override {
        std::cout << "Infantry resting and regaining strength.\n";
    }
};
#endif
