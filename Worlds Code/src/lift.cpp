#include "lift.hpp"
#include "robot.hpp"
#include "stdio.h"
#include <cmath>

Lift::Lift() {

}
// Manual control
void Lift::stop() {
  liftLeft.set_brake_mode(MOTOR_BRAKE_HOLD);
  liftRight.set_brake_mode(MOTOR_BRAKE_HOLD);
  liftLeft.move_velocity(0);
  liftRight.move_velocity(0);
}

void Lift::manualUp() {
  targetPosition = 9000;
  liftLeft.move_velocity(200);
  liftRight.move_velocity(200);
}

void Lift::manualDown() {
  targetPosition = 9000;
  liftLeft.move_velocity(-200);
  liftRight.move_velocity(-200);
}

// Presets
// Goto function should only be called on new press, check controller press
void Lift::goToPreset(LiftLevel preset) {
  switch (preset) {
     case LiftLevel::zero:
     targetPosition = GROUND_PRESET;
     break;
     case LiftLevel::low:
     targetPosition = LOW_LEVEL_PRESET;
     break;
     case LiftLevel::high:
     targetPosition = HIGH_LEVEL_PRESET;
     break;
  }
}

void Lift::newPTask(void* self_p) {
  Lift* self = (Lift*)self_p;
  while (true) {
    std::cout << "target: " << self->targetPosition << std::endl;
    if (self->targetPosition == 9000)
      continue;

    int error = self->targetPosition - self->liftPotentiometer.get_value();
    // int speed = error < 0 ? std::min(int(-90), std::max(int(-200), int(error * 0.09)))
    //                             : std::max(int(90), std::min(int(200), int(error * 0.09)));

    int speed = error * 0.09;
    // if (abs(speed) < 110) {
    //   if (speed < 0)
    //     speed = -200;
    //   else
    //     speed = 200;
    // } else if (abs(speed) > 200){
    //   if (speed < 0)
    //     speed = -200;
    //   else
    //   speed = 200;
    // }
    if (error < 0) {
      speed = -200;
    } else {
      speed = 200;
    }
    std::cout << "error: " << speed << std::endl;
    std::cout << "speed: " << error << std::endl;
    if (abs(error) < 60) {
      self->liftLeft.move_velocity(0);
      self->liftRight.move_velocity(0);
      self->targetPosition = 9000;
      continue;
    }

    self->liftLeft.move_velocity(speed);
    self->liftRight.move_velocity(speed);

    pros::Task::delay(5);
  }
}

// Claw functions
void Lift::flipClawBack() {
  this->clawMotor.set_brake_mode(MOTOR_BRAKE_HOLD);
  this->clawMotor.move_absolute(0, 200);
  this->clawState = ClawState::initial;
}

void Lift::flipClawForward() {
  this->clawMotor.set_brake_mode(MOTOR_BRAKE_HOLD);
  this->clawMotor.move_absolute(180, 200);
  this->clawState = ClawState::flipped;
}

void Lift::flipClaw() {
  switch (this->clawState) {
    case ClawState::flipped:
      flipClawBack();
      break;
    case ClawState::initial:
      flipClawForward();
      break;
  }
}

void Lift::tiltClaw() {
  if (!isClawTilted) {
    this->clawMotor.set_brake_mode(MOTOR_BRAKE_HOLD);
    this->clawMotor.move_absolute(30, 200);
    this->clawState = ClawState::flipped;
  } else {
    flipClawForward();
  }
}
