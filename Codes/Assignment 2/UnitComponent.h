#ifndef UNITCOMPONENT_H
#define UNITCOMPONENT_H

class UnitComponent {
public:
    virtual void move() = 0;
    virtual void attack() = 0;
    virtual void add(UnitComponent* component) {}
    virtual void remove(UnitComponent* component) {}
    virtual ~UnitComponent() = default;
};

#endif // UNITCOMPONENT_H
