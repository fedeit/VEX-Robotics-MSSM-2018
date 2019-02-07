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
  if (ballShooter.get_position() > 1100) {
    ballShooter.move(0);
  }
  std::cout << "Position: " << ballShooter.get_position() << std::endl;
  std::cout << "Torque: " << ballShooter.get_torque() << std::endl;
  std::cout << "Efficiency: " << ballShooter.get_efficiency() << std::endl;
}

void RobotBallShooter::stop() {
  ballShooter.move(0);
  ballShooter.tare_position();
}
