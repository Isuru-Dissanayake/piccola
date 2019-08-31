void mazeStart()
{
    rightEncoder=0;
    leftEncoder=0;
    encoderRightCount=820;
    encoderLeftCount=820;
    rightBase=60;
    leftBase=60;

    while (rightEncoder <= encoderRightCount || leftEncoder <= encoderLeftCount)
    {
        rightBase = int(70+110/(1+pow(2.73,((300-rightEncoder)*0.012))));
        leftBase = int(70+110/(1+pow(2.73,((300-leftEncoder)*0.012))));
        forwardBase();
    }
    rightBase=177;
    leftBase=180;
    //forwardBase();
}

void prevWall(){
  if (wallAvailable[2] == 1){
    right=true;
  }
  else{
    right=false;
  }
  if (wallAvailable[0] == 1){
    left=true;
  }
  else{
    left=false;
  }
}


boolean wallChange(){
  tofPid();
  checkWallsPid();
  if((right==true && wallAvailable[2] == 0)||(right==false && wallAvailable[2] == 1)){
    tofPid();
    checkWallsPid();
    prevWall();
    return true;
  }
  if((left==true && wallAvailable[0] == 0)||(left==false && wallAvailable[0] == 1)){
    tofPid();
    checkWallsPid();
    prevWall();
    return true;
  }
  else{
    //wallFollow();
    prevWall();
    return false;
  }
  
}
/*

void cellForward(){
  leftEncoder=0;
  rightEncoder=0;
  cell=0;
  while(cell <1){
    tofPid();
    wallFollow();
    if (leftEncoder <= 100 && rightEncoder <= 100  ){
      if(wallChange()==true){
        leftEncoder=0;
        rightEncoder=0;
      }}
    else if (leftEncoder >= 1100 && rightEncoder >= 1100  ){
      if(wallChange()==true){
        leftEncoder=0;
        rightEncoder=0;
        cell++;
      }
      if(leftEncoder >= 1265 && rightEncoder >= 1265 ){
        leftEncoder=0;
        rightEncoder=0;
        cell++;
      }
    }
  }
}
*/

void cellForward()
{
    encoderLeftCount = leftEncoder  + 1260;
    encoderRightCount = rightEncoder + 1260;
    while (leftEncoder <= encoderLeftCount || rightEncoder <= encoderRightCount)
    {
        tofPid();
        wallFollow();
        //forwardBase();
    }
}

/*

void rightTurn()
{
    leftEncoder = 0;
    encoderLeftCount = 1250;
    while (leftEncoder <= 50)
    {
        leftBase = int(180+75/(1+pow(2.73,((25-leftEncoder)*0.05))));
        rightBase = int(176-90/(1+pow(2.73,((25-rightEncoder)*0.05))));
        forwardBase();
    }
    leftBase = 255;
    rightBase = 86;
    leftEncoder = 0;
    while (leftEncoder <= encoderLeftCount)
    {
        forwardBase();
    }
    leftEncoder = 0;
    while (leftEncoder <= 60)
    {
        leftBase = int(255-75/(1+pow(2.73,((30-rightEncoder)*0.05))));
        rightBase = int(86+90/(1+pow(2.73,((30-leftEncoder)*0.05))));
        forwardBase();
    }
    leftEncoder = 0;
    leftBase = 180;
    rightBase = 176;
    while (leftEncoder <= 50)
    {
        forwardBase();
    }
    leftEncoder = 0;
    rightEncoder = 0;
    encoderLeftCount = 0;
    encoderRightCount = 0;
}


void leftTurn()
{
    leftEncoder = 0;
    rightEncoder = 0;
    encoderRightCount = 1340;
    while (rightEncoder <= 50)
    {
        rightBase = int(176+70/(1+pow(2.73,((25-rightEncoder)*0.05))));
        leftBase = int(180-95/(1+pow(2.73,((25-leftEncoder)*0.05))));
        forwardBase();
    }
    leftBase = 85;
    rightBase = 246;
    leftEncoder = 0;
    rightEncoder = 0;
    while (rightEncoder <= encoderRightCount)
    {
        forwardBase();
    }

    leftEncoder = 0;
    rightEncoder = 0;
    while (rightEncoder <= 50)
    {
        rightBase = int(246-70/(1+pow(2.73,((25-rightEncoder)*0.05))));
        leftBase = int(85+95/(1+pow(2.73,((25-leftEncoder)*0.05))));
        forwardBase();
    }

    leftEncoder = 0;
    rightEncoder = 0;
    leftBase = 180;
    rightBase = 176;
    while (rightEncoder <= 60)
    {
        tof[2] = tof3.readRangeSingleMillimeters();
        if (tof[2] <= 138)
        {
            //brake();
            break;
        }
        else
        {
            forwardBase();
        }
    }
    leftEncoder = 0;
    rightEncoder = 0;
    leftBase = 180;
    rightBase = 176;
    encoderLeftCount = 0;
    encoderRightCount = 0;
}
*/


void rightTurn(){
  cellBrake();
  rightAboutTurn();
  cellStart();
}

void leftTurn(){
  cellBrake();
  leftAboutTurn();
  cellStart();
}
void cellBack()
{
    cellBrake();
    turnBack();
    cellStart();
}
