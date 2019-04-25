#ifndef ROBOT_TANK_ASSEMBLY_HPP
#define ROBOT_TANK_ASSEMBLY_HPP

#include "main.h"

const double D_ROBOT = 24.7;// inches;
const double D_WHEEL = 4.75;
const double _PI = 3.1415926;
const double IN_R = 1/(_PI*D_WHEEL);

class TankAssembly {
private:
  // Tank pros motors
  pros::Motor motorLeftFront = pros::Motor(16, pros::E_MOTOR_GEARSET_18, false, pros::E_MOTOR_ENCODER_DEGREES);
  pros::Motor motorLeftBack = pros::Motor(17, pros::E_MOTOR_GEARSET_18, false, pros::E_MOTOR_ENCODER_DEGREES);
  pros::Motor motorRightFront = pros::Motor(10, pros::E_MOTOR_GEARSET_18, true, pros::E_MOTOR_ENCODER_DEGREES);
  pros::Motor motorRightBack  = pros::Motor(6, pros::E_MOTOR_GEARSET_18, true, pros::E_MOTOR_ENCODER_DEGREES);
  // Create Okapi objects

  double currentY = 0.0;
  double currentX = 0.0;
  double currentAngle = 0.0;
public:
    void moveBase(std::int8_t velocity);
    void moveLeftSide(std::int8_t velocity);
    void moveRightSide(std::int8_t velocity);

    void goToPosition(double targetX, double targetY); // 0 to 108 in each
    void goToTile(int targetX, int targetY); // 1 to 6 each
    void turnByAngle(double angle);
    void driveStraightBy(double distance);
    void driveStraightByTiles(int tiles);
    void pickupCap();
    void releaseCap();

    // Relative movement
    // void moveBase(int velocity, double distance);
    // void moveLeftSide(int velocity, double distance);
    // void moveRightSide(int velocity, double distance);
};

#endif
