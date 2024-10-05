#include "Room.h"

Room::Room(const std::string& name) : name(name) {}

void Room::addDevice(SmartDevice* device) {
    devices.push_back(device);
}

const std::vector<SmartDevice*>& Room::getDevices() const {
    return devices;
}

std::string Room::getName() const {
    return name;
}
