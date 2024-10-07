#include "Light.h"
#include <iostream>

Light::Light() : isOn(false) {}

std::string Light::getStatus() const {
    return isOn ? "on" : "off";
}

void Light::performAction() {
    isOn = !isOn; // Toggle the light
    std::cout << "Light is On" << getStatus() << std::endl;
}

std::string Light::getDeviceType() const {
    return "Light";
}
