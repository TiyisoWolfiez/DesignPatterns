#ifndef TACTICALCOMMAND_H
#define TACTICALCOMMAND_H

#include "BattleStrategy.h"
#include "TacticalPlanner.h"
#include "WarArchives.h"

class TacticalCommand {
private:
    TacticalPlanner planner;
    WarArchives archives;

public:
    void setStrategy(BattleStrategy* strategy) {
        planner.setStrategy(strategy);
    }

    void executeStrategy() {
        if (planner.getStrategy()) {
            planner.getStrategy()->engage();
        }
    }

    void saveCurrentStrategy(const std::string& label) {
        TacticalMemento* memento = planner.createMemento();
        archives.addTacticalMemento(memento, label);
    }

    void restoreStrategy(const std::string& label) {
        TacticalMemento* memento = archives.getTacticalMemento(label);
        if (memento) {
            planner.restoreMemento(memento);
        }
    }

    void chooseBestStrategy() {
        // Logic to choose the best strategy based on stored mementos.
    }
};

#endif // TACTICALCOMMAND_H
