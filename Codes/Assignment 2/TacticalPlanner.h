#ifndef TACTICALPLANNER_H
#define TACTICALPLANNER_H

#include "BattleStrategy.h"
#include "TacticalMemento.h"

class TacticalPlanner {
private:
    BattleStrategy* currentStrategy;

public:
    TacticalPlanner() : currentStrategy(nullptr) {}

    void setStrategy(BattleStrategy* strategy) {
        currentStrategy = strategy;
    }

    BattleStrategy* getStrategy() {
        return currentStrategy;
    }

    TacticalMemento* createMemento() {
        return new TacticalMemento(currentStrategy);
    }

    void restoreMemento(TacticalMemento* memento) {
        currentStrategy = memento->getStoredStrategy();
    }
};

#endif // TACTICALPLANNER_H
