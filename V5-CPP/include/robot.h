#ifndef ROBOT_H
#define ROBOT_H

class Robot {
    RobotBallIntake ballIntake;
    RobotBallShooter ballShooter;
    RobotCapFlipper capFlipper;
    RobotTankAssembly tankAssembly;
    StartingPosition startPos;
    TeamColor teamColor;
    RobotDisplay brainDisplay;
    Controller master;
public:
    Robot();
    void runAutonomous();
    void runManual();
    void runDisplaySetup();
};

#endif

