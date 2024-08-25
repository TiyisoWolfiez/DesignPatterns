#ifndef RIVERBANKFACTORY_H
#define RIVERBANKFACTORY_H

#include "LegionFactory.h"
#include "RiverbankUnits.h"

class RiverbankFactory : public LegionFactory {
public:
    UnitComponent* createInfantry() override {
        return new RiverbankInfantry();
    }
    UnitComponent* createCavalry() override {
        return new RiverbankCavalry();
    }
    UnitComponent* createArtillery() override {
        return new RiverbankArtillery();
    }
};

#endif // RIVERBANKFACTORY_H
