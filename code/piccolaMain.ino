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
    cellStart();
    while (1)
    {
        tofCell();
        checkWallsCell();
        if (cellWalls[2] == 0)
        {
            rightTurn();
            brake();
        }

        else if(cellWalls[1] == 0)
        {
            leftEncoder = 0;
            rightEncoder = 0;
            encoderLeftCount = 1250;
            encoderRightCount = 1250;
            while (leftEncoder <= encoderLeftCount || rightEncoder <= encoderRightCount)
            {
                tofPid();
                checkWallsPid();
                wallFollow();
            }
            //brake();
        }

        else if(cellWalls[0] == 0)
        {
            leftTurn();
            brake();
        }

        else
        {
            cellBrake();
            turnBack();
            cellStart();
        }
        

    }
}

void loopm()
{
    leftEncoder = 0;
    rightEncoder = 0;
    encoderLeftCount = 1280;
    encoderRightCount = 1280;
    while (leftEncoder <= encoderLeftCount || rightEncoder <= encoderRightCount)
    {
    tofPid();
    checkWallsPid();
    wallFollow();
    }
    brake();
    delay(500);
    tofCell();
    checkWallsCell();
    if (wallAvailable[2] == 0)
    {
        rightTurn();
    }
}

void loopd()
{
    tofCell();
    checkWallsCell();
    printWallState();
}