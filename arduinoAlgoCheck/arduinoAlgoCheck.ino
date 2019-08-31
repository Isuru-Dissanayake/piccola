#include "piccolaZlgo.h"
#include "piccolaZlgoSupport.h"

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  x_0=0;
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

void loopu(){
  Serial.println(x_0);
  y_0=x_0-1;
  Serial.println(y_0);
  
}
