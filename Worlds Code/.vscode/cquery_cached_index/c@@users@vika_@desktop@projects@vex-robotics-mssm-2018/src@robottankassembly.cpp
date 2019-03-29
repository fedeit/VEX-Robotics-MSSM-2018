#include "main.h"
#include "robot.hpp"
#include "robotTankAssembly.hpp"

void RobotTankAssembly::moveBase(std::int8_t velocity) {
  moveLeftSide(velocity);
  moveRightSide(velocity);
}

void RobotTankAssembly::moveLeftSide(std::int8_t velocity) {
    baseMotorLeftFront.move(velocity);
    baseMotorLeftBack.move(velocity);
}

void RobotTankAssembly::moveRightSide(std::int8_t velocity) {
    baseMotorRightFront.move(velocity);
    baseMotorRightBack.move(velocity);
}

// Move by specified relative position
// Used in autonomous
void RobotTankAssembly::moveBase(int speed, double distance) {
    moveLeftSide(speed, distance);
    moveRightSide(speed, distance);
}

void RobotTankAssembly::moveLeftSide(int velocity, double distance) {
  baseMotorLeftFront.move_relative(distance, velocity);
  baseMotorLeftBack.move_relative(distance, velocity);
}

void RobotTankAssembly::moveRightSide(int  velocity, double distance) {
  baseMotorRightFront.move_relative(distance, velocity);
  baseMotorRightBack.move_relative(distance, velocity);
}
