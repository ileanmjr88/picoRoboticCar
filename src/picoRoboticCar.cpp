#include <stdio.h>
#include "pico/stdlib.h"
#include "pico/stdio_usb.h"
#include "hardware/pwm.h"
#include "VehicleDrive.h"
#include "MotorControl.h"
#include "SpeedEncoder.h"
#include <array>

// UART defines
// By default the stdout UART is `uart0`, so we will use the second one
#define UART_ID uart1
#define BAUD_RATE 115200


int main(){
    stdio_usb_init();

    int delay = 2000;
    // Motor pins
    const std::array<MotorPins, 4> pins = {
        {MotorPins{17, 16}, MotorPins{14, 15}, MotorPins{13, 12}, MotorPins{10, 11}}};

    SpeedEncoder speedEncoder(8, 9);

    while (!stdio_usb_connected()) { sleep_ms(100); }

    VehicleDrive vehicle(pins);
    printf("Vehicle drive initialized\n");
    while (true) {

    }

    return 0;
}
