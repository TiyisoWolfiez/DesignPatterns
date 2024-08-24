#ifndef LEGIONUNIT_H
#define LEGIONUNIT_H

class LegionUnit {
public:
    virtual void move() = 0;
    virtual void attack() = 0;
    virtual ~LegionUnit() {}
};

#endif // LEGIONUNIT_H
