#include "Servo.h"
#define SERVOMOTOR_PIN 11
#define SERIAL_BPS 9600 // bits per second.
#define OPEN_POSITION 60 // degrees.
#define CLOSE_POSITION 150 // degrees.
#define WAIT_LONG 7000
#define WAIT_SHORT 200
#define CLOSE_DELAY 750
#define PUSH_BUTTON 2

Servo myservo;
String command = ""; // available commands: "open"
bool buttonState; // false = closed; true = open
bool previousButtonState;
bool openState = false;

void setup() {
  Serial.begin(SERIAL_BPS);
  myservo.attach(SERVOMOTOR_PIN);
  myservo.write(OPEN_POSITION);
  buttonState = true;
  delay(WAIT_LONG);
  myservo.write(CLOSE_POSITION);
  buttonState = false;
  delay(WAIT_SHORT);
  
  pinMode(PUSH_BUTTON, INPUT_PULLUP);
}

void loop() {
  char letter;
  previousButtonState = buttonState;

  // when door gets unlocked (was closed) keep door unlocked until it is opened
  buttonState = digitalRead(PUSH_BUTTON);
  while(buttonState == false && openState == true) {
    delay(WAIT_SHORT);
    buttonState = digitalRead(PUSH_BUTTON);
    delay(CLOSE_DELAY);
  }

  // add delay 
  if(previousButtonState == true && buttonState == false) {
    delay(CLOSE_DELAY);
  }

  openState = false;
  
  if(buttonState == false) {
    delay(WAIT_SHORT);
    myservo.write(CLOSE_POSITION);
    
    if(Serial.available() > 0) {
      letter = Serial.read(); // 1 Byte = 1 char = 1 letter.
      command.concat(letter);
  
      if(command.length() > 4) {
        command = command.substring(1);
      }
  
      if(command == "open") {
        myservo.write(OPEN_POSITION);
        openState = true;
      }
    }
  } else {
    delay(WAIT_SHORT);
    myservo.write(OPEN_POSITION);
  }

  delay(WAIT_SHORT);
}
