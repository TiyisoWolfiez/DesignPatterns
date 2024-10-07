#include "DoorLock.h"
#include <iostream>

DoorLock::DoorLock() : isLocked(true) {}

std::string DoorLock::getStatus() const {
    return isLocked ? "locked" : "unlocked";
}

void DoorLock::performAction() {
    isLocked = !isLocked; // Toggle the door lock
    std::cout << "Door is Locked" << getStatus() << std::endl;
}

std::string DoorLock::getDeviceType() const {
    return "DoorLock";
}
