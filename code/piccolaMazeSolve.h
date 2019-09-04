void mazeSolve()  /// a right priority algorithm
{
    tofPid();
    tofPid();
    checkWallsCell();
    if (cellWalls[2] == 0)
    {
        nextMove = 'R';
    }

    else if (cellWalls[1] == 0)
    {
        nextMove = 'F';
    }

    else if (cellWalls[0] == 0)
    {
        nextMove = 'L';
    }

    else if (cellWalls[0] == 1)
    {
        nextMove = 'B';
    }
    
    switch (nextMove)
    {
    case 'F' :      //move forward
        cellForward();
        break;
    case 'R' :      //move right
        rightTurn();
        break;

    case 'L' :      //move left
        leftTurn();
        break;
    
    case 'B' :      //move back
        cellBack();
        break;
    }
    
}


void traverse(byte xdes, byte ydes, boolean middleSquare, boolean shortPath){
  
  if (shortPath== false){
  appendDestination(xdes,ydes,middleSquare);
  floodFill3();

  
  
  while(flood[y][x]!=0){
    tofPid();
    tofPid();
    checkWallsCell();
    updateWalls(x, y, orient, L, R, F);
    
    //cells[y][x]= sliit[y][x];
    
    appendDestination(xdes,ydes,middleSquare);
    floodFill3();
    dir= toMove(x,y,xprev,yprev,orient);

    //Serial.println(dir);
    
        if (dir=='L'){
            orient = orientation(orient,'L');
            leftTurn();
        }

        else if (dir=='R'){
            orient = orientation(orient,'R');
            //rightTurn();
            rightSmoothTurn();
        }

        else if (dir=='B'){
            orient = orientation(orient,'L');
            orient = orientation(orient,'L');
            cellBack();
        }
        else{
          if(x==0 && y==0){
            cellStart();
            brake();
            delay(1000);
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
      while(flood2[y][x]!=1){


    tofPid();
    tofPid();
    checkWallsCell();
    updateWalls(x, y, orient, L, R, F);
    toMove2();

    //Serial.println(dir);
    
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
            brake();
            delay(1000);
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
}
