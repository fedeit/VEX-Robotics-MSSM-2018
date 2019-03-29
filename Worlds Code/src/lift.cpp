#include "lift.hpp"
#include "robot.hpp"
#include "stdio.h"

void Lift::lowPolePreset() {
  this->liftMotorLeft.move_absolute(-360, 200);
  this->liftMotorRight.move_absolute(360, 200);
  // Have to test number of rotations to go to preset
  this->level = low;
}

void Lift::highPolePreset() {
  this->liftMotorLeft.move_absolute(180, 200);
  this->liftMotorRight.move_absolute(180, 200);
  // Have to test number of rotations to go to preset
  this->level = high;
}

void Lift::retractCompletely() {
  this->liftMotorLeft.move_absolute(0, 200);
  this->liftMotorRight.move_absolute(0, 200);
  this->level = retracted;
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

void Lift::toggleUp() {
  switch (this->level) {
    case retracted:
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
    case retracted:
      break;
    case low:
      retractCompletely();
      break;
    case high:
      lowPolePreset();
      break;
  }
}

void Lift::flipClawBack() {
  this->clawMotor.move_absolute(0, 200);
  this->clawState = initial;
}

void Lift::flipClawForward() {
  this->clawMotor.move_absolute(175, 200);
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
