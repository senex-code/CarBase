#include <CarBase.h>

#define SPEED 180
#define THRESHOLD 500  // adjust this based on your IR sensor's behavior

// Create the robot object:
// L_FWD, L_BWD, R_FWD, R_BWD, L_EN, R_EN, TRIG, ECHO, SERVO, IR_L, IR_R
CarBase bot(
  5, 4, 2, 3,     // Motor direction pins
  11, 10,         // Motor PWM pins
  7, 8,           // Ultrasonic (optional)
  6,              // Servo (optional)
  A0, A1          // IR analog pins: Left and Right
);

void setup() {
  Serial.begin(9600);
  Serial.println("Starting raw IR-based line following...");
}

void loop() {
  int leftRaw = bot.readLeftIRRaw();
  int rightRaw = bot.readRightIRRaw();

  // Debug print
  Serial.print("Left: "); Serial.print(leftRaw);
  Serial.print(" | Right: "); Serial.println(rightRaw);

  // Basic raw-value line following logic
  bool leftOnLine  = (leftRaw  < THRESHOLD);
  bool rightOnLine = (rightRaw < THRESHOLD);

  if (leftOnLine && rightOnLine) {
    bot.moveForward(SPEED);
  }
  else if (!leftOnLine && rightOnLine) {
    bot.pivotRight(SPEED);
  }
  else if (leftOnLine && !rightOnLine) {
    bot.pivotLeft(SPEED);
  }
  else {
    bot.stop();  // Both off line (maybe white surface)
  }

  delay(50);
}
