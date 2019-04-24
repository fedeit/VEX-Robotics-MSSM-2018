#include "lift.hpp"
#include "robot.hpp"
#include "stdio.h"

int Lift::getLiftVoltage() {
  if (abs(this->prevLiftPotValue - this->currLiftPotValue) < 10 && this->liftStatus != Status::rest) {
    return 0;
  }
  else {
    int error = this->currLiftPotValue - this->liftTargetPos;
    return error < 0 ? std::max(int(-127), int(error / PCONST)) : std::min(int(127), int(error / PCONST));
  }
}

void Lift::update() {
  this->prevLiftPotValue = this->currLiftPotValue;
  this->currLiftPotValue = this->liftPotentiometer.get_value();

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

void Lift::extend(uint speed) {
  this->liftMotorLeft.move(speed);
  this->liftMotorRight.move(speed);
  this->liftMode = LiftMode::manual;
}

void Lift::retract(uint speed) {
  this->liftMotorLeft.move(-speed);
  this->liftMotorRight.move(-speed);
  this->liftMode = LiftMode::manual;
}

void Lift::stop() {
  this->liftMotorLeft.move(0);
  this->liftMotorRight.move(0);
}

void Lift::flipClaw() {
  if (clawState == ClawState::initial){
    clawMotor.move_absolute(180, 200);
    clawState = ClawState::flipped;
  }
  else {
    clawMotor.move_absolute(0, 200);
    clawState = ClawState::initial;
  }
}
