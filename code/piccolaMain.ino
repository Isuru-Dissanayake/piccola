#include <Wire.h>
#include <VL6180X.h>

#include "piccolaPins.h"
#include "piccolaVariables.h"
#include "piccolaMotors.h"
#include "piccolaTurns.h"
#include "piccolaSpeed.h"
#include "piccolaTof.h"
#include "piccolaWallPid.h"
#include "piccolaMazeSolve.h"

void setup()
{
    motorDiver();
    motorInterrupt();
    tofSetup();

    attachInterrupt(digitalPinToInterrupt(2), countLeftOut1, RISING);
    attachInterrupt(digitalPinToInterrupt(3), countLeftOut2, RISING);
    //attachInterrupt(digitalPinToInterrupt(4), countRightOut1, RISING);
    //attachInterrupt(digitalPinToInterrupt(5), countRightOut1, RISING);

    Serial2.begin(9600);
}

void loop()
{

}