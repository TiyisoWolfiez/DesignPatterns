#ifndef TACTICALMEMENTO_H
#define TACTICALMEMENTO_H

#include "BattleStrategy.h"

class TacticalMemento {
private:
    BattleStrategy* strategy;

public:
    TacticalMemento(BattleStrategy* strat) : strategy(strat) {}

    BattleStrategy* getStoredStrategy() const {
        return strategy;
    }
};

#endif // TACTICALMEMENTO_H
