#ifndef SPEEDCONTROL_H
#define SPEEDCONTROL_H
#pragma once

#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/irq.h"
#include "hardware/timer.h"
#include "hardware/clocks.h"

constexpr double PI = 3.14159265358979323846;
constexpr double WHEEL_DIAMETER = 3.3;
constexpr double duration = 200;
constexpr double WP = 2 * PI * WHEEL_DIAMETER;

class SpeedEncoder{
public:
    SpeedEncoder(int pinL, int pinR);
    ~SpeedEncoder();
    void getSpeed(int speed);
    int getEncoderCount(uint8_t pin);
private:
    uint8_t pinL;
    uint8_t pinR;
    int currentSpeed;
    volatile int encoderCountL;
    volatile int encoderCountR;
    static SpeedEncoder* instance;
    static void gpio_callback_trampoline(uint gpio, uint32_t events);
    static void gpio_callback(uint gpio, uint32_t events);

    //repeating_timer_t *timer;
};

#endif // SPEEDCONTROL_H