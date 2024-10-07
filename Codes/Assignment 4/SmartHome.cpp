#include "SmartHome.h"
#include <iostream>

  SmartHome::SmartHome() {
        // Instantiate rooms and add them to the vector
        rooms.push_back(new Room("Living Room"));
        rooms.push_back(new Room("Kitchen"));
        rooms.push_back(new Room("Bedroom"));
    }

    
SmartHome::~SmartHome() {
    for (auto room : rooms) {
        delete room;
    }
}

void SmartHome::addRoom(Room* room) {
    rooms.push_back(room);
}

void SmartHome::performActionOnAllDevices() {
    for (Room* room : rooms) {
        for (SmartDevice* device : room->getDevices()) {
            device->performAction(); // Perform action (e.g., toggle)
        }
    }
}

void SmartHome::showStatus() const {
    for (const Room* room : rooms) {
        std::cout << "Room: " << room->getName() << std::endl;
        for (const SmartDevice* device : room->getDevices()) {
            std::cout << "  " << device->getDeviceType() << ": " << device->getStatus() << std::endl;
        }
    }
}

const std::vector<Room*>& SmartHome::getRooms() const {
    return rooms;
}
