#ifndef BFS_TRAVERSAL_H
#define BFS_TRAVERSAL_H

#include <queue>
#include "Traversal.h"
#include "FarmUnit.h"

class BFSTraversal : public Traversal {
private:
    std::queue<FarmUnit*> farmQueue;
    FarmUnit* current;

public:
    BFSTraversal(FarmUnit* startUnit) {
        farmQueue.push(startUnit);
        current = nullptr;
    }

    void firstFarm() override {
        if (!farmQueue.empty()) {
            current = farmQueue.front();
        }
    }

    void next() override {
        if (isDone()) return;

        // Process the current unit
        current = farmQueue.front();
        farmQueue.pop();

        // Add child units to the queue
        for (int i = 0; i < current->getChildCount(); ++i) {
            FarmUnit* child = current->getChild(i);
            farmQueue.push(child);
        }
    }

    bool isDone() const override {
        return farmQueue.empty();
    }

    FarmUnit* currentFarm() const override {
        return current;
    }
};

#endif // BFS_TRAVERSAL_H
