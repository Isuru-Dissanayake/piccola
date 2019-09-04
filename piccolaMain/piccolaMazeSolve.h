void calculatePath(boolean runningNext,boolean eeprom){
  floodFill2();
  x=0;
  y=0;
  //char prevDir;
  byte oldOrient= orient;
  
  cellCount=0;
  //prevDir= dir;
  
    while(flood2[y][x]!=1){

        toMove2();
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
}

void traverse(byte xdes, byte ydes, boolean middleSquare, boolean shortPath){
  //int forwardCellCount=0;

  if (shortPath== false){
  appendDestination(xdes,ydes,middleSquare);
  floodFill3();
  //tofPid();
  //tofPid();
  checkWallsCell();
  updateWalls(x, y, orient, L, R, F);
  while(flood[y][x]!=0){
    
    //cells[y][x]= sliit[y][x];
    checkWallsCell();
    updateWalls(x, y, orient, L, R, F);
    appendDestination(xdes,ydes,middleSquare);
    floodFill3();
    dir= toMove(x,y,xprev,yprev,orient);
        if (dir=='L'){
            orient = orientation(orient,'L');
            leftTurn();
        }

        else if (dir=='R'){
            orient = orientation(orient,'R');
            rightTurn();
        }

        else if (dir=='B'){
            orient = orientation(orient,'L');
            orient = orientation(orient,'L');
            cellBack();
        }
        else{
          if(x==0 && y==0){
            cellStart();
            //brake();
            //delay(1000);
          }
          else{
          cellForward();
          }
        }
        xprev=x;
        yprev=y;
        updateCoordinates();
  }
  }

  else{

    calculatePath(true,false);
    while (!pathQueue.isEmpty ()){
    dir= pathQueue.dequeue();
    
        if (dir=='L'){
            orient = orientation(orient,'L');
            leftTurn();
            xprev=x;
            yprev=y;
            updateCoordinates();
        }

        else if (dir=='R'){
            orient = orientation(orient,'R');
            rightTurn();
            xprev=x;
            yprev=y;
            updateCoordinates();
        }

        else if (dir=='B'){
            orient = orientation(orient,'L');
            orient = orientation(orient,'L');
            cellBack();
            xprev=x;
            yprev=y;
            updateCoordinates();
        }
        else{
          cellForward();
          xprev = x;
          yprev = y;
          updateCoordinates();
          }
          
        }   
  }
  }
