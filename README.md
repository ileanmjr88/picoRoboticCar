# picoRoboticCar
## Table of Contents
- [Introduction](#introduction)
- [Kit and Software Tools](#kit-and-software-tools)
    - [Hardware](#hardware)
    - [Software](#software)
- [Todo list](#todo-list)
    - [Low Level](#low-level)
    - [Behavior](#behavior)
- [Documentation and Useful Links](#documentation-and-useful-links)
    - [Documentation](#documentation)
    - [Useful Links](#useful-links)
- [License](#license)

## Introduction
The picoRoboticCar is a project that involves building and programming a robotic car using a Raspberry Pi Pico. This project aims to provide a hands-on experience with Raspberry Pi Pico. I have not use this microcontroller and like that you can use C/C++ or a version of python called MicroPython.

For this project I have decided to implement as much as possible from scratch using C and C++.

## Kit and Software Tools
### Hardware
- Robotic Car Kit, this is the one I purchased [SunFounder Robot Car Kit](https://www.amazon.com/dp/B09DP1QFPN?th=1)
    - It includes everything you need for the car
- Rasberry Pi Debug Probe

### Software
- Visual Studio Code
- [Install Rasberry Pi Pico extension](https://marketplace.visualstudio.com/items?itemName=raspberry-pi.raspberry-pi-pico)
    - I discovered this extension will do the full installation of the toolchain

## Todo list
### Low Level
- [ ] Motor Control with PWM
    - [ ] Clockwise
    - [ ] Counter clockwise
    - [ ] Stop
    - [ ] Variable speed control
- [ ] Vehicle Control
    - [ ] Forward
    - [ ] Reverse
    - [ ] Stop
    - [ ] Left turn
    - [ ] Right turn
    - [ ] Speed control
- [ ] Wifi module driver
    - [ ] Serial communication
- [ ] Speed encoder sensor driver
- [ ] Gray scale sensor driver (for line following)
- [ ] Ultrasonic senor driver
- [ ] Servo driver
- [ ] RBG light control

### Behavior
- [ ] Line following
- [ ] Object collition avoidance 

## Documentation and Useful Links
### Documentation
- [Pico C SDK](https://www.raspberrypi.com/documentation/pico-sdk/)
- [SunFounder Pico 4WD Car V2.0 Kit](https://docs.sunfounder.com/projects/pico-4wd-v2/en/latest/index.html)
- [SunFounder Repo](https://github.com/sunfounder/pico_4wd_car/tree/v2.0)

### Useful Links
- [Pico Basic PWM](https://www.i-programmer.info/programming/hardware/14849-the-pico-in-c-basic-pwm.html)

## License
This project is licensed under the MIT License.