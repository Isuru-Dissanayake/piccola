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
    delay(1000);
}

void loop()
{
    tofPid();
    if (tof[2] <80)
    {
        buzz();
        delay(500);
        start = 1;
    }
    if (start == 1)
    {
        delay(1000);
        /*traverse(0,0,true,false,false);
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
       
        floodFill2();*/
        traverse(0,0,true,true,true);
        while(1){brake();} 
    }
}
void loopu(){
  for (int i=0; i<14;i++){
    for (int j=0; j<14;j++){
      cells[j][i]=sliit[j][i];
    }
  }

  Serial2.println(1000);
  calculatePath(false,true);
  /*for (int j=0; j<14;j++){
      EEPROM.write(j,j);
    }

  for (int j=0; j<14;j++){
      Serial2.println(EEPROM.read(j));
    }*/

  cellCount= EEPROM.read(0);
  char shortestPath[cellCount];

  for( int i=0; i<cellCount;i++){

        shortestPath[i]= char(EEPROM.read(i+1));
  }

for (int i=0; i<cellCount; i++){
  dir = shortestPath[i];
  Serial2.println(dir);
  }
  while(1){}
  
}
