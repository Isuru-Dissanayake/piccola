#include <VL6180X.h>
#include <Wire.h>
int t = 0;

#include "piccolaPins.h"
#include "piccolaVariables.h"
#include "piccolaTof.h"
#include "piccolaMotors.h"
#include "piccolaTurns.h"
#include "piccolaSpeed.h"
#include "piccolaWallPid.h"
#include "piccolaMazeSolve.h"

void setup()
{
    tofSetup();
    motorDiver();
    pinMode(PC13,OUTPUT);
    pinMode(PA7,OUTPUT);
    pinMode(PB0,OUTPUT);
    pinMode(PB1,OUTPUT);
    //motorInterrupt();
    //attachInterrupt(digitalPinToInterrupt(PB12), countLeftOut1, RISING);
    //attachInterrupt(digitalPinToInterrupt(PB13), countLeftOut2, RISING);
    //attachInterrupt(digitalPinToInterrupt(PB14), countRightOut1, RISING);
    //attachInterrupt(digitalPinToInterrupt(PB15), countRightOut1, RISING);


    //pinMode(PB12, INPUT);
    //pinMode(PC13, OUTPUT);
    //attachInterrupt(digitalPinToInterrupt(PB15), interrupted, CHANGE);
    Serial2.begin(9600);
    
}




void loop()
{ //tofRead();
  //printTof();
  turnRight();
  Serial2.println("reverse");
  delay(1000);
  brake();
  delay(1000);
  turnRight();
  Serial2.println("forward");
  delay(1000);
  brake();
  delay(1000);


}

void loope(){
  Serial2.println("Interrupted");
  digitalWrite(PWMA, HIGH);  //PB8    //motor driver pins
  digitalWrite(PA7, HIGH);  //PA15   ///////////////// AIN2
  digitalWrite(AIN1, LOW);  //PA12
  digitalWrite(STBY, HIGH);  //PA11
  digitalWrite(PB0, HIGH);  //PB3   ////////////////// BIN1
  digitalWrite(PB1, LOW);  //PB4   ////////////////// BIN2
  digitalWrite(PWMB, HIGH);  //PB9
  digitalWrite(PC13, HIGH);  
  delay(2000);
  digitalWrite(PWMA, LOW);  //PB8    //motor driver pins
  digitalWrite(PA7, LOW);  //PA15
  digitalWrite(AIN1, HIGH);  //PA12
  digitalWrite(STBY, LOW);  //PA11
  digitalWrite(PB0, LOW);  //PB3
  digitalWrite(PB1, HIGH);  //PB4
  digitalWrite(PWMB, LOW);  //PB9
  digitalWrite(PC13, LOW); 
  delay(2000);
  
}
/*
  leftEncoder = 0;
  rightEncoder = 0;
  while(t<1000)
  {
    forwardBase();
    t++;
  }
  brake();
  Serial2.println(leftEncoder);
  Serial2.println(rightEncoder);
  
}*/
