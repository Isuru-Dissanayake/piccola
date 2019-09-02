#include <VL6180X.h>
#include <Wire.h>
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


void loopy()
{
    delay(1000);
    while(1)
    {
        tofPid();
        //wallFollow();
    }
    
}

void loopt(){
  delay(10000);
  cellStart();
  //cellForward();
  cellBrake();
  brake();
  delay(1000);
  Serial2.println(test);
  while(1)
  {
    
  }
}

void loop(){
traverseToCenter();
//wallFollow();
//tofPid();
//printTof();
}
