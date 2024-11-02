#include "MotorControl.h"
#include "pico/stdlib.h"

MotorControl::MotorControl(){
    this->pinA = 0;
    this->pinB = 0;
}

MotorControl::MotorControl(int pinA, int pinB){
    this->pinA = pinA;
    this->pinB = pinB;
    gpio_init(this->pinA);
    gpio_init(this->pinB);
    gpio_set_dir(this->pinA, GPIO_OUT);
    gpio_set_dir(this->pinB, GPIO_OUT);
}

void MotorControl::forward(){
    gpio_put(this->pinA, true);
    gpio_put(this->pinB, false);
}

void MotorControl::reverse(){
    gpio_put(this->pinA, false);
    gpio_put(this->pinB, true);
}

void MotorControl::stop(){
    gpio_put(this->pinA, true);
    gpio_put(this->pinB, true);
}