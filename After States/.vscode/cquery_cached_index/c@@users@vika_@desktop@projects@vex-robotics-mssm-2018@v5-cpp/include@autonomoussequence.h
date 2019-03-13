#ifndef AUTONOMOUS_SEQUENCE_H
#define AUTONOMOUS_SEQUENCE_H

#include "teamColor.h"
#include "startingPosition.h"


class AutonomousSequence {
  StartingPosition startPos;
  TeamColor teamColor;
  int angleFlipFactor;

public:
  AutonomousSequence(StartingPosition startingTile, TeamColor teamColor);
  void runSequence();
};


#endif
