#include "Interval.h"

Interval::Interval() {}

Interval::Interval(unsigned long interval, Callback callback) {
    this->interval = interval;
    this->callback = callback;
}

void Interval::update(unsigned long delta) {
    if (running) {
        t += delta;
        if (t >= interval) {
            t = 0;
            callback();
        }
    }
}

void Interval::start() {
    running = true;
}

void Interval::stop() {
    t = 0;
    running = false;
}

bool Interval::is_running() {
    return running;
}

unsigned long Interval::get_elapsed_time() {
    return t;
}

unsigned long Interval::get_interval() {
    return interval;
}

unsigned long Interval::get_remaining_time() {
    return interval - t;
}

void Interval::set_interval(unsigned long interval) {
    this->interval = interval;
}

void Interval::set_callback(Callback callback) {
    this->callback = callback;
}