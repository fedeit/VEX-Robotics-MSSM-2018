#ifndef ROBOT_CAP_DESCORE_H
#define ROBOT_CAP_DESCORE_H

#include "descorePositionEnum.h"

class RobotCapDescore {
  DescorePosition currentPosition = retracted;
public:
  void toggle();
  void extend();
  void retract();
};

#endif
