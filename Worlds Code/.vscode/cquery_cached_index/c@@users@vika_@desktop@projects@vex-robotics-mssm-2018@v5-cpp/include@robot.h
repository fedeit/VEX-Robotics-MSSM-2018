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
#include "robotCapDescore.h"
#include "startingPosition.h"
#include "autonomousSequence.h"

class Robot {
    pros::Controller master = pros::Controller(pros::E_CONTROLLER_MASTER);
public:
    RobotBallIntake ballIntake = RobotBallIntake();
    RobotBallShooter ballShooter = RobotBallShooter();
    RobotCapFlipper capFlipper = RobotCapFlipper();
    RobotCapDescore descore = RobotCapDescore();
    RobotTankAssembly tankAssembly = RobotTankAssembly();
    StartingPosition startPos;
    TeamColor teamColor;
    RobotDisplay brainDisplay = RobotDisplay();
    Robot();
    void runAutonomous();
    void runManual();
    void runDisplaySetup();
};

#endif
