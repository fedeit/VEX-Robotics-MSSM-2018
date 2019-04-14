#include "lift.hpp"
#include "robot.hpp"
#include "stdio.h"

int Lift::getLiftVoltage() {
  if (abs(this->prevLiftPotValue - this->currLiftPotValue) < 10 && this->liftStatus != Status::rest) {
    return 0;
  }
  else {
    int error = this->currLiftPotValue - this->liftTargetPos;
    return error > 0 ? max(-127, error / PCONST) : min(127, error / PCONST);
  }
}

int Lift::getClawVoltage() {
  if (abs(this->prevClawPotValue - this->currClawPotValue) < 10 && this->clawStatus != Status::rest) {
    return 0;
  }
  else {
    int error = this->currLiftPotValue - this->liftTargetPos;
    return error > 0 ? max(-127, error / PCONST) : min(127, error / PCONST);
  }
}

void Lift::update() {
  this->prevLiftPotValue = this->currLiftPotValue;
  this->currLiftPotValue = this->liftPotentiometer.get_value();

  this->prevClawPotValue = this->currClawPotValue;
  this->currClawPotValue = this->clawPotentiometer.get_value();

  int liftVoltage = getLiftVoltage();
  int clawVoltage = getClawVoltage();

  if (liftVoltage == 0) {
    this->clawStatus = Status::rest;
    this->liftTargetPos = this->currLiftPotValue;
  }
  else {
    this->liftStatus = Status::moving;
  }

  if (clawVoltage == 0) {
    this->liftStatus = Status::rest;
    this->clawTargetPos = this->currClawPotValue;
  }
  else {
    this->clawStatus = Status::moving;
  }

  this->liftMotorRight.move(liftVoltage);
  this->liftMotorLeft.move(liftVoltage);

  this->clawMotor.move(clawVoltage);
}

void Lift::hold() {
  if (this->liftMode == LiftMode::manual){
    this->liftTargetPos = this->liftPotentiometer.get_value();
    this->liftMode = LiftMode::presets;
  }
}

void Lift::lowPolePreset() {
  this->liftTargetPos = LOW_POLE;
  this->liftMode = LiftMode::presets;
}

void Lift::highPolePreset() {
  this->liftTargetPos = HIGH_POLE;
  this->liftMode = LiftMode::presets;
}

void Lift::retractCompletely() {
  this->liftTargetPos = LIFT_ZERO;
  this->liftMode = LiftMode::presets;
}

void Lift::extend(uint speed = 127) {
  this->liftMotorLeft.move(speed);
  this->liftMotorRight.move(speed);
  this->liftMode = LiftMode::manual;
}

void Lift::retract(uint speed = 127) {
  this->liftMotorLeft.move(-speed);
  this->liftMotorRight.move(-speed);
  this->liftMode = LiftMode::manual;
}

void Lift::stop() {
  this->liftMotorLeft.move(0);
  this->liftMotorRight.move(0);
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

void Lift::flipClaw() {
  if (this->clawTargetPos == CLAW_ZERO) {
    this->clawTargetPos = CLAW_FLIPPED;
  }
  else {
    this->clawTargetPos = CLAW_ZERO;
  }
}

// Misc
void Lift::calibrate() {
}
