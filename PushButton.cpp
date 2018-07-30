#include "PushButton.h"

PushButton::PushButton(byte pin, bool pullup, Callback press_callback = NULL,  int debounce_delay = 50) {
    pinMode(pin, (pullup ? INPUT_PULLUP : INPUT));
    this->pin = pin;
    this->pressed_mode = pullup;
    this->debounce_delay = debounce_delay;
    this->press_callback = press_callback;
}

void PushButton::update() {
    bool state = is_pressed();
    unsigned long t = millis();
    if (last_state != state) {
        last_debounce = t;
        last_state = state;
    }

    if ((t - last_debounce) >= debounce_delay) {
        /// button state has actually changed
        if (state != debounced_state) {
            debounced_state = state;
            if (state) {
                press_callback();
            }
        }

    }
}

bool PushButton::is_pressed() {
    return digitalRead(pin) && pressed_mode;
}

void PushButton::set_press_callback(Callback callback) {
    this->press_callback = callback;
}