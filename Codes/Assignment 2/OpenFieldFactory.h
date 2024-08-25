#ifndef OPENFIELDFACTORY_H
#define OPENFIELDFACTORY_H

#include "LegionFactory.h"
#include "OpenFieldUnits.h"

class OpenFieldFactory : public LegionFactory {
public:
    UnitComponent* createInfantry() override {
        return new OpenFieldInfantry();
    }
    UnitComponent* createCavalry() override {
        return new OpenFieldCavalry();
    }
    UnitComponent* createArtillery() override {
        return new OpenFieldArtillery();
    }
};

#endif // OPENFIELDFACTORY_H
