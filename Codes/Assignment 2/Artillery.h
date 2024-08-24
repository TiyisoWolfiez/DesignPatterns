#ifndef ARTILLERY_H
#define ARTILLERY_H

#include "LegionUnit.h"
#include "UnitComponent.h"

class Artillery : public LegionUnit, public UnitComponent {
public:
    virtual ~Artillery() {}
};

#endif // ARTILLERY_H
