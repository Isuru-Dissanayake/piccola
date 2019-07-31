#include <Wire.h>
#include <VL6180X.h>

#include "piccolaPins.h"
#include "piccolaVariables.h"
#include "piccolaMotors.h"
#include "piccolaTurns.h"
#include "piccolaTof.h"
#include "piccolaWallPid.h"
#include "piccolaMazeSolve.h"

void setup()
{
    motorDiver();
    motorInterrupt();
    tofSetup();
    Serial.begin(9600);
}

void loop()
{

}