#ifndef Soldiers_H
#define Soldiers_H

#include <string>

class Soldiers {
    private:
        int healthPerSoldier;
        int damagePerSoldier;
        int defencePerSoldier;
        int amountOfSoldierPerUnit;
        std::string unitName;
    public:
        virtual ~Soldiers() = default;
        virtual int getHealthPerSoldier() const = 0;
        virtual int getDamagePerSoldier() const = 0;
        virtual int getDefencePerSoldier() const = 0;
        virtual int getAmountOfSoldiersPerUnit() const = 0;
        virtual std::string getUnitName() const = 0;
};
#endif
