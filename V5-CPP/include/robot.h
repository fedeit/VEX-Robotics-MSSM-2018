#ifndef ROBOT_H
#define ROBOT_H

#include "main.h"
#include "api.h"
#include "robotDisplay.h"
#include "robotCapFlipper.h"
#include "robotBallIntake.h"
#include "robotBallShooter.h"
#include "robotTankAssembly.h"
#include "robotCapFlipper.h"
#include "startingPosition.h"
#include "autonomousSequence.h"

class Robot {
    RobotBallIntake ballIntake;
    RobotBallShooter ballShooter;
    RobotCapFlipper capFlipper;
    RobotTankAssembly tankAssembly;
    StartingPosition startPos;
    TeamColor teamColor;
    RobotDisplay brainDisplay;
    pros::Controller master = pros::Controller(pros::E_CONTROLLER_MASTER);
public:
    Robot();
    void runAutonomous();
    void runManual();
    void runDisplaySetup();
};

#endif
