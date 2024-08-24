#ifndef UNITCOMPONENT_H
#define UNITCOMPONENT_H

class UnitComponent {
public:
    virtual void move() = 0;
    virtual void fight() = 0;
    virtual void add(UnitComponent* component) {
        // Default implementation does nothing.
    }
    virtual void remove(UnitComponent* component) {
        // Default implementation does nothing.
    }
    virtual ~UnitComponent() {}
};

#endif // UNITCOMPONENT_H
