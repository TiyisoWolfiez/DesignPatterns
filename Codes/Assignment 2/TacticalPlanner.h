#ifndef TACTICALPLANNER_H
#define TACTICALPLANNER_H

#include "BattleStrategy.h"
#include "TacticalMemento.h"

class TacticalPlanner {
private:
    BattleStrategy* currentStrategy;

public:
    void setStrategy(BattleStrategy* strategy) {
        currentStrategy = strategy;
    }

    TacticalMemento* createMemento() {
        return new TacticalMemento(currentStrategy);
    }

    void restoreMemento(TacticalMemento* memento) {
        currentStrategy = memento->getStoredStrategy();
    }

    BattleStrategy* getCurrentStrategy() const {
        return currentStrategy;
    }
};

#endif // TACTICALPLANNER_H
