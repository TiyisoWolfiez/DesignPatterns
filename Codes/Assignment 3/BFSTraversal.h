// BFS_Traversal.h
#ifndef BFS_TRAVERSAL_H
#define BFS_TRAVERSAL_H

#include <queue>
#include "Traversal.h"
#include "FarmUnit.h"

/**
 * @class BFSTraversal
 * @brief Performs a Breadth-First Search (BFS) traversal on the farm units.
 * 
 * This class implements the Breadth-First Search (BFS) algorithm to traverse
 * through the `FarmUnit` hierarchy, starting from a given initial unit. It
 * processes each unit level by level.
 */
class BFSTraversal : public Traversal {
private:
    std::queue<FarmUnit*> farmQueue; /**< Queue used for BFS traversal */
    FarmUnit* current; /**< The current farm unit being processed */

public:
    /**
     * @brief Constructs a BFS traversal with the starting unit.
     * @param startUnit The initial farm unit to start the traversal.
     */
    BFSTraversal(FarmUnit* startUnit) {
        farmQueue.push(startUnit);
        current = nullptr;
    }

    /**
     * @brief Initializes the traversal to the first farm unit.
     */
    void firstFarm() override {
        if (!farmQueue.empty()) {
            current = farmQueue.front();
        }
    }

    /**
     * @brief Advances the traversal to the next farm unit.
     * 
     * This method processes the current farm unit and adds its child units
     * to the queue. It should be called iteratively until the traversal is
     * complete.
     */
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

    /**
     * @brief Checks if the traversal is complete.
     * @return True if all farm units have been processed; otherwise, false.
     */
    bool isDone() const override {
        return farmQueue.empty();
    }

    /**
     * @brief Gets the current farm unit being processed.
     * @return The current farm unit.
     */
    FarmUnit* currentFarm() const override {
        return current;
    }
};

#endif // BFS_TRAVERSAL_H