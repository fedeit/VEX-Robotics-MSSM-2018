#include "main.h"
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

<<<<<<< HEAD
void RobotTankAssembly::moveRightSide(std::int8_t velocity) {
    baseMotorRightFront.move(velocity);
    baseMotorRightBack.move(velocity);
}

// Move by specified relative position
// Used in autonomous
void RobotTankAssembly::moveBase(std::int32_t velocity, double position) {
    moveLeftSide(velocity, position);
    moveRightSide(velocity, position);
}

void RobotTankAssembly::moveRightSide(std::int32_t velocity, double position) {
  baseMotorRightFront.move_relative(position, velocity);
  baseMotorRightBack.move_relative(position, velocity);
=======
// Used by the autonomous function
void RobotTankAssembly::moveByTiles(double speed, double tiles) {
  float distance = tiles;
  baseMotorLeftBack.move_absolute(distance, 100); // Moves 100 units forward
  baseMotorLeftFront.move_absolute(distance, 100); // Moves 100 units forward
  baseMotorRightFront.move_absolute(distance, 100); // Moves 100 units forward
  baseMotorRightBack.move_absolute(distance, 100); // Moves 100 units forward

  while (!((baseMotorRightBack.get_position() < distance + 5) && (baseMotorRightBack.get_position() > distance - 5))) {
    pros::delay(2);
  }

  baseMotorRightBack.move(0);
  baseMotorLeftFront.move(0);
  baseMotorRightFront.move(0);
  baseMotorLeftBack.move(0);

  baseMotorRightBack.tare_position();
  baseMotorLeftFront.tare_position();
  baseMotorRightFront.tare_position();
  baseMotorLeftBack.tare_position();
>>>>>>> fbff09d6c8eb84b7a11a9d8803b67f762c1400b2
}

void RobotTankAssembly::moveLeftSide(std::int32_t velocity, double position) {
  baseMotorLeftFront.move_relative(position, velocity);
  baseMotorLeftBack.move_relative(position, velocity);
}

// Used by the autonomous function
void RobotTankAssembly::moveByTiles(std::int32_t velocity, unsigned int tiles) {
  moveBase(velocity, velocity > 0 ? tiles*TILE_SIZE : -tiles*TILE_SIZE);
}

void RobotTankAssembly::rotateBaseByAngle(double angle) {
  // Rotation by the angle
}
