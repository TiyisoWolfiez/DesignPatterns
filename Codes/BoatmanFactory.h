#ifndef ShieldBearerFactory_H
#define ShieldBearerFactory_H

#include "SoldierFactory.h"
#include "Boatman.h"


class BoatmanFactory : public SoldierFactory {
public:
    Soldiers* createUnit() override {
        return new Boatman();
    }
    int calculateTotalHealthPerUnit() override;
    int calculateTotalDamagePerUnit() override;
    int calculateTotalDefencePerUnit() override;
};
#endif
