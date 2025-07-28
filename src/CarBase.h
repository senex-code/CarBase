#ifndef CarBase_H
#define CarBase_H

#include <Arduino.h>
#if defined(ESP32)
  #include <ESP32Servo.h>
#else
  #include <Servo.h>
#endif


/**
 * @brief Controls a differential-drive robot base with an ultrasonic scanner and IR sensors.
 */
class CarBase {
public:
  /**
   * @brief Construct a new CarBase object.
   * @param leftForwardPin   Pin for left motor forward control.
   * @param leftBackwardPin  Pin for left motor backward control.
   * @param rightForwardPin  Pin for right motor forward control.
   * @param rightBackwardPin Pin for right motor backward control.
   * @param leftEnablePin    PWM pin for left motor speed.
   * @param rightEnablePin   PWM pin for right motor speed.
   * @param trigPin          Ultrasonic sensor trigger pin.
   * @param echoPin          Ultrasonic sensor echo pin.
   * @param servoPin         Servo pin for scanner arm.
   * @param leftIRPin        Digital or analog input pin for left IR sensor.
   * @param rightIRPin       Digital or analog input pin for right IR sensor.
   */
  CarBase(uint8_t leftForwardPin,
        uint8_t leftBackwardPin,
        uint8_t rightForwardPin,
        uint8_t rightBackwardPin,
        uint8_t leftEnablePin,
        uint8_t rightEnablePin,
        uint8_t trigPin = 255,
        uint8_t echoPin = 255,
        uint8_t servoPin = 255,
        uint8_t leftIRPin = 255,
        uint8_t rightIRPin = 255);

  void moveForward(uint8_t speed);
  void moveBackward(uint8_t speed);
  void stop();
  void pivotLeft(uint8_t speed);
  void pivotRight(uint8_t speed);
  void turnLeft(uint16_t angle, uint8_t speed);
  void turnRight(uint16_t angle, uint8_t speed);

  long measureDistanceAt(uint8_t scanAngle);
  long measureDistance();
  void setScannerAngle(uint8_t scanAngle);

  /**
   * @brief Reads the left IR sensor.
   * @return true if sensor is HIGH, false if LOW.
   */
  bool readLeftIR();

  /**
   * @brief Reads the right IR sensor.
   * @return true if sensor is HIGH, false if LOW.
   */
  bool readRightIR();

    /**
   * @brief Read raw analog value from the left IR sensor.
   * @return Integer from 0 to 1023.
   */
  int readLeftIRRaw();

  /**
   * @brief Read raw analog value from the right IR sensor.
   * @return Integer from 0 to 1023.
   */
  int readRightIRRaw();


private:
  uint8_t _lfPin, _lbPin, _rfPin, _rbPin;
  uint8_t _lePin, _rePin;
  uint8_t _trigPin, _echoPin;
  uint8_t _servoPin;
  uint8_t _leftIRPin, _rightIRPin;

  static constexpr float DEFAULT_TURN_TIME_90 = 1450.0f / 4.0f;
  static constexpr uint8_t DEFAULT_PWM_SPEED = 255;

  Servo _scanner;

  void setMotorPWM(uint8_t leftSpeed, uint8_t rightSpeed);
  unsigned long computeTurnDuration(uint16_t angle, uint8_t speed);
};

#endif // CarBase_H
