#include <VL6180X.h>
#include <Wire.h>
#include "piccolaPins.h"
#include "piccolaVariables.h"
#include "piccolaTof.h"
#include "piccolaMotors.h"
#include "piccolaTurns.h"
#include "piccolaWallPid.h"
#include "piccolaSpeed.h"



void setup()
{
    tofSetup();
    motorDiver();
    motorInterrupt();
    attachInterrupt(digitalPinToInterrupt(PB12), countLeftOut1, RISING);
    attachInterrupt(digitalPinToInterrupt(PB13), countLeftOut2, RISING);
    attachInterrupt(digitalPinToInterrupt(PB14), countRightOut1, RISING);
    attachInterrupt(digitalPinToInterrupt(PB15), countRightOut2, RISING);
    Serial2.begin(9600);
}

void loopk()
{
    delay(1000);
    cellStart();
    while(1)
    {
        tofCell();
        checkWallsCell();
        if (cellWalls[1] == 1)
        {
            cellBrake();
            delay(3000);
        }
        else if (cellWalls[0] ==1 && cellWalls[2] == 1)
        {
            forwardBase();
        }

        else if (cellWalls[2] == 0)
        {
            rightTurn();
        }

        else
        {
            leftTurn();
        }
    }
    
    
}

void loop()
{
    delay(1000);
    turnBack();
    //leftTurn();
    /*
    delay(1000);
    cellStart();
    while(1)
    {
        tofPid();
        checkWallsPid();
        wallPid();
        forward();
    }
    */
}