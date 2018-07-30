#ifndef callback_h
#define callback_h

// Base callback: takes no arguments and returns nothing
typedef void (*Callback) ();

typedef void (*DeltaCallback) (unsigned long);

#endif