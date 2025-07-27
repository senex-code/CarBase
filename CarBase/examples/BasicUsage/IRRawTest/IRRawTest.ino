#include <CarBase.h>

CarBase bot(
  5, 4, 2, 3,     // Motor direction pins
  11, 10,         // Motor PWM pins
  7, 8,           // Ultrasonic (not used here)
  6,              // Servo (not used here)
  A0, A1          // IR analog pins: Left, Right
);

void setup() {
  Serial.begin(9600);
  Serial.println("IR Raw Sensor Test Started");
}

void loop() {
  int leftRaw = bot.readLeftIRRaw();
  int rightRaw = bot.readRightIRRaw();

  Serial.print("Left IR Raw: ");
  Serial.print(leftRaw);
  Serial.print(" | Right IR Raw: ");
  Serial.println(rightRaw);

  delay(300);
}
