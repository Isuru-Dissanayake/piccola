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
        
        
  }

        
        x=0;
        y=0;
        orient=oldOrient;   
        EEPROM.write(0,cellCount);
}

void traverse(byte xdes, byte ydes, boolean middleSquare, boolean shortPath, boolean eeprom){

  if (shortPath== false){
  appendDestination(xdes,ydes,middleSquare);
  floodFill3();
  checkWallsCell();
  updateWalls(x, y, orient, L, R, F);
  while(flood[y][x]!=0){
    
    checkWallsCell();
    updateWalls(x, y, orient, L, R, F);
    appendDestination(xdes,ydes,middleSquare);
    floodFill3();
    dir= toMove(x,y,xprev,yprev,orient);
        if (dir=='L'){
            orient = orientation(orient,'L');
            if(x==0){
              if(y==0){
                leftAboutTurn();
                cellStart();
              }
              else{
                leftTurn();
              }
            }
            else{
            leftTurn();}
        }

        else if (dir=='R'){
          orient = orientation(orient,'R');
            if(x==0){
              if(y==0){
                rightAboutTurn();
                cellStart();
              }
              else{
                rightTurn();
              }
            }
            else{
            rightTurn();}
        }

        else if (dir=='B'){
            orient = orientation(orient,'L');
            orient = orientation(orient,'L');
            if(x==0 && y==0){
              turnBack();
              cellStart();
              }
              else{
              cellBack();
              }
        }
        else{
          if(x==0 && y==0){
            cellStart();
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

    if (eeprom== true){
      cellCount= EEPROM.read(0);
      char shortestPath[cellCount];

      for( int i=0; i<cellCount;i++){

        shortestPath[i]= char(EEPROM.read(i+1));
      }

      for (int i=0; i<cellCount; i++){
        dir = shortestPath[i];

        if (dir=='L'){
            orient = orientation(orient,'L');
            if(x==0 && y==0){
              leftAboutTurn();
              cellStart();
            }
            else{
            leftTurn();}
            
        }

        else if (dir=='R'){
            orient = orientation(orient,'R');
            if(x==0 && y==0){
              rightAboutTurn();
              cellStart();
            }
            else{
            rightTurn();}
        }

        else if (dir=='B'){
            orient = orientation(orient,'L');
            orient = orientation(orient,'L');
            if(x==0 && y==0){
              turnBack();
              cellStart();
            }
            else{
            cellBack();}
          }
        
        else{
          if(x==0 && y==0){
              cellStart();
            }
            else{
            cellForward();}
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
            if(x==0 && y==0){
              leftAboutTurn();
              cellStart();
            }
            else{
            leftTurn();}
            
        }

        else if (dir=='R'){
            orient = orientation(orient,'R');
            if(x==0 && y==0){
              rightAboutTurn();
              cellStart();
            }
            else{
            rightTurn();}
        }

        else if (dir=='B'){
            orient = orientation(orient,'L');
            orient = orientation(orient,'L');
            if(x==0 && y==0){
              turnBack();
              cellStart();
            }
            else{
            cellBack();}
          }
        
        else{
          if(x==0 && y==0){
              cellStart();
            }
            else{
            cellForward();}
          }

          xprev=x;
          yprev=y;
          updateCoordinates();
          
        }   
    }
  }
  }
