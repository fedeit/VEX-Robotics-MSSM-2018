#include "main.h"
#include "robotTankAssembly.h"
#include "robotMotorDeclarations.h"
#include "teamColor.h"
#include "direction.h"

// Speed out of 200 (RPM). If direction == stop, stop even if speed != 0
void RobotTankAssembly::moveBase(double speed, Direction direction) {
    moveLeftSide(speed, direction);
    moveRightSide(speed, direction);
}

void RobotTankAssembly::moveLeftSide(double speed, Direction direction) {
    switch (direction) {
        case stop: speed = 0;
        case forward: speed = fabs(speed);
        case backward: speed = -1 * fabs(speed);
    }
    baseMotorLeftFront.move_velocity(speed);
    baseMotorLeftBack.move_velocity(speed);
}

void RobotTankAssembly::moveRightSide(double speed, Direction direction) {
    switch (direction) {
        case stop: speed = 0;
        case forward: speed = fabs(speed);
        case backward: speed = -1 * fabs(speed);
    }
    baseMotorRightFront.move_velocity(speed);
    baseMotorRightBack.move_velocity(speed);
}

// Speed in range +- 127, used for controller analog
void RobotTankAssembly::moveLeftSide(double speed) {
    baseMotorLeftFront.move(speed);
    baseMotorLeftBack.move(speed);
}

void RobotTankAssembly::moveRightSide(double speed) {
    baseMotorRightFront.move(speed);
    baseMotorRightBack.move(speed);
}

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
}

void RobotTankAssembly::rotateBaseOfAngle(double angle) {

}
