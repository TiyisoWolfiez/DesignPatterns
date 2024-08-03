#ifndef ShieldBearerFactory_H
#define ShieldBearerFactory_H

#include <string>
#include "SoldierFactory.h"
#include "ShieldBearer.h"

class ShieldBearerFactory : public SoldierFactory {
    public:
        Soldiers * createUnit() override {
            return new ShieldBearer();
        }
        int calculateTotalHealthPerUnit() override;
        int calculateTotalDamagePerUnit() override;
        int calculateTotalDefencePerUnit() override;
};
#endif
