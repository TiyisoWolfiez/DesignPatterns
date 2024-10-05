#ifndef ROOM_H
#define ROOM_H

#include <string>
#include <vector>
#include "SmartDevice.h"

class Room {
private:
    std::string name;
    std::vector<SmartDevice*> devices;

public:
    Room(const std::string& name);

    void addDevice(SmartDevice* device);
    const std::vector<SmartDevice*>& getDevices() const;
    std::string getName() const;
};

#endif // ROOM_H
