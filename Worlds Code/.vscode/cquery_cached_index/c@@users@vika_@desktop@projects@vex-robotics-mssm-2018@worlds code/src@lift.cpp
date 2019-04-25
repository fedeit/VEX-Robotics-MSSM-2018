#include "lift.hpp"
#include "robot.hpp"
#include "stdio.h"

int Lift::getLiftVoltage() {
  if (abs(this->prevLiftPotValue - this->currLiftPotValue) < 50 && this->liftStatus != Status::rest) {
    return 0;
  }
  else {
    int error = this->liftTargetPos - this->currLiftPotValue;
    if (abs(error) < 50)
      return 0;
    return error < 0 ? std::min(int(-40), std::max(int(-127), int(error / PCONST))) : std::max(int(40), std::min(int(127), int(error / PCONST)));
  }
}

void Lift::update() {
  this->prevLiftPotValue = this->currLiftPotValue;
  this->currLiftPotValue = this->liftPotentiometer.get_value();

  if (this->liftMode == LiftMode::manual)
    return;

  int liftVoltage = getLiftVoltage();

  if (liftVoltage == 0) {
    this->liftStatus = Status::rest;
    this->liftTargetPos = this->currLiftPotValue;
  }
  else {
    this->liftStatus = Status::moving;
  }

  this->liftMotorRight.move(liftVoltage);
  this->liftMotorLeft.move(liftVoltage);
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

void Lift::extend() {
  this->liftMotorRight.move(127);
  this->liftMotorLeft.move(127);
  this->liftMode = LiftMode::manual;
}

void Lift::retract() {
  this->liftMotorRight.move(-127);
  this->liftMotorLeft.move(-127);
  this->liftMode = LiftMode::manual;
}

void Lift::stop() {
  this->liftMotorLeft.move(0);
  this->liftMotorRight.move(0);
}

void Lift::flipClaw() {
  if (this->clawState == ClawState::initial){
    this->clawMotor.move_absolute(-180, 200);
    this->clawState = ClawState::flipped;
  }
  else {
    this->clawMotor.move_absolute(0, 200);
    this->clawState = ClawState::initial;
  }
}
