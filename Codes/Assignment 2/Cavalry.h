#ifndef CAVALRY_H
#define CAVALRY_H

#include "UnitComponent.h"
#include <iostream>

class Cavalry : public UnitComponent {
public:
    void move() override {
        std::cout << "Cavalry moving." << std::endl;
    }
    void attack() override {
        std::cout << "Cavalry fighting." << std::endl;
    }
};

#endif // CAVALRY_H
