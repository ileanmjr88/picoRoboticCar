#ifndef MOTORCONTROL_H
#define MOTORCONTROL_H

#include <cstdint>
#include "pico/stdlib.h"
#include "hardware/pwm.h"


class MotorControl{
    public:
        MotorControl(int pinA, int pinB);
        void forward(uint16_t speed);
        void reverse(uint16_t speed);
        void stop();

    private:
        int pinA;
        int pinB;
        uint16_t maxSpeed = 0xffff;
        unsigned int pwmSlice;
        unsigned int pinChannel;
        void m_init();
};

#endif // MOTORCONTROL_H