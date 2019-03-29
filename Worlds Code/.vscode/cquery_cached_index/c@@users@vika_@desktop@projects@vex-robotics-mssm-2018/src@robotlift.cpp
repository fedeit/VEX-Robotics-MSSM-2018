#include "robotLift.hpp"
#include "robot.hpp"


void RobotLift::lowPolePreset() {
  liftMotor.move_absolute(0.25, 100);
  // Have to test number of rotations to go to preset
}

void RobotLift::highPolePreset() {
  liftMotor.move_absolute(0.5, 100);
  // Have to test number of rotations to go to preset
}

void RobotLift::retractCompletely() {
  liftMotor.move_absolute(0, 100);
}

void RobotLift::extend() {
  liftMotor.move(100);
}

void RobotLift::retract() {
  liftMotor.move(-100);
}

void RobotLift::stop() {
  liftMotor.move_voltage(0);
}

void RobotLift::toggleUp() {
  switch (level) {
    case retracted: lowPolePreset();
    case low: highPolePreset();
    case high: break;
  }
}

void RobotLift::toggleDown() {
  switch (level) {
    case retracted: break;
    case low: retractCompletely();
    case high: lowPolePreset();
  }
}
