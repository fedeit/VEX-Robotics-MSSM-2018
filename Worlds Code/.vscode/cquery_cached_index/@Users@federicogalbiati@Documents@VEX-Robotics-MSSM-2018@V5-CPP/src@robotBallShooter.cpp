#include "robotBallShooter.h"
#include "robotMotorDeclarations.h"

void RobotBallShooter::spin() {
  motorBallShooter.move_voltage(12000);
  if (motorBallShooter.get_position() > 4400) {
    motorBallShooter.move(0);
  }
}

void RobotBallShooter::stop() {
  motorBallShooter.move(0);
  motorBallShooter.tare_position();
}
