#ifndef CareTaker_H
#define CareTaker_H

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
        if(index >= 0 && index < mementoList.size()) {
            return mementoList[index];
        }
        return nullptr;
    }
    ~CareTaker() {
        for (Memento* memento : mementoList) {
            delete memento;
        }
    }
};
#endif
