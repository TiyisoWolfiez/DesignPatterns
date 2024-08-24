#ifndef WARARCHIVES_H
#define WARARCHIVES_H

#include "TacticalMemento.h"
#include <map>
#include <string>

class WarArchives {
private:
    std::map<std::string, TacticalMemento*> mementoArchive;

public:
    void addTacticalMemento(TacticalMemento* memento, const std::string& label) {
        mementoArchive[label] = memento;
    }

    void removeTacticalMemento(const std::string& label) {
        mementoArchive.erase(label);
    }

    TacticalMemento* getTacticalMemento(const std::string& label) const {
        auto it = mementoArchive.find(label);
        return (it != mementoArchive.end()) ? it->second : nullptr;
    }
};

#endif // WARARCHIVES_H
