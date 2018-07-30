#ifndef PushButton_h
#define PushButton_h

#include "Arduino.h"
#include "callback.h"

/*
    Momentary button class with builtin debouncing.
    Calls press_callback when pressed.
    Written by Killian Meersman <killian.meersman@gmail.com> 2018
*/
class PushButton {
public:
    PushButton() {}
    PushButton(byte pin, bool pullup, Callback press_callback = NULL, int debounce_delay = 50);
    void update(unsigned long delta);
    bool is_pressed();
    void set_press_callback(Callback callback);

private:
    byte pin;
    bool pressed_mode;
    bool last_state = false;
    bool debounced_state = false;
    unsigned long last_debounce = 0;
    int debounce_delay;
    Callback press_callback;
};

#endif