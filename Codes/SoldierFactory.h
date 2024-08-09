#ifndef SoldierFactory_H
#define SoldierFactory_H

#include "Soldiers.h"

class SoldierFactory {
    private:
        Soldiers * soldiers = nullptr;
    public:
        virtual Soldiers * createUnit() = 0;
        virtual int calculateTotalHealthPerUnit() = 0;
        virtual int calculateTotalDamagePerUnit() = 0;
        virtual int calculateTotalDefencePerUnit() = 0;

        void setSoldiers(Soldiers* s) {
            if (soldiers) {
                delete soldiers;
            }
            soldiers = s;
        }

        Soldiers* getSoldiers() const { return soldiers; }
        
    public:
        virtual ~SoldierFactory() {
             delete soldiers; 
             }
};
#endif
