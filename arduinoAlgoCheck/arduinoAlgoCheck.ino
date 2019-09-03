
#include "piccolaZlgoVariables.h"
#include "piccolaZlgo.h"
#include "piccolaZlgoSupport.h"
#include "piccolaMazeSolve.h"

void setup()
{   
    Serial.begin(9600);
}

void loopt(){
  appendDestination(0,13,false);
  floodFill3();
  showFlood();
  while(1){
  }
}

void loop(){
  
//traverse(byte xdes, byte ydes, boolean middleSquare, boolean shortPath)
traverse(0,0,true,false);  // traverses to center
Serial.println(' ');
//showCells();
Serial.println(' ');
center();  //saves the walls of the middle square
showCells();
Serial.println(' ');
//showFlood();
Serial.println(' ');


traverse(0,13,false,false);  // traverses back to the starting square
//showFlood();
showCells();
//appendDestination(0,0,false);
//floodFill3();
traverse(0,0,false,false);
//showFlood();
showCells();
Serial.println(' ');
floodFill2();
//traverse(0,0,true,true);
showFlood2();
traverse(0,0,true,true);
while(1){}

}
