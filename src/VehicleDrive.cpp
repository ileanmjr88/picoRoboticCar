#include "VehicleDrive.h"


VehicleDrive::VehicleDrive(const std::array<MotorPins, 4>& pins)
    : frontLeft(pins[0].pinA, pins[0].pinB),
      frontRight(pins[1].pinA, pins[1].pinB),
      backLeft(pins[2].pinA, pins[2].pinB),
      backRight(pins[3].pinA, pins[3].pinB) {
    // Constructor implementation
}

void VehicleDrive::forward(uint16_t speed){
    this->frontLeft.forward(speed);
    this->frontRight.forward(speed);
    this->backLeft.forward(speed);
    this->backRight.forward(speed);
}

void VehicleDrive::reverse(uint16_t speed){
    this->frontLeft.reverse(speed);
    this->frontRight.reverse(speed);
    this->backLeft.reverse(speed);
    this->backRight.reverse(speed);
}

void VehicleDrive::stop(){
    this->frontLeft.stop();
    this->frontRight.stop();
    this->backLeft.stop();
    this->backRight.stop();
}
