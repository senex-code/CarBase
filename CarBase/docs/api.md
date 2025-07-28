
---

## ✅ `API.md`
```markdown
# CarBase Library — API Documentation

## 🛞 Motion Control

| Method                    | Description                                |
|---------------------------|--------------------------------------------|
| `moveForward(speed)`      | Drive both motors forward at `speed`       |
| `moveBackward(speed)`     | Drive both motors backward at `speed`      |
| `pivotLeft(speed)`        | Turn in place to the left                  |
| `pivotRight(speed)`       | Turn in place to the right                 |
| `turnLeft(angle, speed)`  | Turn left by degrees                       |
| `turnRight(angle, speed)` | Turn right by degrees                      |
| `stop()`                  | Stop all motors                            |

## 📡 Ultrasonic

| Method                        | Description                                     |
|-------------------------------|-------------------------------------------------|
| `measureDistance()`           | Get distance ahead (no servo movement)         |
| `measureDistanceAt(angle)`    | Rotate scanner to angle and get distance       |
| `setScannerAngle(angle)`      | Manually set servo angle                       |

## 🔦 IR Sensor — Digital

| Method           | Description                          |
|------------------|--------------------------------------|
| `readLeftIR()`   | Return `HIGH` or `LOW` from left IR  |
| `readRightIR()`  | Return `HIGH` or `LOW` from right IR |

## 🎚 IR Sensor — Raw (Analog)

| Method              | Description                          |
|---------------------|--------------------------------------|
| `readLeftIRRaw()`   | Return raw analog value (0–1023)     |
| `readRightIRRaw()`  | Return raw analog value (0–1023)     |

## 🛠 Constants

- `DEFAULT_TURN_TIME_90`: Used to calibrate turn timing
- `DEFAULT_PWM_SPEED`: Reference speed for time calculations

---

For usage, see `/examples/BasicUsage/`
