#ifndef Boatman_H
#define Boatman_H

#include "Soldiers.h"
#include "BoatmanFactory.h"

class Boatman : public Soldiers {
    public:
        Boatman() {
            setHealthPerSoldier(90);
            setDamagePerSoldier(60);
            setDefencePerSoldier(20);
            setAmountOfSoldiersPerUnit(12);
            setUnitName("Boatman");
        }

        Soldiers* clonis() const override {
            return new Boatman(*this);
        }

        void prepare() override {
            std::cout << "Boatman preparing by maneuvering boats into strategic positions.\n";
        }

        void execute() override {
            std::cout << "Boatman executing naval attack!\n";
        }

        void retreat() override {
            std::cout << "Boatman retreating from the water!\n";
        }

        void rest() override {
            std::cout << "Boatman resting and repairing boats.\n";
        }
};
#endif
