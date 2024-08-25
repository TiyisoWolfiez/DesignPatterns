#ifndef WARARCHIVES_H
#define WARARCHIVES_H

#include "TacticalMemento.h"
#include <map>
#include <string>

class WarArchives {
private:
    std::map<std::string, TacticalMemento*> archives;

public:
    void addTacticalMemento(TacticalMemento* memento, const std::string& label) {
        archives[label] = memento;
    }

    void removeTacticalMemento(const std::string& label) {
        archives.erase(label);
    }

    TacticalMemento* getTacticalMemento(const std::string& label) {
        return archives[label];
    }
};

#endif // WARARCHIVES_H
