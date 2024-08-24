#ifndef INFANTRY_H
#define INFANTRY_H

#include "LegionUnit.h"
#include "UnitComponent.h"

class Infantry : public LegionUnit, public UnitComponent {
public:
    virtual ~Infantry() {}
};

#endif // INFANTRY_H
