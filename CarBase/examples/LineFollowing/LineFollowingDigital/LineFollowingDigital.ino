#include <CarBase.h>

#define SPEED 180
#define WHITE  HIGH
#define BLACK  LOW

// Create the robot object:
// L_FWD, L_BWD, R_FWD, R_BWD, L_EN, R_EN, TRIG, ECHO, SERVO, IR_L, IR_R
CarBase bot(
  5, 4, 2, 3,     // Motor control
  11, 10,         // Motor speed
  7, 8,           // Ultrasonic (not used here)
  6,              // Servo (not used here)
  12, 13          // IR sensors: Left and Right
);

void setup() {
  Serial.begin(9600);
}

void loop() {
  bool leftIR = bot.readLeftIR();
  bool rightIR = bot.readRightIR();

  // Both sensors on black line
  if (leftIR == BLACK && rightIR == BLACK) {
    bot.moveForward(SPEED);
  }
  // Left sensor sees white (veered left)
  else if (leftIR == WHITE && rightIR == BLACK) {
    bot.pivotRight(SPEED);
  }
  // Right sensor sees white (veered right)
  else if (leftIR == BLACK && rightIR == WHITE) {
    bot.pivotLeft(SPEED);
  }
  // Both on white – lost the line
  else {
    bot.stop();
  }

  delay(50);
}
