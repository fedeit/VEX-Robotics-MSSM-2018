#include "robotBallShooter.h"
#include "robotMotorDeclarations.h"

void RobotBallShooter::load() {

}

void RobotBallShooter::shoot() {

}

void RobotBallShooter::loadAndShoot() {

}

void RobotBallShooter::spin() {
  ballShooter.move_voltage(12000);
  if (ballShooter.get_position() > 4400) {
    ballShooter.move(0);
  }
}

void RobotBallShooter::stop() {
  ballShooter.move(0);
  ballShooter.tare_position();
}
