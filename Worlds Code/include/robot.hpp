#ifndef _ROBOT_HPP_
#define _ROBOT_HPP_

#include "main.h"
#include "display.hpp"
#include "capFlipper.hpp"
#include "tankAssembly.hpp"
#include "lift.hpp"
#include "startingPosition.hpp"
#include "robotSensors.hpp"

class Robot {
public:
    pros::Controller controller = pros::Controller(pros::E_CONTROLLER_MASTER);
    CapFlipper capFlipper = CapFlipper();
    Lift lift = Lift();
    TankAssembly tankAssembly = TankAssembly();
    Display display = Display();
    RobotSensors robotSensors = RobotSensors();
    TeamColor teamColor = TeamColor::red;
    void runDisplaySetup();
    void calibrate();
};

extern Robot robot;

#endif
