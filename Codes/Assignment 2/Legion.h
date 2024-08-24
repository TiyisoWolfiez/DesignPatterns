#ifndef LEGION_H
#define LEGION_H

#include "UnitComponent.h"
#include <vector>

class Legion : public UnitComponent {
private:
    std::vector<UnitComponent*> units;

public:
    void add(UnitComponent* component) override {
        units.push_back(component);
    }

    void remove(UnitComponent* component) override {
        units.erase(std::remove(units.begin(), units.end(), component), units.end());
    }

    void move() override {
        for (UnitComponent* unit : units) {
            unit->move();
        }
    }

    void fight() override {
        for (UnitComponent* unit : units) {
            unit->fight();
        }
    }

    ~Legion() {
        for (UnitComponent* unit : units) {
            delete unit;
        }
    }
};

#endif // LEGION_H
