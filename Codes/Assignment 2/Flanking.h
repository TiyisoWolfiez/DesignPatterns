#ifndef FLANKING_H
#define FLANKING_H

#include "BattleStrategy.h"
#include <iostream>

class Flanking : public BattleStrategy {
public:
    void engage() override {
        std::cout << "Executing flanking maneuver." << std::endl;
    }
};

#endif // FLANKING_H
