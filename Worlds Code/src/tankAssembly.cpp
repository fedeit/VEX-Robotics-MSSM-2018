#include "main.h"
#include "robot.hpp"
#include "tankAssembly.hpp"
#include <cmath>

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

void TankAssembly::driveStraightBy(double distance) {
  this->motorLeftBack.move_relative(distance*IN_R, 200);
  this->motorLeftBack.move_relative(distance*IN_R, 200);
  this->motorLeftBack.move_relative(distance*IN_R, 200);
  this->motorLeftBack.move_relative(distance*IN_R, 200);
}

void TankAssembly::goToPosition(double targetX, double targetY) {
  double dx = targetX - this->currentX;
  double dy = targetY - this->currentY;
  double r = sqrt(dx*dx+dy*dy);
  try { // Will work if not both dy and dx zero
    float dAngle = atan2(dy, dx);
    turnByAngle(dAngle);
    driveStraightBy(r);
    this->currentX = targetX;
    this->currentY = targetY;
  } catch (int e) {};
}

void TankAssembly::turnByAngle(double angle) {
  int rotations = (D_ROBOT*angle/2)/(D_WHEEL*_PI);
  this->motorLeftFront.move_relative(-rotations, 200);
  this->motorLeftBack.move_relative(-rotations, 200);
  this->motorRightFront.move_relative(rotations, 200);
  this->motorRightBack.move_relative(rotations, 200);
}
