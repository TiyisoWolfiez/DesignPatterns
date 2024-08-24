#ifndef TACTICALMEMENTO_H
#define TACTICALMEMENTO_H

#include "BattleStrategy.h"

class TacticalMemento {
private:
    BattleStrategy* storedStrategy;

public:
    TacticalMemento(BattleStrategy* strategy) : storedStrategy(strategy) {}

    BattleStrategy* getStoredStrategy() const {
        return storedStrategy;
    }
};

#endif // TACTICALMEMENTO_H
