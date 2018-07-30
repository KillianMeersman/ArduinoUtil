#include "Led.h"

Led::Led(byte pin) {
    this->pin = pin;
    pinMode(pin, OUTPUT);
}

void Led::set(bool on) {
    state = on;
    digitalWrite(pin, on);
}

void Led::toggle() {
    state = !state;
    digitalWrite(pin, state);
}

bool Led::is_on() {
    return state;
}