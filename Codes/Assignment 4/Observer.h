// Observer.h
#ifndef OBSERVER_H
#define OBSERVER_H

#include <string>

class Observer {
public:
    virtual void update(const std::string& notification) = 0; // Method to receive updates
};

#endif // OBSERVER_H
