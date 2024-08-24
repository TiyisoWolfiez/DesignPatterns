#ifndef CareTaker_H
#define CareTaker_H

#include <string>
#include <vector>
#include "Memento.h"

class CareTaker {
    private:
        std::vector<Memento*> mementoList;

    public:
    void addMemento(Memento* memento) {
        mementoList.push_back(memento);
    }
    Memento* getMemento(int index) {
        if (index < 0 || static_cast<std::size_t>(index) >= mementoList.size()) {
            return nullptr;
        }
        return mementoList[index];
    }


    ~CareTaker() {
        for (Memento* memento : mementoList) {
            delete memento;
        }
    }
};
#endif
