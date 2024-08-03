#ifndef SoldierFactory_H
#define SoldierFactory_H

#include "Soldiers.h"

class SoldierFactory {
    private:
        Soldiers * soldiers;
    protected:
        virtual Soldiers * createUnit() = 0;
        virtual int calculateTotalHealthPerUnit() = 0;
        virtual int calculateTotalDamagePerUnit() = 0;
        virtual int calculateTotalDefencePerUnit() = 0;
};
#endif
