#ifndef FORTIFICATION_H
#define FORTIFICATION_H

#include "BattleStrategy.h"
#include <iostream>

class Fortification : public BattleStrategy {
public:
    void engage() override {
        std::cout << "Executing fortification strategy." << std::endl;
    }
};

#endif // FORTIFICATION_H
