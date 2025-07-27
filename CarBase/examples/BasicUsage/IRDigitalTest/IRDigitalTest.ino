#include <CarBase.h>

#define BLACK LOW
#define WHITE HIGH

CarBase bot(
  5, 4, 2, 3,     // Motor pins
  11, 10,         // PWM pins
  7, 8,           // Ultrasonic (not used here)
  6,              // Servo (not used here)
  12, 13          // IR digital pins
);

void setup() {
  Serial.begin(9600);
  Serial.println("IR Digital Sensor Test Started");
}

void loop() {
  bool left = bot.readLeftIR();
  bool right = bot.readRightIR();

  Serial.print("Left IR: ");
  Serial.print(left == BLACK ? "BLACK" : "WHITE");
  Serial.print(" | Right IR: ");
  Serial.println(right == BLACK ? "BLACK" : "WHITE");

  delay(500);
}
