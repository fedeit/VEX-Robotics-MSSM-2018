#include "lift.hpp"
#include "robot.hpp"
#include "stdio.h"

void Lift::holdToPosition(int position) {
  while (this->liftPotentiometer.get_value_calibrated() - position > 5) {
    this->extend();
    pros::delay(2);
  }

  while (this->liftPotentiometer.get_value_calibrated() - position < -5) {
    this->retract();
    pros::delay(2);
  }

  this->stop();
}

void Lift::lowPolePreset() {
  while (this->liftPotentiometer.get_value_calibrated() > ABOVE_LOW_LEVEL_POT_PRESET){
    this->extend();
    pros::delay(2);
  }

  this->stop();
  this->level = low;

  this->holdToPosition(ABOVE_LOW_LEVEL_POT_PRESET);
}

void Lift::highPolePreset() {
  while (this->liftPotentiometer.get_value_calibrated() > ABOVE_HIGH_LEVEL_POT_PRESET){
    this->extend();
    pros::delay(2);
  }

  this->stop();
  this->level = high;

  this->holdToPosition(ABOVE_HIGH_LEVEL_POT_PRESET);
}

void Lift::retractCompletely() {
  this->liftMotorLeft.move_absolute(0, 100);
  this->liftMotorRight.move_absolute(0, 100);
  this->level = zero;
}

void Lift::extend() {
  this->liftMotorLeft.move(127);
  this->liftMotorRight.move(127);
}

void Lift::retract() {
  this->liftMotorLeft.move(-127);
  this->liftMotorRight.move(-127);
}

void Lift::stop() {
  this->liftMotorLeft.move(0);
  this->liftMotorRight.move(0);
}

void Lift::holdToClosest() {
  switch(this->level) {
    case zero:
      this->holdToPosition(300);
      break;
    case low:
      this->holdToPosition(LOW_LEVEL_POT_PRESET);
      break;
    case high:
      this->holdToPosition(HIGH_LEVEL_POT_PRESET);
  }
}

void Lift::toggleUp() {
  switch (this->level) {
    case zero:
      lowPolePreset();
      break;
    case low:
      highPolePreset();
      break;
    case high:
      break;
  }
}

void Lift::toggleDown() {
  switch (this->level) {
    case zero:
      break;
    case low:
      retractCompletely();
      break;
    case high:
      lowPolePreset();
      break;
  }
}

// Claw functions
void Lift::flipClawBack() {
  this->clawMotor.move_absolute(0, 200);
  this->clawState = initial;
}

void Lift::flipClawForward() {
  this->clawMotor.move_absolute(180, 200);
  this->clawState = flipped;
}

void Lift::flipClaw() {
  switch (this->clawState) {
    case flipped:
      flipClawBack();
      break;
    case initial:
      flipClawForward();
      break;
  }
}

// Misc
void Lift::calibrate() {
  this->liftPotentiometer.calibrate();
}

int Lift::getLiftPotentiometerValue() {
  return this->liftPotentiometer.get_value();
}
