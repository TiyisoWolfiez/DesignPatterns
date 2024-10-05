#include "DoorLock.h"

DoorLock::DoorLock() : isLocked(true) {}

std::string DoorLock::getStatus() const {
    return isLocked ? "locked" : "unlocked";
}

void DoorLock::performAction() {
    isLocked = !isLocked;
}

std::string DoorLock::getDeviceType() const {
    return "DoorLock";
}
