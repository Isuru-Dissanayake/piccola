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


void traverseToCenter(){
  cellStart();
  brake();
  delay(1000);
  x=0;
  y=1;
  cells[0][0]= 11;
  
  while(flood[y][x]!=0){
    
    tofPid();
    tofPid();
    tofPid();
    checkWallsCell();
    updateWalls(x, y, orient, L, R, F);
    
    //cells[y][x]=sliit[y][x];
    appendZero();
    
    //appendDestination(0,13);
    floodFill3();
    dir= toMove(x,y,xprev,yprev,orient);
    
        if (dir=='L'){
            orient = orientation(orient,'L');
            leftTurn();
            //brake();
            //delay(1000);
        }

        else if (dir=='R'){
            orient = orientation(orient,'R');
            rightTurn();
            //brake();
            //delay(1000);
        }

        else if (dir=='B'){
            orient = orientation(orient,'L');
            orient = orientation(orient,'L');
            cellBack();
            //brake();
            //delay(1000);
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
  center();
  while(1){brake();}
}
