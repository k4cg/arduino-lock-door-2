// Door lock control
// By sergiolindo.empresa@gmail.com
//
// It controls a servomotor attached to a lock.
// It listens at serial port for commands "open" and "close".

#include <Servo.h>
// The open and close position are the maximum and the minimum angular position for the servo.
// They depend on the servo. Interval for my servo [25,160].
#define OPEN_POSITION 160 // degrees.
#define CLOSE_POSITION 25 // degrees.

void setup() {}

void loop() {}
