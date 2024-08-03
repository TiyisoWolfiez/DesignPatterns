#ifndef InfantryFactory_H
#define InfantryFactroy_H

#include "SoldierFactory.h"
#include "Infantry.h"

class InfantryFactory : public SoldierFactory {
    public:
        Soldiers * createUnit() {
            return new Infantry();
        }
        int calculateTotalHealthPerUnit() override;
        int calculateTotalDamagePerUnit() override;
        int calculateTotalDefencePerUnit() override;
};
#endif
