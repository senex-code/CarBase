#include <CarBase.h>

#define SPEED 180
#define THRESHOLD 500

CarBase bot(
  5, 4, 2, 3,     // Motor direction pins
  11, 10,         // Motor PWM pins
  7, 8,           // Ultrasonic TRIG, ECHO
  6,              // Servo pin
  A0, A1          // IR analog pins: Left, Right
);

void setup() {
  Serial.begin(9600);
  Serial.println("All Systems Test Started");
  delay(2000);
}

void loop() {
  // --- Motors ---
  Serial.println("Moving Forward");
  bot.moveForward(SPEED);
  delay(1000);

  Serial.println("Moving Backward");
  bot.moveBackward(SPEED);
  delay(1000);

  Serial.println("Pivoting Left");
  bot.pivotLeft(SPEED);
  delay(1000);

  Serial.println("Pivoting Right");
  bot.pivotRight(SPEED);
  delay(1000);

  bot.stop();
  delay(500);

  // --- Ultrasonic ---
  long front = bot.measureDistance();
  long left  = bot.measureDistanceAt(180);
  long right = bot.measureDistanceAt(0);

  Serial.print("Ultrasonic - Front: ");
  Serial.print(front);
  Serial.print(" cm | Left: ");
  Serial.print(left);
  Serial.print(" cm | Right: ");
  Serial.print(right);
  Serial.println(" cm");

  delay(1000);

  // --- Servo sweep ---
  Serial.println("Sweeping servo...");
  for (int i = 0; i <= 180; i += 60) {
    bot.setScannerAngle(i);
    Serial.print("Angle: ");
    Serial.println(i);
    delay(300);
  }

  // --- IR Digital ---
  Serial.print("IR Digital - Left: ");
  Serial.print(bot.readLeftIR() ? "WHITE" : "BLACK");
  Serial.print(" | Right: ");
  Serial.println(bot.readRightIR() ? "WHITE" : "BLACK");

  // --- IR Raw ---
  Serial.print("IR Raw - Left: ");
  Serial.print(bot.readLeftIRRaw());
  Serial.print(" | Right: ");
  Serial.println(bot.readRightIRRaw());

  Serial.println("-----");
  delay(3000);  // Repeat full test every 3 sec
}
