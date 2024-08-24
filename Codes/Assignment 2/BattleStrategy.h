#ifndef BATTLESTRATEGY_H
#define BATTLESTRATEGY_H

class BattleStrategy {
public:
    virtual void engage() = 0;
    virtual ~BattleStrategy() {}
};

#endif // BATTLESTRATEGY_H
