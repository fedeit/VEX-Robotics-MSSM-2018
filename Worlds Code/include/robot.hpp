#ifndef _ROBOT_HPP_
#define _ROBOT_HPP_

#include "main.h"
#include "api.h"
#include "display.hpp"
#include "capFlipper.hpp"
#include "tankAssembly.hpp"
#include "lift.hpp"
#include "startingPosition.hpp"

class Robot {
public:
    void initialize();
    pros::Controller controller = pros::Controller(pros::E_CONTROLLER_MASTER);
    CapFlipper capFlipper = CapFlipper();
    Lift lift = Lift();
    TankAssembly tankAssembly = TankAssembly();
    Display display = Display();

    void runDisplaySetup();
    void calibrate();
    void update();
};

extern Robot robot;
#endif
