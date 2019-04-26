#ifndef ROBOT_DISPLAY_HPP
#define ROBOT_DISPLAY_HPP

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
