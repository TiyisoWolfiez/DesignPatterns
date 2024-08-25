#ifndef WOODLANDUNITS_H
#define WOODLANDUNITS_H

#include "UnitComponent.h"
#include <iostream>

class WoodlandInfantry : public UnitComponent {
public:
    void move() override {
        std::cout << "Woodland Infantry moving through the woodland terrain." << std::endl;
    }
    void attack() override {
        std::cout << "Woodland Infantry attacking from the woodland terrain." << std::endl;
    }
};

class WoodlandCavalry : public UnitComponent {
public:
    void move() override {
        std::cout << "Woodland Cavalry moving swiftly through the woodland." << std::endl;
    }
    void attack() override {
        std::cout << "Woodland Cavalry charging through the woodland." << std::endl;
    }
};

class WoodlandArtillery : public UnitComponent {
public:
    void move() override {
        std::cout << "Woodland Artillery positioning in the woodland." << std::endl;
    }
    void attack() override {
        std::cout << "Woodland Artillery firing from the woodland." << std::endl;
    }
};

#endif // WOODLANDUNITS_H
