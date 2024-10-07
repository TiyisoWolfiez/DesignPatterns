#ifndef SMARTDEVICE_H
#define SMARTDEVICE_H

#include <string>

class SmartDevice { //component object and observer 
    public:
        virtual std::string getStatus() const = 0;      // is this not state??'
        virtual void performAction() = 0;
        virtual std::string getDeviceType() const = 0;
        virtual ~SmartDevice() = default;
        virtual void update() {
            performAction();
        }
        

        // The Observer interface requires the implementation of update()
        // We can make this function call performAction() to take a specific action when notified
        /*virtual void update() update(const std::string& notification) = 0;
            performAction(); // Perform the action when a notification is received
        */

};

#endif
