#ifndef WOODLANDFACTORY_H
#define WOODLANDFACTORY_H

#include "LegionFactory.h"
#include "WoodlandUnits.h"

class WoodlandFactory : public LegionFactory {
public:
    UnitComponent* createInfantry() override {
        return new WoodlandInfantry();
    }
    UnitComponent* createCavalry() override {
        return new WoodlandCavalry();
    }
    UnitComponent* createArtillery() override {
        return new WoodlandArtillery();
    }
};

#endif // WOODLANDFACTORY_H
