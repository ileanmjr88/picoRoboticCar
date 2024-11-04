#include <stdio.h>
#include "pico/stdlib.h"
#include "pico/stdio_usb.h"
#include "hardware/pwm.h"
#include "../include/VehicleDrive.h"
#include <array>

// UART defines
// By default the stdout UART is `uart0`, so we will use the second one
#define UART_ID uart1
#define BAUD_RATE 115200

int main() {
    stdio_usb_init();
    int delay = 2000;
    const std::array<int, 8> pins = {17, 16, 14, 15, 13, 12, 10, 11};
    VehicleDrive vehicle = VehicleDrive(pins);

    vehicle.forward();
    sleep_ms(delay);
    vehicle.reverse();
    sleep_ms(delay);
    vehicle.stop();
}
