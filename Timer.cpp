#include "Timer.h"

Timer::Timer() {}

Timer::Timer(unsigned long interval, Callback callback) {
    this->interval = interval;
    this->callback = callback;
}

void Timer::update(unsigned long delta) {
    if (running) {
        t += delta;
        if (t >= interval) {
            t = 0;
            callback();
        }
    }
}

void Timer::start() {
    running = true;
}

void Timer::stop() {
    t = 0;
    running = false;
}

bool Timer::is_running() {
    return running;
}

unsigned long Timer::get_elapsed_time() {
    return t;
}

unsigned long Timer::get_interval() {
    return interval;
}

unsigned long Timer::get_remaining_time() {
    return interval - t;
}

void Timer::set_interval(unsigned long interval) {
    this->interval = interval;
}

void Timer::set_callback(Callback callback) {
    this->callback = callback;
}