#pragma once
#include "VehicleDrive.h"
#include "MotorControl.h"
#include <array>

VehicleDrive::VehicleDrive(const std::array<int, 8>& pins)
    : frontLeft(pins[0], pins[1]),
      frontRight(pins[2], pins[3]),
      backLeft(pins[4], pins[5]),
      backRight(pins[6], pins[7]) {
    // Constructor implementation
}

void VehicleDrive::forward(){
    this->frontLeft.forward();
    this->frontRight.forward();
    this->backLeft.forward();
    this->backRight.forward();
}

void VehicleDrive::reverse(){
    this->frontLeft.reverse();
    this->frontRight.reverse();
    this->backLeft.reverse();
    this->backRight.reverse();
}

void VehicleDrive::stop(){
    this->frontLeft.stop();
    this->frontRight.stop();
    this->backLeft.stop();
    this->backRight.stop();
}
