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
    attachInterrupt(digitalPinToInterrupt(PB13), countLeftOut1, RISING);
    attachInterrupt(digitalPinToInterrupt(PB14), countRightOut1, RISING);
    attachInterrupt(digitalPinToInterrupt(PB15), countRightOut1, RISING);
    Serial2.begin(9600);
}

void loopd()
{
    delay(1000);
    while(1)
    {
        mazeSolve();
    }
}

void loop()
{
    delay(1000);
    leftAboutTurn();
    brake();
}