#include "lift.hpp"
#include "robot.hpp"
#include "stdio.h"

void Lift::holdToPosition(long int position) {
  while (abs(this->getLiftPotentiometerValue() - position) > 30) {
    while (this->getLiftPotentiometerValue() < position - 30){
      this->extend(std::min((long int)127, std::max((long int)25, ((long int)position - this->getLiftPotentiometerValue())/3)));
      pros::delay(2);
    }

    while (this->getLiftPotentiometerValue() > position + 30){
      std::cout << this->getLiftPotentiometerValue() << " " << position << "\n";
      this->retract(std::min((long int)127, std::max((long int)25,  (this->getLiftPotentiometerValue() - (long int)position)/3)));
      pros::delay(2);
    }
  }

  this->stop();
}

void Lift::lowPolePreset() {
  while (abs(this->getLiftPotentiometerValue() - ABOVE_LOW_LEVEL_POT_PRESET) > 30) {
    while (this->getLiftPotentiometerValue() < ABOVE_LOW_LEVEL_POT_PRESET - 30){
      std::cout << this->getLiftPotentiometerValue() << " " << ABOVE_LOW_LEVEL_POT_PRESET << "\n";
      this->extend(std::min((long int)127, std::max((long int)25, ((long int)ABOVE_LOW_LEVEL_POT_PRESET - this->getLiftPotentiometerValue())/3)));
      pros::delay(2);
    }

    while (this->getLiftPotentiometerValue() > ABOVE_LOW_LEVEL_POT_PRESET + 30){
      std::cout << this->getLiftPotentiometerValue() << " " << ABOVE_LOW_LEVEL_POT_PRESET << "\n";
      this->retract(std::min((long int)127, std::max((long int)25,  (this->getLiftPotentiometerValue() - (long int)ABOVE_LOW_LEVEL_POT_PRESET)/3)));
      pros::delay(2);
    }
  }

  this->stop();
  this->level = low;
}

void Lift::highPolePreset() {
  while (this->liftPotentiometer.get_value() < ABOVE_HIGH_LEVEL_POT_PRESET - 15){
    this->extend(127);
    pros::delay(2);
  }

  this->stop();
  this->level = high;
}

void Lift::retractCompletely() {
  while (this->liftPotentiometer.get_value() > GROUND_PRESET + 15) {
    this->retract(127);
    pros::delay(2);
  }

  this->stop();
  this->level = zero;
}

void Lift::extend(unsigned int speed) {
  this->liftMotorLeft.move(speed);
  this->liftMotorRight.move(speed);
}

void Lift::retract(unsigned int speed) {
  this->liftMotorLeft.move(-speed);
  this->liftMotorRight.move(-speed);
}

void Lift::stop() {
  this->liftMotorLeft.move(0);
  this->liftMotorRight.move(0);
}

void Lift::holdToClosest() {
  switch(this->level) {
    case zero:
      this->retractCompletely();
      break;
    case low:
      this->holdToPosition(LOW_LEVEL_POT_PRESET);
      break;
    case high:
      this->holdToPosition(HIGH_LEVEL_POT_PRESET);
  }
}

void Lift::hold() {
  if (this->holdMode == latest) {
    this->holdToPosition(this->getLiftPotentiometerValue());
  }
  else {
    this->holdToClosest();
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
}

int Lift::getLiftPotentiometerValue() {
  return this->liftPotentiometer.get_value();
}
