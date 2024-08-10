#ifndef Memento_H
#define Memento_H

#include <string>

class Memento {
    private:
        int healthPerSoldier;
        int damagePerSoldier;
        int defencePerSoldier;
        int amountOfSoldiersPerUnit;
        std::string unitName;

    public:
        Memento(int health, int damage, int defence, int amount, const std::string &name){
        // refence wcause it fetches same name and dopesnt mistekanly create new object instance of same name
            this->healthPerSoldier = health;
            this->damagePerSoldier = damage;
            this->defencePerSoldier = defence;
            this->amountOfSoldiersPerUnit = amount;
            this->unitName = name;
        }
        int getHealthPerSoldier() const { return healthPerSoldier; }
        int getDamagePerSoldier() const { return damagePerSoldier; }
        int getDefencePerSoldier() const { return defencePerSoldier; }
        int getAmountOfSoldiersPerUnit() const { return amountOfSoldiersPerUnit; }
        std::string getUnitName() const { return unitName; } 

};
#endif
