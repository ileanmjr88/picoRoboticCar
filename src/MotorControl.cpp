#include "MotorControl.h"
#include "pico/stdlib.h"
#include "hardware/pwm.h"

MotorControl::MotorControl(){
    this->pinA = -1;
    this->pinB = -1;
}

MotorControl::MotorControl(int pinA, int pinB){
    this->pinA = pinA;
    this->pinB = pinB;
    this->m_init();
}

void MotorControl::setPins(int pinA, int pinB){
    this->pinA = pinA;
    this->pinB = pinB;
}

void MotorControl::m_init(){
    // Pin A for H-bridge motor drive
    gpio_set_function(this->pinA, GPIO_FUNC_PWM);
    uint slice_numA = pwm_gpio_to_slice_num(this->pinA);
    uint channelA = pwm_gpio_to_channel(this->pinA);

    // Pin B for H-bridge motor drive
    gpio_set_function(this->pinB, GPIO_FUNC_PWM);
    uint slice_numB = pwm_gpio_to_slice_num(this->pinB);
    uint channelB = pwm_gpio_to_channel(this->pinB);
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
