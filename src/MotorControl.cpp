
#include "MotorControl.h"

MotorControl::MotorControl(int pinA, int pinB){
    this->pinA = pinA;
    this->pinB = pinB;

    gpio_init(pinA);
    gpio_set_dir(pinA, GPIO_OUT);
    gpio_init(pinB);
    gpio_set_dir(pinB, GPIO_OUT);

    this->m_init();
}


void MotorControl::m_init(){
    // Pin A for H-bridge motor drive
    gpio_set_function(pinA, GPIO_FUNC_PWM);
    pwmSlice = pwm_gpio_to_slice_num(this->pinA);
    pinChannel = pwm_gpio_to_channel(this->pinA);
    pwm_set_wrap(pwmSlice, maxSpeed);
    pwm_set_chan_level(pwmSlice, pinChannel, 0);
    pwm_set_enabled(pwmSlice, true);
}

void MotorControl::forward(uint16_t speed){
    pwm_set_chan_level(pwmSlice, pinChannel, speed);
    gpio_put(pinA, true);
    gpio_put(pinB, false);
}

void MotorControl::reverse(uint16_t speed){
    pwm_set_chan_level(pwmSlice, pinChannel, speed);
    gpio_put(pinB, true);
    gpio_put(pinA, false);
}

void MotorControl::stop(){
    pwm_set_chan_level(pwmSlice, pinChannel, 0);
    gpio_put(pinA, true);
    gpio_put(pinB, true);
}
