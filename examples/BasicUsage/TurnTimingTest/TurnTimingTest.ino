#include <CarBase.h>

#define SPEED 180
#define WAIT  1500  // Wait between turns

CarBase bot(
  5, 4, 2, 3,    // Motor direction pins
  11, 10,        // PWM pins
  7, 8,          // Ultrasonic (not used)
  6,             // Servo (not used)
  A0, A1         // IR (not used)
);

void setup() {
  Serial.begin(9600);
  Serial.println("Turn Timing Test Started");
  delay(2000);
}

void loop() {
  Serial.println("Turning Left 90°");
  bot.turnLeft(90, SPEED);
  delay(WAIT);

  Serial.println("Turning Right 90°");
  bot.turnRight(90, SPEED);
  delay(WAIT);

  Serial.println("Turning Left 45°");
  bot.turnLeft(45, SPEED);
  delay(WAIT);

  Serial.println("Turning Right 45°");
  bot.turnRight(45, SPEED);
  delay(WAIT);

  Serial.println("Stopping");
  bot.stop();
  delay(5000); // Long pause to observe

  Serial.println("Repeating...");
}
