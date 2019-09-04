
void calculatePath(boolean runningNext,boolean eeprom){
  floodFill2();
  showFlood2();
  
  x=0;
  y=0;
  byte oldOrient= orient;
  
  cellCount=0;
  
    while(flood2[y][x]!=1){

        toMove2();

        //Serial.println(20);
        //Serial.print(x); Serial.print(' '); Serial.println(y);
        //Serial.println(dir);
        
        if (runningNext){
        pathQueue.enqueue(dir);
        
        }
        if(eeprom){
        cellCount++;
        EEPROM.write(cellCount,dir);}
        
    
        if (dir=='L'){
            orient = orientation(orient,'L');
        }

        else if (dir=='R'){
            orient = orientation(orient,'R');
        }

        else if (dir=='B'){
            orient = orientation(orient,'L');
            orient = orientation(orient,'L');
        }

        
        xprev=x;
        yprev=y;
        updateCoordinates();
        //prevDir= dir;
        
  }
  

        x=0;
        y=0;
        orient=oldOrient;
        Serial.print(x); Serial.print(' '); Serial.println(y);
        Serial.println(orient);
        
    if(eeprom){
        EEPROM.write(0,1);
        EEPROM.write(1,cellCount-1);}
}








void traverse(byte xdes, byte ydes, boolean middleSquare, boolean shortPath){
  int forwardCellCount=0;

  if (shortPath== false){
  appendDestination(xdes,ydes,middleSquare);
  floodFill3();

  //tofPid();
  //tofPid();
  //checkWallsCell();
  //updateWalls(x, y, orient, L, R, F);
  
  while(flood[y][x]!=0){
    
    cells[y][x]= sliit[y][x];
    
    appendDestination(xdes,ydes,middleSquare);
    floodFill3();
    dir= toMove(x,y,xprev,yprev,orient);

    Serial.println(dir);
    
        if (dir=='L'){
            orient = orientation(orient,'L');
            //leftTurn();
        }

        else if (dir=='R'){
            orient = orientation(orient,'R');
            //rightTurn();
        }

        else if (dir=='B'){
            orient = orientation(orient,'L');
            orient = orientation(orient,'L');
            //cellBack();
        }
        else{
          if(x==0 && y==0){
            //cellStart();
            //brake();
            //delay(1000);
          }
          else{
          //cellForward();
          }
        }
        
        
        xprev=x;
        yprev=y;
        updateCoordinates();
        

  }
  }

  else{
    //calculatePath (runningNext, eeprom)
    calculatePath(true,false);
    showFlood2();
    
    while (!pathQueue.isEmpty ()){

    dir= pathQueue.dequeue();
    
        if (dir=='L'){
            orient = orientation(orient,'L');
            //leftSmoothTurn();
            xprev=x;
            yprev=y;
            updateCoordinates();
        }

        else if (dir=='R'){
            orient = orientation(orient,'R');
            //rightSmoothTurn();
            xprev=x;
            yprev=y;
            updateCoordinates();
        }

        else if (dir=='B'){
            orient = orientation(orient,'L');
            orient = orientation(orient,'L');
            //cellBack();
            xprev=x;
            yprev=y;
            updateCoordinates();
        }
        else{
          forwardCellCount= String(dir).toInt();
          ///////////////////////you have to move this much of cells forward. accelarate as you wish

          // but call xprev=x; yprev=y; updateCoordinates(); every time you run a cell.
          for (int i= forwardCellCount; i>0; i--){
            //cellForward();
            xprev=x;
            yprev=y;
            updateCoordinates();
          }
          
        }
        Serial.print(x); Serial.print(' '); Serial.println(y);
        Serial.println(dir);
        
        
        
        
  }
  }
}
