#include <CarBase.h>

#define THRESHOLD 25

// Create the robot object with pin mappings:
// L_FWD, L_BWD, R_FWD, R_BWD, L_EN, R_EN, TRIG, ECHO, SERVO
CarBase bot(
  5, 4, 2, 3,    // Motor direction pins
  11, 10,        // Motor enable (PWM) pins
  1, 2,          // Ultrasonic TRIG and ECHO
  6              // Servo pin
);

// Struct to return multiple distances
struct DistanceScan {
  int right;
  int front;
  int left;
};

DistanceScan scanSurroundings() {
  DistanceScan scan;
  scan.right = bot.measureDistanceAt(0);
  scan.front = bot.measureDistanceAt(90);
  scan.left = bot.measureDistanceAt(180);
  return scan;
}

void setup() {
  Serial.begin(9600);
}

void loop() {
  int frontDistance = bot.measureDistanceAt(90);

  if (frontDistance < THRESHOLD) {
    bot.stop();
    delay(100);

    DistanceScan d = scanSurroundings();

    if (d.right > d.left && d.right > THRESHOLD) {
      bot.turnRight(90, 255);
      delay(100);
    }
    else if (d.left > d.right && d.left > THRESHOLD) {
      bot.turnLeft(90, 255);
      delay(100);
    }
    else {
      bot.turnLeft(180, 255);
    }
  } else {
    bot.moveForward(255);
    delay(100);
  }
}
