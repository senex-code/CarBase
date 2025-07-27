#include <CarBase.h>

CarBase bot(
  5, 4, 2, 3,    // Motor direction pins
  11, 10,        // Motor PWM pins
  7, 8,          // TRIG, ECHO
  6,             // SERVO pin
  A0, A1         // IR (not used here)
);

void setup() {
  Serial.begin(9600);
  Serial.println("Ultrasonic Sensor Test Started");
}

void loop() {
  // Direct forward measurement (no servo move)
  long dist = bot.measureDistance();
  Serial.print("Forward Distance: ");
  Serial.print(dist);
  Serial.println(" cm");

  // Scan left-right using servo
  int angles[] = {0, 90, 180};
  for (int i = 0; i < 3; i++) {
    long scanned = bot.measureDistanceAt(angles[i]);
    Serial.print("Distance at ");
    Serial.print(angles[i]);
    Serial.print("°: ");
    Serial.print(scanned);
    Serial.println(" cm");
    delay(500);
  }

  Serial.println("----");
  delay(2000); // Repeat every 2 seconds
}
