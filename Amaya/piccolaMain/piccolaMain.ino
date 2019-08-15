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
    delay(1000);
}

void loop()
{
    if(Serial2.available())
  {
    Val=Serial2.read(); 
  if (Val[0]=='p')
  {
    wallP= float(Val[1:4]);
    Serial2.println(wallP);
  }
  else if (Val[0]=='d')
  {
    wallD= float(Val[1:4]);
    Serial2.println(wallD);
  }
}
