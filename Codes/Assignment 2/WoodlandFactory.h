#ifndef WOODLANDFACTORY_H
#define WOODLANDFACTORY_H

#include "LegionFactory.h"
#include "WoodlandInfantry.h"
#include "WoodlandCavalry.h"
#include "WoodlandArtillery.h"

class WoodlandFactory : public LegionFactory {
public:
    Infantry* createInfantry() override {
        return new WoodlandInfantry();
    }
    
    Cavalry* createCavalry() override {
        return new WoodlandCavalry();
    }
    
    Artillery* createArtillery() override {
        return new WoodlandArtillery();
    }
};

#endif // WOODLANDFACTORY_H
