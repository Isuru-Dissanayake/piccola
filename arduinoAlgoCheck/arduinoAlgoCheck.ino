#include "piccolaZlgo.h"
#include "piccolaZlgoSupport.h"

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  Serial.println(' ');
  Serial.println(' ');
  //showFlood();
  Serial.println(' ');
  Serial.println(' ');
  //showCells();
  
  getWalls();
  
  
}
