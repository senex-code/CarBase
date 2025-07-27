# CarBase Arduino Library

CarBase is a professional Arduino library for controlling differential drive robots with:

- Motor control (forward, backward, pivot, timed turns)
- Ultrasonic scanning (servo-mounted or fixed)
- IR sensor integration (digital + analog modes)
- Structured modular code with clean API
- Full example suite for testing and teaching

---

## 📦 Features

- Simple object-oriented motor control
- Angle-based turning with time-calculated delay
- Distance scanning at any servo angle
- Support for both digital and analog IR sensors
- Fully documented and ready for classrooms, competitions, or development

---

⚠️ If you're using an ESP32 board, install the ESP32Servo library via Library Manager.

## 🚀 Quick Start

```cpp
#include <CarBase.h>

CarBase bot(5, 4, 2, 3, 11, 10, 7, 8, 6, A0, A1);

void setup() {
  bot.moveForward(200);
}

void loop() {
  if (bot.measureDistance() < 20) {
    bot.stop();
  }
}
