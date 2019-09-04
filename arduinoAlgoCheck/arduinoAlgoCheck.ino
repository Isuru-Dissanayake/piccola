#include <EEPROM.h>
#include "piccolaZlgoVariables.h"
#include "piccolaZlgo.h"
#include "piccolaZlgoSupport.h"
#include "piccolaMazeSolve.h"


void setup()
{   
    Serial2.begin(9600);
}

void loopt(){
  appendDestination(0,13,false);
  floodFill3();
  showFlood();
  while(1){
  }
}

void loopq(){
/*  
//traverse(byte xdes, byte ydes, boolean middleSquare, boolean shortPath)
traverse(0,0,true,false);  // traverses to center
Serial.println(' ');
Serial.println(' ');
center();  //saves the walls of the middle square
showCells();
Serial.println(' ');
Serial.println(' ');


traverse(0,0,false,false);  // traverses back to the starting square
Serial.println(' ');
Serial.println(' ');
showCells();
Serial.println(' ');
Serial.println(' ');
traverse(0,0,true,true);
showCells();
Serial.println(' ');

while(1){}
*/
}

void loop(){
  for (int i=0; i<100; i++){
    EEPROM.write(i,'F');
  }

  for(int i=0 ; i<100; i++){
    Serial2.println(EEPROM.read(i));
  }
}
