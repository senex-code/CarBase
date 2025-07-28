// File: CarBase.cpp
#include "CarBase.h"

CarBase::CarBase(uint8_t lf, uint8_t lb, uint8_t rf, uint8_t rb,
                 uint8_t le, uint8_t re,
                 uint8_t trig, uint8_t echo,
                 uint8_t servoPin,
                 uint8_t leftIRPin,
                 uint8_t rightIRPin)
  : _lfPin(lf), _lbPin(lb), _rfPin(rf), _rbPin(rb),
    _lePin(le), _rePin(re),
    _trigPin(trig), _echoPin(echo),
    _servoPin(servoPin),
    _leftIRPin(leftIRPin), _rightIRPin(rightIRPin)
{
  pinMode(_lfPin, OUTPUT);
pinMode(_lbPin, OUTPUT);
pinMode(_rfPin, OUTPUT);
pinMode(_rbPin, OUTPUT);
pinMode(_lePin, OUTPUT);
pinMode(_rePin, OUTPUT);

// Optional ultrasonic
if (_trigPin != 255) pinMode(_trigPin, OUTPUT);
if (_echoPin != 255) pinMode(_echoPin, INPUT);

// Optional IRs
if (_leftIRPin != 255) pinMode(_leftIRPin, INPUT);
if (_rightIRPin != 255) pinMode(_rightIRPin, INPUT);

// Optional servo
if (_servoPin != 255) _scanner.attach(_servoPin);
}

void CarBase::moveForward(uint8_t speed) {
  digitalWrite(_lfPin, HIGH);
  digitalWrite(_lbPin, LOW);
  digitalWrite(_rfPin, HIGH);
  digitalWrite(_rbPin, LOW);
  setMotorPWM(speed, speed);
}

void CarBase::moveBackward(uint8_t speed) {
  digitalWrite(_lfPin, LOW);
  digitalWrite(_lbPin, HIGH);
  digitalWrite(_rfPin, LOW);
  digitalWrite(_rbPin, HIGH);
  setMotorPWM(speed, speed);
}

void CarBase::stop() {
  digitalWrite(_lfPin, LOW);
  digitalWrite(_lbPin, LOW);
  digitalWrite(_rfPin, LOW);
  digitalWrite(_rbPin, LOW);
  setMotorPWM(0, 0);
}

void CarBase::pivotLeft(uint8_t speed) {
  stop();
  delay(50);
  digitalWrite(_lfPin, LOW);
  digitalWrite(_lbPin, HIGH);
  digitalWrite(_rfPin, HIGH);
  digitalWrite(_rbPin, LOW);
  setMotorPWM(speed, speed);
}

void CarBase::pivotRight(uint8_t speed) {
  stop();
  delay(50);
  digitalWrite(_lfPin, HIGH);
  digitalWrite(_lbPin, LOW);
  digitalWrite(_rfPin, LOW);
  digitalWrite(_rbPin, HIGH);
  setMotorPWM(speed, speed);
}

void CarBase::turnLeft(uint16_t angle, uint8_t speed) {
  stop();
  delay(50);
  unsigned long t = computeTurnDuration(angle, speed);
  pivotLeft(speed);
  delay(t);
  stop();
}

void CarBase::turnRight(uint16_t angle, uint8_t speed) {
  stop();
  delay(50);
  unsigned long t = computeTurnDuration(angle, speed);
  pivotRight(speed);
  delay(t);
  stop();
}

long CarBase::measureDistanceAt(uint8_t scanAngle) {
  setScannerAngle(scanAngle);
  if (_trigPin == 255 || _echoPin == 255) return -1;
  digitalWrite(_trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(_trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(_trigPin, LOW);
  long duration = pulseIn(_echoPin, HIGH);
  long distance = duration * 0.034 / 2;
  return (distance > 0 ? distance : -1);
}

long CarBase::measureDistance() {
  if (_trigPin == 255 || _echoPin == 255) return -1;
  digitalWrite(_trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(_trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(_trigPin, LOW);
  long duration = pulseIn(_echoPin, HIGH);
  long distance = duration * 0.034 / 2;
  return (distance > 0 ? distance : -1);
}

void CarBase::setScannerAngle(uint8_t scanAngle) {
  if (_servoPin != 255) {
  _scanner.write(constrain(scanAngle, 0, 180));
}
}

void CarBase::setMotorPWM(uint8_t leftSpeed, uint8_t rightSpeed) {
  analogWrite(_lePin, leftSpeed);
  analogWrite(_rePin, rightSpeed);
}

unsigned long CarBase::computeTurnDuration(uint16_t angle, uint8_t speed) {
  if (speed == 0) speed = 1;
  float ratio = float(DEFAULT_PWM_SPEED) / speed;
  float t = (angle / 90.0f) * DEFAULT_TURN_TIME_90 * ratio;
  return static_cast<unsigned long>(t);
}

bool CarBase::readLeftIR() {
  return _leftIRPin != 255 ? digitalRead(_leftIRPin) : false;
}

bool CarBase::readRightIR() {
  return _rightIRPin != 255 ? digitalRead(_rightIRPin) : false;
}

int CarBase::readLeftIRRaw() {
  return _leftIRPin != 255 ? analogRead(_leftIRPin) : 0;
}

int CarBase::readRightIRRaw() {
  return _rightIRPin != 255 ? analogRead(_rightIRPin) : 0;
}