#include "main.h"
#include "robot.h"
#include "robotTankAssembly.h"
#include "robotMotorDeclarations.h"
#include "teamColor.h"
#include "direction.h"
#include "constants.h"

// Speed out of 200 (RPM). If direction == stop, stop even if speed != 0
void RobotTankAssembly::moveBase(std::int16_t speed, Direction direction) {
    moveLeftSide(speed, direction);
    moveRightSide(speed, direction);
}

void RobotTankAssembly::moveLeftSide(std::int16_t speed, Direction direction) {
    switch (direction) {
        case stop: speed = 0;
        case forward: speed = abs(speed);
        case backward: speed = -abs(speed);
    }
    baseMotorLeftFront.move_velocity(speed);
    baseMotorLeftBack.move_velocity(speed);
}

void RobotTankAssembly::moveRightSide(std::int16_t speed, Direction direction) {
    switch (direction) {
        case stop: speed = 0;
        case forward: speed = abs(speed);
        case backward: speed = -abs(speed);
    }
    baseMotorRightFront.move_velocity(speed);
    baseMotorRightBack.move_velocity(speed);
}

// Speed in range +- 127, used for controller analog
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
void RobotTankAssembly::moveBase(std::uint32_t velocity, double position) {
    moveLeftSide(velocity, position);
    moveRightSide(velocity, position);
}

void RobotTankAssembly::moveRightSide(std::uint32_t velocity, double position) {
  baseMotorRightFront.move_relative(position, velocity);
  baseMotorRightBack.move_relative(position, velocity);
}

void RobotTankAssembly::moveLeftSide(std::uint32_t velocity, double position) {
  baseMotorLeftFront.move_relative(position, velocity);
  baseMotorLeftBack.move_relative(position, velocity);
}

// Used by the autonomous function
void RobotTankAssembly::moveByTiles(std::uint32_t speed, double tiles) {
  moveBase(speed, tiles*TILE_SIZE);
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
