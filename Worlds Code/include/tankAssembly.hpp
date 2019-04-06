#ifndef ROBOT_TANK_ASSEMBLY_H
#define ROBOT_TANK_ASSEMBLY_H

#include "main.h"
#include "api.h"

using namespace pros;

class TankAssembly {
private:
  Motor motorLeftFront = Motor(16, E_MOTOR_GEARSET_18, false, E_MOTOR_ENCODER_DEGREES);
  Motor motorLeftBack = Motor(17, E_MOTOR_GEARSET_18, false, E_MOTOR_ENCODER_DEGREES);
  Motor motorRightFront = Motor(10, E_MOTOR_GEARSET_18, true, E_MOTOR_ENCODER_DEGREES);
  Motor motorRightBack  = Motor(8, E_MOTOR_GEARSET_18, true, E_MOTOR_ENCODER_DEGREES);
public:
    void moveBase(std::int8_t velocity);
    void moveLeftSide(std::int8_t velocity);
    void moveRightSide(std::int8_t velocity);

    // Relative movement
    void moveBase(int velocity, double distance);
    void moveLeftSide(int velocity, double distance);
    void moveRightSide(int velocity, double distance);
};

#endif
