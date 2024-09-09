#ifndef TRAVERSAL_H
#define TRAVERSAL_H

#include "Farm.h"

/**
 * @class Traversal
 * @brief Abstract base class for different traversal strategies of farm units.
 * 
 * This class defines the interface for traversing through farm units. Different traversal strategies,
 * such as breadth-first and depth-first search, should derive from this class and implement its methods
 * to provide specific traversal mechanisms.
 */
class Traversal {
public:
    /**
     * @brief Initializes the traversal to the first farm unit.
     * 
     * Pure virtual function that must be implemented by derived classes to set up the traversal
     * to start from the first farm unit.
     */
    virtual void firstFarm() = 0;

    /**
     * @brief Advances to the next farm unit in the traversal.
     * 
     * Pure virtual function that must be implemented by derived classes to move the traversal
     * to the next farm unit.
     */
    virtual void next() = 0;

    /**
     * @brief Checks if the traversal is complete.
     * 
     * Pure virtual function that must be implemented by derived classes to determine if the traversal
     * has finished visiting all farm units.
     * 
     * @return bool True if the traversal is complete, false otherwise.
     */
    virtual bool isDone() const = 0;

    /**
     * @brief Gets the current farm unit in the traversal.
     * 
     * Pure virtual function that must be implemented by derived classes to return the current
     * farm unit being visited by the traversal.
     * 
     * @return FarmUnit* Pointer to the current farm unit.
     */
    virtual FarmUnit* currentFarm() const = 0;

    /**
     * @brief Virtual destructor for Traversal.
     * 
     * Ensures proper cleanup of derived classes.
     */
    virtual ~Traversal() {}
};

#endif // TRAVERSAL_H