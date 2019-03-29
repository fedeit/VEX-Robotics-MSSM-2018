#ifndef ROBOT_DISPLAY_H
#define ROBOT_DISPLAY_H

#include "teamColor.hpp"
#include "startingPosition.hpp"

class Display {
public:
    TeamColor chooseTeamColor();
    StartingPosition chooseStartingTile();
    bool checkColor();
    bool checkTile();
};

#endif
