#include <VL6180X.h>
#include <Wire.h>
#include <EEPROM.h>
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
    pinMode(buzzer, OUTPUT);
    attachInterrupt(digitalPinToInterrupt(PB12), countLeftOut1, RISING);
    attachInterrupt(digitalPinToInterrupt(PB13), countLeftOut1, RISING);
    attachInterrupt(digitalPinToInterrupt(PB14), countRightOut1, RISING);
    attachInterrupt(digitalPinToInterrupt(PB15), countRightOut1, RISING);
    Serial2.begin(9600);
}

void loopaaaa()
{
     mazeStart();
    if (selectMode == 1)
    {
        delay(1000);
        traverse(0,0,true,false,false);
        checkWallsCell();
        updateWalls(x, y, orient, L, R, F);
        cellBrake();
        
        center();
        
        calculatePath(false,true);
        delay(3000);

        traverse(0,0,false,false,false);
        cellBrake();
        fixOrientation();
        
        delay(1000);
    }
    
    else if(selectMode==2){
        floodFill2();
        traverse(0,0,true,true,true);
        } 
}
