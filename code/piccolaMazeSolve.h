void calculatePath(boolean runningNext,boolean eeprom){
  floodFill2();
  
  byte xprevious=x;
  byte yprevious=y;
  x=0;
  y=0;
  byte oldOrient= orient;
  orient=0;
  
  cellCount=0;
  
    while(flood2[y][x]!=1){

        toMove2();
        //pathQueue.enqueue(dir);

        
        if (runningNext== true){
        pathQueue.enqueue(dir);
        }
        
        if(eeprom){
        cellCount++;
        EEPROM.write(cellCount,dir);
        }
        //Serial2.println(dir);
    
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

        
        x= xprevious;
        y= yprevious;
        orient=oldOrient;   
        EEPROM.write(0,cellCount);
        buzz();
}


void traverse(byte xdes, byte ydes, boolean middleSquare, boolean shortPath, boolean eeprom){

  byte currentx= x;
  byte currenty= y;
  
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
            if(x==0 || x== currentx){
              if(y==0 || y== currenty){
                leftAboutTurn();
                delay(500);
                cellStart();
                currentx=0;
                currenty=0;
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
            if(x==0 || x== currentx){
              if(y==0 || y== currenty){
                rightAboutTurn();
                delay(500);
                cellStart();
                currentx=0;
                currenty=0;
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
            if((x==0 && y==0)||(x== currentx && y== currenty)){
              turnBack();
              delay(500);
              cellStart();
              currentx=0;
                currenty=0;
              }
              else{
              cellBack();
              }
        }
        else{
          if((x==0 && y==0)||(x== currentx && y== currenty)){
            cellStart();
            currentx=0;
                currenty=0;
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

        F= false;
        R= false;
        L= false;

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
            if((x==0 && y==0)||(x== currentx && y== currenty)){
              leftAboutTurn();
              delay(500);
              cellStart();
              currentx=0;
                currenty=0;
            }
            else{
            leftTurn();}
            
        }

        else if (dir=='R'){
            orient = orientation(orient,'R');
            if((x==0 && y==0)||(x== currentx && y== currenty)){
              rightAboutTurn();
              delay(500);
              cellStart();
              currentx=0;
                currenty=0;
            }
            else{
            rightTurn();}
        }

        else if (dir=='B'){
            orient = orientation(orient,'L');
            orient = orientation(orient,'L');
            if((x==0 && y==0)||(x== currentx && y== currenty)){
              turnBack();
              delay(500);
              cellStart();
              currentx=0;
                currenty=0;
            }
            else{
            cellBack();}
          }
        
        else{
          if((x==0 && y==0)||(x== currentx && y== currenty)){
              cellStart();
              currentx=0;
                currenty=0;
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
            if((x==0 && y==0)){
              leftAboutTurn();
              delay(500);
              cellStart();
            }
            else{
            leftTurn();}
            
        }

        else if (dir=='R'){
            orient = orientation(orient,'R');
            if((x==0 && y==0)){
              rightAboutTurn();
              delay(500);
              cellStart();
            }
            else{
            rightTurn();}
        }

        else if (dir=='B'){
            orient = orientation(orient,'L');
            orient = orientation(orient,'L');
            if((x==0 && y==0)){
              turnBack();
              delay(500);
              cellStart();
            }
            else{
            cellBack();}
          }
        
        else{
          if((x==0 && y==0)){
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

void fixOrientation(){
  while(orient!=0){
    leftAboutTurn();
    orient = orientation(orient,'L');
    delay(500);
  }
}

void loadCells(){
  for (int i=0;i<14;i++){
    for (int j=0; j<14;j++){
      cells[j][i]= EEPROM.read(i*14+j);
    }
  }
}

void writeCells(){
  for (int i=0;i<14;i++){
    for (int j=0; j<14;j++){
      EEPROM.write(i*14+j ,sliit[j][i]);
    }
  }
}


void searchStates(){
  byte searchState= EEPROM.read(0);
  if (searchState>0){
    loadCells();
    if (searchState==1){
      mazeStart();
      if (selectMode==1){
        traverse(0,13,false,false,false);
        cellBrake();
        buzz();
        traverse(0,0,true,false,false);
        L=0; R=0; F=0;
        cellBrake();
        center();
        traverse(0,0,flase,false,false);
        cellBrake();
        fixOrientation();
      }

    }
    else if(searchState==2){
      mazeStart();

    }
    else if(searchState==3){
      mazeStart();

    }
  }
  else{
      mazeStart();
      traverse(0,0,true,false,false);
      center();
      cellBrake();
      traverse(0,0,false,false,false);
      cellBrake();
      fixOrientation();
  }


}

void eepromClear(){
  for (int i=0 ;i< 250; i++){
    EEPROM.write(i,0);
  }
}