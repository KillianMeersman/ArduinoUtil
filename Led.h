#ifndef Led_h
#define Led_h

#include "Arduino.h"

class Led {
public:
    Led() {}
    Led(byte pin);
    void set(bool on);
    void toggle();
    bool is_on();

private:
    byte pin;
    bool state;
};

#endif