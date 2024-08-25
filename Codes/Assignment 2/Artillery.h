#ifndef ARTILLERY_H
#define ARTILLERY_H

#include "UnitComponent.h"
#include <iostream>

class Artillery : public UnitComponent {
public:
    void move() override {
        std::cout << "Artillery moving." << std::endl;
    }
    void attack() override {
        std::cout << "Artillery fighting." << std::endl;
    }
};

#endif // ARTILLERY_H
