//
//  flipper.c
//
//  This file contains flipper's functionality
//  Created by Federico Galbiati and Alex Nikanov on 10/11/2018.
//

#include "main.h"
#include "settings.h"
#include "flipper.h"


void flipperControl(int speed){
  if (!speed)
    speed = 127;
  motorSet(flipperMotor, speed); // Works constantly?
}
