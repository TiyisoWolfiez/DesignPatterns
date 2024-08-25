#ifndef LEGIONFACTORY_H
#define LEGIONFACTORY_H

#include "UnitComponent.h"

class LegionFactory {
public:
    virtual UnitComponent* createInfantry() = 0;
    virtual UnitComponent* createCavalry() = 0;
    virtual UnitComponent* createArtillery() = 0;
    virtual ~LegionFactory() = default;
};

#endif // LEGIONFACTORY_H
