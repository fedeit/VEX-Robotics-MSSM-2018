#ifndef _ROBOT_CAP_FLIPPER_HPP_
#define _ROBOT_CAP_FLIPPER_HPP_

#include "direction.hpp"
#include "api.h"

class CapFlipper {
private:
  pros::Motor motor = pros::Motor(6, pros::E_MOTOR_GEARSET_36, false, pros::E_MOTOR_ENCODER_DEGREES);
public:
  void spin(Direction dir);
  void stop();
};

#endif
