#include "MultiButton.h"

MultiButton::MultiButton(byte pin, bool pullup, unsigned long hold_duration, Callback press_callback = NULL,
    Callback hold_callback = NULL, Callback release_callback = NULL, int debounce_delay = 50) {
    pinMode(pin, (pullup ? INPUT_PULLUP : INPUT));
    this->pin = pin;
    this->pressed_mode = pullup;
    this->hold_duration = hold_duration;
    this->debounce_delay = debounce_delay;
    this->press_callback = press_callback;
    this->hold_callback = hold_callback;
    this->release_callback = release_callback;
}

void MultiButton::update() {
    bool state = is_pressed();
    unsigned long t = millis();
    if (last_state != state) {
        last_debounce = t;
    }

    unsigned long delta = t - last_debounce;
    if (delta >= debounce_delay) {
        // if changed
        if (state != debounced_state) {
            debounced_state = state;
            if (!state && long_press) {
                long_press = false;
                release_callback();
            }
            else if(!state) {
                press_callback();
            }
        }
        else if (state && !long_press && (delta >= hold_duration)) {
            long_press = true;
            hold_callback();
        }
    }

    last_state = state;
}

bool MultiButton::is_pressed() {
    return digitalRead(pin) ^ pressed_mode;
}

void MultiButton::set_press_callback(Callback callback) {
    this->press_callback = callback;
}

void MultiButton::set_hold_callback(Callback callback) {
    this->hold_callback = callback;
}

void MultiButton::set_release_callback(Callback callback) {
    this->release_callback = callback;
}