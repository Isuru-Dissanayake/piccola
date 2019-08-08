#include <VL6180X.h>
#include <Wire.h>
int y = 0;
#include "piccolaPins.h"
#include "piccolaVariables.h"
#include "piccolaTof.h"
#include "piccolaMotors.h"
#include "piccolaTurns.h"



void setup()
{
    tofSetup();
    motorDiver();
    motorInterrupt();
    attachInterrupt(digitalPinToInterrupt(PB12), countLeftOut1, RISING);
    attachInterrupt(digitalPinToInterrupt(PB13), countLeftOut2, RISING);
    attachInterrupt(digitalPinToInterrupt(PB14), countRightOut1, RISING);
    attachInterrupt(digitalPinToInterrupt(PB15), countRightOut1, RISING);
    Serial2.begin(9600);
}


void loopm()
{ 
  forwardBase();
  //Serial2.println("reverse");
  delay(2000);
  brake();
  delay(1000);
  forwardBase();
  //Serial2.println("forward");
  delay(2000);
  brake();
  delay(1000);
  Serial2.println(leftEncoder);
  Serial2.println(rightEncoder);
  leftEncoder = 0;
  rightEncoder = 0;


}
void loop()
{
  delay(1000);
  leftEncoder = 0;
  while (leftEncoder <1200)
  {
    forwardBase();
  }
  brake();
  delay(2000);
}
