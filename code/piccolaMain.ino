#include <VL6180X.h>
#include <Wire.h>
#include "piccolaPins.h"
#include "piccolaVariables.h"
#include "piccolaTof.h"
#include "piccolaMotors.h"
#include "piccolaTurns.h"
#include "piccolaWallPid.h"
#include "piccolaSpeed.h"
#include "piccolaMoves.h"

unsigned long time;

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

void loopg()
{
    delay(1000);
    //cellStart();
    while (1)
    {
        delay(2000);
        tofPid();
        checkWallsCell();
        printTof();
        delay(1000);
        printWallState();
        delay(4000);
        if (cellWalls[2] == 0)
        {
            rightTurn();
            brake();
            delay(1000);
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
            brake();
            delay(1000);
        }

        else if(cellWalls[0] == 0)
        {
            leftTurn();
            brake();
            delay(1000);
        }

        else
        {
            cellBrake();
            turnBack();
            cellStart();
            brake();
        }
    }
}




void looph()
{
    delay(1000);
    cellStart();
    cellForward();
    rightTurn();
    leftTurn();
    cellForward();
    cellForward();
    rightTurn();
    rightTurn();
    leftTurn();
    cellForward();
    rightTurn();
    leftTurn();
    leftTurn();
    rightTurn();
    leftTurn();
    cellForward();
    cellBrake();
    delay(3000);
}

void loop()
{
    tofCell();
    checkWallsCell();
    printTof();
    printWallState();
}
