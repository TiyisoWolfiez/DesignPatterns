#ifndef TRAVERSAL_H
#define TRAVERSAL_H

#include "Farm.h"

class Traversal {
public:
    virtual void firstFarm() = 0;
    virtual void next() = 0;
    virtual bool isDone() const = 0;
    virtual FarmUnit* currentFarm() const = 0;
    virtual ~Traversal() {}
};

#endif // TRAVERSAL_H
