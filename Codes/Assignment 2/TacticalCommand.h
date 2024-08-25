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
        if (planner.getCurrentStrategy()) {
            planner.getCurrentStrategy()->engage();
        }
    }

    void saveCurrentStrategy(const std::string& label) {
        TacticalMemento* memento = planner.createMemento();
        archives.addTacticalMemento(memento, label);
    }

    void restoreStrategy(const std::string& label) {
        TacticalMemento* memento = archives.getTacticalMemento(label);
        planner.restoreMemento(memento);
    }

    void chooseBestStrategy() {
        // Placeholder for choosing the best strategy based on previous results
        // This would involve using the stored mementos to make informed decisions
    }
};

#endif // TACTICALCOMMAND_H
