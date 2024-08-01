#include <Arduino.h>
#include <Keypad.h>
#include <ESP32Servo.h>

// Keypad configuration
const byte ROWS = 4;
const byte COLS = 4;
char hexaKeys[ROWS][COLS] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};
byte rowPins[ROWS] = {13, 12, 14, 27};
byte colPins[COLS] = {26, 25, 33, 32};
Keypad customKeypad = Keypad(makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS);

// Servo configuration
Servo myservo;
const int servoPin = 15;

int angles[] = {45, 90, 60, 30, 120, 180};

// Function to map key to angle
int getAngle(char key) {
  switch (key) {
    case '1': return angles[0];
    case '2': return angles[1];
    case '3': return angles[2];
    case '4': return angles[3];
    case '5': return angles[4];
    case '6': return angles[5];
    default: return -1; 
  }
}

void setup() {
  Serial.begin(115200);
  myservo.attach(servoPin);
}

void loop() {
  char customKey = customKeypad.getKey();

  if (customKey) {
    Serial.println(customKey);
    int angle = getAngle(customKey);
    if (angle != -1) {
      myservo.write(angle);
      Serial.print("Servo angle set to: ");
      Serial.println(angle);
      
    }
  else if (customKey == 'A') {
      // Custom Angle Button
      Serial.println("Enter custom angle (0-180) in Serial Monitor:");
      while (Serial.available() == 0) {}
      int customAngle = Serial.parseInt();
      if (customAngle >= 0 && customAngle <= 180) {
        myservo.write(customAngle);
        Serial.print("Custom servo angle set to: ");
        Serial.println(customAngle);
      } else {
        Serial.println("Invalid angle. Please enter a value between 0 and 180.");
      }
    }
  }
}