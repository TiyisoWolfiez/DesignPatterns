#ifndef AMBUSH_H
#define AMBUSH_H

#include "BattleStrategy.h"

class Ambush : public BattleStrategy {
public:
    void engage() override {
        std::cout << "Executing ambush tactic." << std::endl;
    }
};

#endif // AMBUSH_H
