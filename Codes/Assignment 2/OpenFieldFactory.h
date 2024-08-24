#ifndef OPENFIELDFACTORY_H
#define OPENFIELDFACTORY_H

#include "LegionFactory.h"
#include "OpenFieldInfantry.h"
#include "OpenFieldCavalry.h"
#include "OpenFieldArtillery.h"

class OpenFieldFactory : public LegionFactory {
public:
    Infantry* createInfantry() override {
        return new OpenFieldInfantry();
    }
    
    Cavalry* createCavalry() override {
        return new OpenFieldCavalry();
    }
    
    Artillery* createArtillery() override {
        return new OpenFieldArtillery();
    }
};

#endif // OPENFIELDFACTORY_H
