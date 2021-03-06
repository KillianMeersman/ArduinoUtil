#ifndef Interval_h
#define Interval_h

#include "callback.h"
/*
    Basic interval timer that will execute a callback function every n milliseconds (interval)
    Written by Killian Meersman <killian.meersman@gmail.com> 2018
*/
class Interval {
public:
    Interval();
    Interval(unsigned long interval, Callback callback);
    void update(unsigned long delta);
    void start();
    void stop();
    bool is_running();
    unsigned long get_elapsed_time();
    unsigned long get_remaining_time();
    unsigned long get_interval();
    void set_interval(unsigned long interval);
    void set_callback(Callback callback);

private:
    bool running = false;
    unsigned long interval, t;
    Callback callback;
};


#endif