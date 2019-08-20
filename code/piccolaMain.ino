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
#include "piccolaMazeSolve.h"



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

void loopww()
{
    delay(1000);
    mazeStart();
    brake();
    delay(1000);
    while(1)
    {
        mazeSolve();
    }
    
}

void loopj()
{
    tofPid();
    //printTof();
    wallPid();
    forward();
    
}

void loop()
{
    delay(1000);
    cellStart();
    cellBrake();
    cellStart();
    cellForward();
    cellForward();
    cellBrake();
    
}
