#ifndef TRUCK_H
#define TRUCK_H

#include <string>

class Truck {
public:
    virtual ~Truck() {}

    virtual void startEngine() = 0;
    virtual void operate() = 0;  // Specific operation like delivering fertilizer or collecting crops
};

#endif // TRUCK_H
