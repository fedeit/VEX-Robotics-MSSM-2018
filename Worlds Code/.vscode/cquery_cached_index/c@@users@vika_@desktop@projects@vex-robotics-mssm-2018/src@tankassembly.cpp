#include "main.h"
#include "robot.hpp"
#include "tankAssembly.hpp"

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

// Move by specified relative position
// Used in autonomous
void TankAssembly::moveBase(int speed, double distance) {
  moveLeftSide(speed, distance);
  moveRightSide(speed, distance);
}

void TankAssembly::moveLeftSide(int velocity, double distance) {
  this->motorLeftFront.move_relative(distance, velocity);
  this->motorLeftBack.move_relative(distance, velocity);
}

void TankAssembly::moveRightSide(int  velocity, double distance) {
  this->motorRightFront.move_relative(distance, velocity);
  this->motorRightBack.move_relative(distance, velocity);
}
