#ifndef LEGION_H
#define LEGION_H

#include "UnitComponent.h"
#include <vector>
#include <algorithm>

class Legion : public UnitComponent {
private:
    std::vector<UnitComponent*> components;

public:
    void move() override {
        for (auto component : components) {
            component->move();
        }
    }

    void attack() override {
        for (auto component : components) {
            component->attack();
        }
    }

    void add(UnitComponent* component) override {
        components.push_back(component);
    }

    void remove(UnitComponent* component) override {
        components.erase(std::remove(components.begin(), components.end(), component), components.end());
    }

    ~Legion() {
        for (auto component : components) {
            delete component;
        }
    }
};

#endif // LEGION_H
