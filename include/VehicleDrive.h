#ifndef VEHICLEDRIVE_H
#define VEHICLEDRIVE_H

#include <array>
#include "VehicleDrive.h"
#include "MotorControl.h"

class VehicleDrive{
    public:
        VehicleDrive(const std::array<int, 8>& pins);
        void forward();
        void reverse(); 
        void stop();
        
    private:
        MotorControl frontLeft;
        MotorControl frontRight;
        MotorControl backLeft;
        MotorControl backRight;
};

#endif // VEHICLEDRIVE_H