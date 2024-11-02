#ifndef MOTORCONTROL_H
#define MOTORCONTROL_H


class MotorControl{
    public:
        MotorControl();
        MotorControl(int pinA, int pinB);
        void forward();
        void reverse();
        void stop();

    private:
        int pinA;
        int pinB;
};

#endif // MOTORCONTROL_H