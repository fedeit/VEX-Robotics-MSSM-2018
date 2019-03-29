#ifndef ROBOT_DISPLAY_H
#define ROBOT_DISPLAY_H

#include "teamColor.hpp"
#include "startingPosition.hpp"

class RobotDisplay {
public:
    TeamColor chooseTeamColor();
    StartingPosition chooseStartingTile();
    bool checkColor();
    bool checkTile();
};

#endif
