#ifndef ROBOT_TANK_ASSEMBLY_HPP
#define ROBOT_TANK_ASSEMBLY_HPP

#include "main.h"

class TankAssembly {
private:
  // Tank pros motors
  pros::Motor motorLeftFront = pros::Motor(16, pros::E_MOTOR_GEARSET_18, false, pros::E_MOTOR_ENCODER_DEGREES);
  pros::Motor motorLeftBack = pros::Motor(17, pros::E_MOTOR_GEARSET_18, false, pros::E_MOTOR_ENCODER_DEGREES);
  pros::Motor motorRightFront = pros::Motor(10, pros::E_MOTOR_GEARSET_18, true, pros::E_MOTOR_ENCODER_DEGREES);
  pros::Motor motorRightBack  = pros::Motor(6, pros::E_MOTOR_GEARSET_18, true, pros::E_MOTOR_ENCODER_DEGREES);
  // Create Okapi objects

  void turnByAngle(float angle);
  void driveStraightBy(float distance);
  float currentY = 0.0;
  float currentX = 0.0;
  float currentAngle = 0.0;
public:
    void moveBase(std::int8_t velocity);
    void moveLeftSide(std::int8_t velocity);
    void moveRightSide(std::int8_t velocity);

    void goToPosition(int targetX, int targetY);
    void pickupCap();
    void releaseCap();

    // Relative movement
    // void moveBase(int velocity, double distance);
    // void moveLeftSide(int velocity, double distance);
    // void moveRightSide(int velocity, double distance);
};

#endif
