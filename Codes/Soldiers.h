#ifndef Soldiers_H
#define Soldiers_H

#include <string>
#include "Memento.h"

class Soldiers {
    private:
        int healthPerSoldier;
        int damagePerSoldier;
        int defencePerSoldier;
        int amountOfSoldiersPerUnit;
        std::string unitName;

    public:
        void setHealthPerSoldier(int health) { healthPerSoldier = health; }
        void setDamagePerSoldier(int damage) { damagePerSoldier = damage; }
        void setDefencePerSoldier(int defence) { defencePerSoldier = defence; }
        void setAmountOfSoldiersPerUnit(int amount) { amountOfSoldiersPerUnit = amount; }
        void setUnitName(const std::string &name) { unitName = name; }

    public:
        virtual ~Soldiers() = default;
        int getHealthPerSoldier() const { return healthPerSoldier; }
        int getDamagePerSoldier() const { return damagePerSoldier; }
        int getDefencePerSoldier() const { return defencePerSoldier; }
        int getAmountOfSoldiersPerUnit() const { return amountOfSoldiersPerUnit; }
        std::string getUnitName() const { return unitName; }

        Memento * militusMemento(){
            return new Memento(this->healthPerSoldier, this->damagePerSoldier, this->defencePerSoldier, this->amountOfSoldiersPerUnit, this->unitName);
        }
        void vivificaMemento (Memento * mem){
            if (mem) {
                setHealthPerSoldier(mem->getHealthPerSoldier());
                setDamagePerSoldier(mem->getDamagePerSoldier());
                setDefencePerSoldier(mem->getDefencePerSoldier());
                setAmountOfSoldiersPerUnit(mem->getAmountOfSoldiersPerUnit());
                setUnitName(mem->getUnitName());
            }
        }
};
#endif
