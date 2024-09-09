#ifndef DFS_TRAVERSAL_H
#define DFS_TRAVERSAL_H

#include <stack>
#include "Traversal.h"
#include "FarmUnit.h"

/**
 * @class DFSTraversal
 * @brief Implements depth-first search (DFS) traversal for farm units.
 * 
 * This class derives from the `Traversal` base class and provides
 * a depth-first traversal mechanism for iterating over farm units.
 * It uses a stack to keep track of the traversal state.
 */
class DFSTraversal : public Traversal {
private:
    std::stack<FarmUnit*> farmStack; ///< Stack to manage DFS traversal.
    FarmUnit* current; ///< Pointer to the current farm unit in traversal.

public:
    /**
     * @brief Constructs a DFS traversal object starting from a specific unit.
     * 
     * @param startUnit Pointer to the initial farm unit to start traversal.
     */
    DFSTraversal(FarmUnit* startUnit) {
        farmStack.push(startUnit);
        current = nullptr;
    }

    /**
     * @brief Initializes the traversal to the first farm unit.
     * 
     * Sets the current farm unit to the top of the stack if it is not empty.
     */
    void firstFarm() override {
        if (!farmStack.empty()) {
            current = farmStack.top();
        }
    }

    /**
     * @brief Advances to the next farm unit in the DFS traversal.
     * 
     * Pops the current farm unit from the stack, processes it, and
     * pushes its child units onto the stack.
     */
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

    /**
     * @brief Checks if the traversal is complete.
     * 
     * @return true if the stack is empty and traversal is done, false otherwise.
     */
    bool isDone() const override {
        return farmStack.empty();
    }

    /**
     * @brief Gets the current farm unit in the traversal.
     * 
     * @return Pointer to the current farm unit.
     */
    FarmUnit* currentFarm() const override {
        return current;
    }
};

#endif // DFS_TRAVERSAL_H
