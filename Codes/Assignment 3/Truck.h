#ifndef TRUCK_H
#define TRUCK_H

#include <string>

/**
 * @class Truck
 * @brief Abstract base class for different types of trucks used in farming operations.
 * 
 * This class defines the interface for trucks that can perform various operations such as delivering
 * fertilizers or collecting crops. Derived classes should implement specific operations for different
 * types of trucks.
 */
class Truck {
public:
    /**
     * @brief Virtual destructor for Truck.
     * 
     * Ensures proper cleanup of derived classes.
     */
    virtual ~Truck() {}

    /**
     * @brief Starts the truck's engine.
     * 
     * Pure virtual function that must be implemented by derived classes to start the truck's engine.
     */
    virtual void startEngine() = 0;

    /**
     * @brief Performs the truck's specific operation.
     * 
     * Pure virtual function that must be implemented by derived classes to carry out the truck's specific
     * operation, such as delivering fertilizer or collecting crops.
     */
    virtual void operate() = 0;
};

#endif // TRUCK_H