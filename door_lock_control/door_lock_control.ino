// Door lock control
// By sergiolindo.empresa@gmail.com
//
// It controls a servomotor attached to a lock.
// It listens at serial port for commands "open" and "close".

#include <Servo.h>
#define SERVOMOTOR_PIN 9
#define SERIAL_BPS 9600 // bits per second.
// The open and close position are the maximum and the minimum angular positions for the servo.
// They depend on the servo. Interval for my servo [25,160].
#define OPEN_POSITION 160 // degrees.
#define CLOSE_POSITION 25 // degrees.

Servo myservo;

void setup() {
  Serial.begin(SERIAL_BPS);
  Serial.println("setup begins");
  Serial.print("  Serial communication port opened at ");
  Serial.println(SERIAL_BPS);

  myservo.attach(SERVOMOTOR_PIN);
  Serial.print("  Servo attached to pin ");
  Serial.println(SERVOMOTOR_PIN);
  Serial.println();

  Serial.println("  Secure in case of emergency");
  Serial.print("  Set servo to ");
  Serial.print(OPEN_POSITION);
  Serial.println(" (open)");
  myservo.write(OPEN_POSITION); // Unlock the door ...
  Serial.println("  Waiting 5 seconds");
  delay(5000); // ... for 5 seconds ...
  Serial.print("  Set servo to ");
  Serial.print(CLOSE_POSITION);
  Serial.println(" (close)");
  myservo.write(CLOSE_POSITION); // ... and lock the door.
  delay(500);

  Serial.println("setup ends");
}

void loop() {}
