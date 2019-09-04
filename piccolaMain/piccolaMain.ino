#include <VL6180X.h>
#include <Wire.h>
#include "EEPROM.h"
#include "piccolaPins.h"
#include "piccolaZlgoVariables.h"
#include "piccolaVariables.h"
#include "piccolaTof.h"
#include "piccolaMotors.h"
#include "piccolaTurns.h"
#include "piccolaWallPid.h"
#include "piccolaSpeed.h"
#include "piccolaMoves.h"
#include "piccolaZlgo.h"
#include "piccolaMazeSolve.h"

void setup()
{   stbyHigh();
    tofSetup();
    motorDiver();
    motorInterrupt();
    attachInterrupt(digitalPinToInterrupt(PB12), countLeftOut1, RISING);
    attachInterrupt(digitalPinToInterrupt(PB13), countLeftOut1, RISING);
    attachInterrupt(digitalPinToInterrupt(PB14), countRightOut1, RISING);
    attachInterrupt(digitalPinToInterrupt(PB15), countRightOut1, RISING);
    Serial2.begin(9600);
}

void loop()
{
    tofPid();
    if (tof[2] <80)
    {
        start = 1;
    }
    if (start == 1)
    {
        delay(1000);
        cellStart();
        x=0;
        y=1;
        cells[0][0]= 11;
        traverse(0,0,true,false);
        center();
        brake();
        delay(5000);
        traverse(13,0,false,false);
        brake();
        delay(5000);

        traverse(0,0,false,false); 
        floodFill2();
        traverse(0,0,true,true);
        brake();
        delay(5000);
        traverse(0,13,false,false);
        brake();
        delay(5000);

        traverse(0,0,false,false); 
        while(1){brake();} 
    }
}


void loopllll()
{
    tofPid();
    printTof();
}