#include <CarBase.h>

#define SPEED 200
#define TURN_DELAY 1000

CarBase bot(
  5, 4, 2, 3,    // Motor direction pins: L_FWD, L_BWD, R_FWD, R_BWD
  11, 10,        // Motor PWM pins: L_EN, R_EN
  7, 8,          // Ultrasonic (not used here)
  6,             // Servo (not used here)
  A0, A1         // IR (not used here)
);

void setup() {
  Serial.begin(9600);
  Serial.println("Motor Test Started");
}

void loop() {
  Serial.println("Forward");
  bot.moveForward(SPEED);
  delay(TURN_DELAY);

  Serial.println("Backward");
  bot.moveBackward(SPEED);
  delay(TURN_DELAY);

  Serial.println("Pivot Left");
  bot.pivotLeft(SPEED);
  delay(TURN_DELAY);

  Serial.println("Pivot Right");
  bot.pivotRight(SPEED);
  delay(TURN_DELAY);

  Serial.println("Turn Left 90°");
  bot.turnLeft(90, SPEED);
  delay(TURN_DELAY);

  Serial.println("Turn Right 90°");
  bot.turnRight(90, SPEED);
  delay(TURN_DELAY);

  Serial.println("Stop");
  bot.stop();
  delay(3000);  // Pause before repeating
}
