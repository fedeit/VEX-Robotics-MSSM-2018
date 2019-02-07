#include "robotCapDescore.h"
#include "robotMotorDeclarations.h"


void RobotCapDescore::extend() {
  if (capDescore.get_position() > 400) {
     capDescore.move_voltage(0);
  } else {
    capDescore.move_voltage(12000);
  }
}

void RobotCapDescore::retract() {
  capDescore.move_absolute(0, 100);
}

void RobotCapDescore::toggle() {
  capDescore.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
  if (currentPosition == retracted) {
    extend();
  } else if (currentPosition == extended) {
    retract();
  }
}
