#ifndef DFS_TRAVERSAL_H
#define DFS_TRAVERSAL_H

#include <stack>
#include "Traversal.h"
#include "FarmUnit.h"

class DFSTraversal : public Traversal {
private:
    std::stack<FarmUnit*> farmStack;
    FarmUnit* current;

public:
    DFSTraversal(FarmUnit* startUnit) {
        farmStack.push(startUnit);
        current = nullptr;
    }

    void firstFarm() override {
        if (!farmStack.empty()) {
            current = farmStack.top();
        }
    }

    void next() override {
        if (isDone()) return;

        // Process the current unit
        current = farmStack.top();
        farmStack.pop();

        // Add child units to the stack
        for (int i = 0; i < current->getChildCount(); ++i) {
            FarmUnit* child = current->getChild(i);
            farmStack.push(child);
        }
    }

    bool isDone() const override {
        return farmStack.empty();
    }

    FarmUnit* currentFarm() const override {
        return current;
    }
};

#endif // DFS_TRAVERSAL_H
