#include <LiquidCrystal_I2C.h>
#include <Arduino.h>
#include <Wire.h>
const int IR_SENSOR_PIN = 13;  // Analog pin for IR sensor

LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  Serial.begin(115200);
  Wire.begin();
  lcd.init();
  lcd.backlight();
  pinMode(IR_SENSOR_PIN, INPUT);
  lcd.print("IRSensor Reading");
  lcd.setCursor(0, 0);  // Set cursor to column 0, row 0
}


void loop() {
  int sensorValue = analogRead(IR_SENSOR_PIN);

  int distance = map(sensorValue, 0, 4095, 0, 12);
  distance = distance * 10;
  lcd.setCursor(0, 1);
  lcd.print("Distance: ");
  lcd.print(distance);
  lcd.print("mm");

  Serial.print("Sensor Value: ");
  Serial.print(sensorValue);
  Serial.print(" | Distance: ");
  Serial.print(distance);
  Serial.println("mm");

  delay(500);
}
