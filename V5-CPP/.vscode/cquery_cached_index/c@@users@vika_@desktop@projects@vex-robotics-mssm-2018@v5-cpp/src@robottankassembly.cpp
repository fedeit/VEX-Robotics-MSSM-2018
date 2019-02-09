#include "main.h"
#include "robot.h"
#include "robotTankAssembly.h"
#include "robotMotorDeclarations.h"
#include "teamColor.h"
#include "direction.h"
#include "constants.h"

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

// Used by the autonomous function
void RobotTankAssembly::moveByTiles(int speed, double tiles) {
  moveBase(speed, tiles * TILE_SIZE);
  while (baseMotorLeftBack.get_actual_velocity() != 0) {
    pros::delay(2);
  }
}

/// \param angle From -180 to +180, positive is clockwise
void RobotTankAssembly::rotateBaseByAngle(double angle) {
  moveLeftSide(200, angle/90*_90_DEGREE_ROTATION);
  moveRightSide(200, -angle/90*_90_DEGREE_ROTATION);
  while (baseMotorLeftBack.get_actual_velocity() != 0) {
    pros::delay(2);
  }
}
