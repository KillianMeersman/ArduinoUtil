#ifndef MultiButton_h
#define MultiButton_h

#include "Arduino.h"
#include "callback.h"

/*
    Momentary button class with builtin debouncing, supports both short and sustained presses.
    Calls press_callback when pressed and released before the hold_duration.
    Calls hold_callback when held for longer than hold_duration and calls release_callback when released from a sustained press.
    Written by Killian Meersman <killian.meersman@gmail.com> 2018
*/
class MultiButton {
public:
    MultiButton() {}
    MultiButton(byte pin, bool pullup, unsigned long hold_duration, Callback press_callback = NULL,
        Callback hold_callback = NULL, Callback release_callback = NULL, int debounce_delay = 50);
    void update();
    bool is_pressed();
    void set_press_callback(Callback callback);
    void set_hold_callback(Callback callback);
    void set_release_callback(Callback callback);

private:
    byte pin;
    bool pressed_mode;
    bool long_press = false;
    bool last_state = false;
    bool debounced_state = false;
    unsigned long last_debounce = 0;
    unsigned long hold_duration;
    int debounce_delay;
    Callback press_callback, hold_callback, release_callback;
};

#endif