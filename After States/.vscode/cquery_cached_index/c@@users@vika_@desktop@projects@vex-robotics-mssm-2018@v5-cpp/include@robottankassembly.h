#ifndef ROBOT_TANK_ASSEMBLY_H
#define ROBOT_TANK_ASSEMBLY_H

#include "teamColor.h"
#include "direction.h"

#include "main.h"

class RobotTankAssembly {
public:

    // Speed values in rangee +- 127 for joysticks
    void moveBase(std::int8_t velocity);
    void moveLeftSide(std::int8_t velocity);
    void moveRightSide(std::int8_t velocity);

    // Relative movement
    void moveBase(int velocity, double distance);
    void moveLeftSide(int velocity, double distance);
    void moveRightSide(int velocity, double distance);

    // Mainly used by autonomous sequences
    void moveByTiles(int speed, double tiles);
    void rotateBaseByAngle(double angle);
};

#endif
