#ifndef MOTORCONTROL_H
#define MOTORCONTROL_H


class MotorControl{
    public:
        MotorControl();
        MotorControl(int pinA, int pinB);
        void setPins(int pinA, int pinB);
        void forward();
        void reverse();
        void stop();

    private:
        int pinA;
        int pinB;
        uint pwmSlice;
        uint pinAChannel;
        uint pinBChannel;
        void m_init();
};

#endif // MOTORCONTROL_H