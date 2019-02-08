#ifndef ROBOT_TANK_ASSEMBLY_H
#define ROBOT_TANK_ASSEMBLY_H

#include "teamColor.h"
#include "direction.h"

class RobotTankAssembly {
public:
    void moveBase(std::int16_t speed, Direction direction);
    void moveLeftSide(std::int16_t speed, Direction direction);
    void moveRightSide(std::int16_t speed, Direction direction);

    // Speed values in rangee +- 127 for joysticks
    void moveBase(std::int8_t velocity);
    void moveLeftSide(std::int8_t velocity);
    void moveRightSide(std::int8_t velocity);

    // Relative movement
    void moveBase(std::uint32_t velocity, double position);
    void moveLeftSide(std::uint32_t velocity, double position);
    void moveRightSide(std::uint32_t velocity, double position);

    // Mainly used by autonomous sequences
    void moveByTiles(std::uint32_t velocity, double tiles);
    void rotateBaseByAngle(double angle);
};

#endif
