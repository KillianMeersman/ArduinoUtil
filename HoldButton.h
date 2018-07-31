#ifndef HoldButton_h
#define HoldButton_h

#include "Arduino.h"
#include "callback.h"

/*
    Momentary button with builtin debouncing.
    Calls hold_callback when held for longer than hold_duration and calls release_callback when released from a sustained press.
    Written by Killian Meersman <killian.meersman@gmail.com> 2018
*/
class HoldButton {
public:
    HoldButton() {}
    HoldButton(byte pin, bool pullup, unsigned long hold_duration, 
        Callback hold_callback = NULL, Callback release_callback = NULL, int debounce_delay = 50);
    void update();
    bool is_pressed();
    void set_hold_callback(Callback callback);
    void set_release_callback(Callback callback);

private:
    byte pin;
    bool pressed_mode;
    bool last_state = false;
    bool debounced_state = false;
    unsigned long last_debounce = 0;
    unsigned long hold_duration;
    int debounce_delay;
    Callback hold_callback, release_callback;
};

#endif