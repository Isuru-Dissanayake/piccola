/*void mazeSolve()  /// a right priority algorithm
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
*/


void calculatePath(){
  floodFill2();
  x=0;
  y=0;
  char prevDir;
  byte oldOrient= orient;
  int forwardCellCount =0;
  toMove2();
  prevDir= dir;
  
    while(flood2[y][x]!=1){

        toMove2();
    
        //Serial.println(dir);

        if (prevDir=='F' && prevDir== dir){
          forwardCellCount++;
        }
        else if( prevDir=='F' && prevDir!=dir){
          pathQueue.enqueue(char(forwardCellCount+1));
        }
        else{
          pathQueue.enqueue(prevDir);
          forwardCellCount=0;
        }

    
        if (prevDir=='L'){
            orient = orientation(orient,'L');
        }

        else if (prevDir=='R'){
            orient = orientation(orient,'R');
        }

        else if (prevDir=='B'){
            orient = orientation(orient,'L');
            orient = orientation(orient,'L');
        }

        
        xprev=x;
        yprev=y;
        updateCoordinates();
        prevDir= dir;
        
  }
  if (prevDir =='F')
    pathQueue.enqueue(char(forwardCellCount+1));
  else
    pathQueue.enqueue(prevDir);

  
        if (prevDir=='L'){
            orient = orientation(orient,'L');
        }

        else if (prevDir=='R'){
            orient = orientation(orient,'R');
        }

        else if (prevDir=='B'){
            orient = orientation(orient,'L');
            orient = orientation(orient,'L');
        }

        
        xprev=x;
        yprev=y;
        updateCoordinates();

        x=0;
        y=0;
        orient=oldOrient;

    
}








void traverse(byte xdes, byte ydes, boolean middleSquare, boolean shortPath){
  int forwardCellCount=0;

  if (shortPath== false){
  appendDestination(xdes,ydes,middleSquare);
  floodFill3();

  //tofPid();
  //tofPid();
  //checkWallsCell();
  updateWalls(x, y, orient, L, R, F);
  
  while(flood[y][x]!=0){
    
    //cells[y][x]= sliit[y][x];
    
    appendDestination(xdes,ydes,middleSquare);
    floodFill3();
    dir= toMove(x,y,xprev,yprev,orient);

    //Serial.println(dir);
    
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

    calculatePath();
    
    while (!pathQueue.isEmpty ()){

    dir= pathQueue.dequeue();
    
        if (dir=='L'){
            orient = orientation(orient,'L');
            leftSmoothTurn();
            xprev=x;
            yprev=y;
            updateCoordinates();
        }

        else if (dir=='R'){
            orient = orientation(orient,'R');
            rightSmoothTurn();
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
          forwardCellCount= String(dir).toInt();
          ///////////////////////you have to move this much of cells forward. accelarate as you wish

          // but call xprev=x; yprev=y; updateCoordinates(); every time you run a cell.
          for (int i= forwardCellCount; i>0; i--){
            cellForward();
            xprev=x;
            yprev=y;
            updateCoordinates();
          }
          
        }
        
        
        
        
  }
  }
}
