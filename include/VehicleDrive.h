#ifndef VEHICLEDRIVE_H
#define VEHICLEDRIVE_H

#include <array>
#include "VehicleDrive.h"
#include "MotorControl.h"

struct MotorPins{
    int pinA;
    int pinB;
};

class VehicleDrive{
    public:
        VehicleDrive(const std::array<MotorPins, 4>& pins);
        void forward(uint16_t speed);
        void reverse(uint16_t speed); 
        void stop();
        
    private:
        MotorControl frontLeft;
        MotorControl frontRight;
        MotorControl backLeft;
        MotorControl backRight;
};

#endif // VEHICLEDRIVE_H