#include <CarBase.h>

CarBase bot(
  5, 4, 2, 3,     // Motor direction pins
  11, 10,         // Motor PWM pins
  7, 8,           // Ultrasonic (not used here)
  6,              // Servo pin
  A0, A1          // IR (not used here)
);

void setup() {
  Serial.begin(9600);
  Serial.println("Servo Scanner Test Started");
}

void loop() {
  // Sweep left to right
  for (int angle = 0; angle <= 180; angle += 15) {
    bot.setScannerAngle(angle);
    Serial.print("Servo Angle: ");
    Serial.println(angle);
    delay(300);
  }

  // Sweep right to left
  for (int angle = 180; angle >= 0; angle -= 15) {
    bot.setScannerAngle(angle);
    Serial.print("Servo Angle: ");
    Serial.println(angle);
    delay(300);
  }

  Serial.println("---- Sweep Complete ----");
  delay(2000);
}
