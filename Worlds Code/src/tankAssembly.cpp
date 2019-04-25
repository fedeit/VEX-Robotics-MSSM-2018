#include "main.h"
#include "robot.hpp"
#include "tankAssembly.hpp"
#include "tgmath.h"

void TankAssembly::moveBase(std::int8_t velocity) {
  moveLeftSide(velocity);
  moveRightSide(velocity);
}

void TankAssembly::moveLeftSide(std::int8_t velocity) {
  this->motorLeftFront.move(velocity);
  this->motorLeftBack.move(velocity);
}

void TankAssembly::moveRightSide(std::int8_t velocity) {
  this->motorRightBack.move(velocity);
  this->motorRightFront.move(velocity);
}

void TankAssembly::pickupCap() {

}

void TankAssembly::releaseCap() {
  robot.lift.stop();
  // Might need to drive the lift up by a few degrees to release cap
}

void TankAssembly::goToPosition(int targetX, int targetY) {
  float dx = targetX - currentX;
  float dy = targetY - currentY;
  float r = sqrt(dx*dx+dy*dy);
  float targetAngle = atan(dy/dx);
  turnByAngle(targetAngle - currentAngle);
  driveStraightBy(r);
}

void TankAssembly::driveStraightBy(float distance) {
  if (robot.robotSensors.sonarDistance() < 20) {
    // Make speed 70% when less than 20 cm from impact
  }
  if (robot.robotSensors.didReachPole()) {
    this->moveBase(0);
  }
}

void TankAssembly::turnByAngle(float angle) {

}
