#include "SpeedEncoder.h"

SpeedEncoder* SpeedEncoder::instance = nullptr;

SpeedEncoder::SpeedEncoder(int pinL, int pinR){
    this->pinL = pinL;
    this->pinR = pinR;
    encoderCountL = 0;
    encoderCountR = 0;
    currentSpeed = 0;

    // Instance for non static functions
    instance = this;

    // Left Wheel Encoder
    gpio_init(pinL);
    gpio_set_dir(pinL, GPIO_IN);
    gpio_pull_up(pinL);

    // Right Wheel Encoder
    gpio_init(pinR);
    gpio_set_dir(pinR, GPIO_IN);
    gpio_pull_up(pinR);

    // Interrupts
    gpio_set_irq_enabled_with_callback(pinL, GPIO_IRQ_EDGE_FALL, true, &SpeedEncoder::gpio_callback);
    gpio_set_irq_enabled_with_callback(pinR, GPIO_IRQ_EDGE_FALL, true, &SpeedEncoder::gpio_callback);

    // Timer

}

SpeedEncoder::~SpeedEncoder(){
    gpio_set_irq_enabled(pinL, GPIO_IRQ_EDGE_FALL, false);
    gpio_set_irq_enabled(pinR, GPIO_IRQ_EDGE_FALL, false);
}

int SpeedEncoder::getEncoderCount(uint8_t pin){
    if (pin == pinL){
        return instance->encoderCountL;
    } else if (pin == pinR){
        return instance->encoderCountR;
    }
    return 0;
}

void SpeedEncoder::gpio_callback(uint gpio, uint32_t events) {
    if (instance) {
        if (gpio == instance->pinL) {
            instance->encoderCountL++;
        } else if (gpio == instance->pinR) {
            instance->encoderCountR++;
        }
    }
}