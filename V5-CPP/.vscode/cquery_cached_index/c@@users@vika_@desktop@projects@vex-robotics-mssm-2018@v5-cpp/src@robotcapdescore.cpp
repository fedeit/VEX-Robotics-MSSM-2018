#include "robotCapDescore.h"
#include "robotMotorDeclarations.h"


void RobotCapDescore::extend() {
  capDescore.move_absolute(-200, 70);
  currentPosition = extended;
}

void RobotCapDescore::retract() {
  capDescore.move_absolute(0, 100);
  currentPosition = retracted;
}

void RobotCapDescore::toggle() {
  capDescore.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
  if (currentPosition == retracted) {
    extend();
  } else if (currentPosition == extended) {
    retract();
  }
}
