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

void cellForward()
{
    encoderLeftCount = encoderLeftCount + 1160;
    encoderRightCount = encoderRightCount + 1160;
    while (leftEncoder <= encoderLeftCount || rightEncoder <= encoderRightCount)
    {
        wallFollow();
    }
    encoderLeftCount = encoderLeftCount + 100;
    encoderRightCount = encoderRightCount + 100;
    while (leftEncoder <= encoderLeftCount || rightEncoder <= encoderRightCount)
    {
        wallFollow();
        tofCell();
        if (tof[1] <= 150)
        {
          leftWallAvailable = leftWallAvailable + 1;
        }
        else
        {
          leftWallAvailable = leftWallAvailable - 1;
        }
        if (tof[3] <= 150)
        {
          rightWallAvailable = rightWallAvailable + 1;
        }
        else
        {
          rightWallAvailable = rightWallAvailable - 1;
        }
    }
    encoderLeftCount = leftEncoder;
    encoderRightCount = rightEncoder;
}



void rightSmoothTurn()
{
    encoderLeftCount = encoderLeftCount + 50;
    encoderRightCount = encoderRightCount + 50;
    while (leftEncoder <= encoderLeftCount || rightEncoder <= encoderRightCount)
    {
        forwardBase();
    }
    encoderLeftCount = encoderLeftCount + 75;
    encoderRightCount = encoderRightCount + 75;
    while (leftEncoder <= encoderLeftCount || rightEncoder <= encoderRightCount)
    {
        dif = leftEncoder - encoderLeftCount + 75;
        rightBase = rightBase - dif;
        leftBase = leftBase + dif;
        forwardBase();
    }
    leftBase = 255;
    rightBase = 101;
    encoderLeftCount = encoderLeftCount + 550;
    encoderRightCount = encoderRightCount + 550;
    while (leftEncoder <= encoderLeftCount || rightEncoder <= encoderRightCount)
    {
        forwardBase();
    }
    encoderLeftCount = encoderLeftCount + 75;
    encoderRightCount = encoderRightCount + 75;
    while (leftEncoder <= encoderLeftCount || rightEncoder <= encoderRightCount)
    {
        dif = leftEncoder - encoderLeftCount + 75;
        rightBase = rightBase + dif;
        leftBase = leftBase - dif;
        forwardBase();
    }
    leftBase = 180;
    rightBase = 176;
    encoderLeftCount = encoderLeftCount + 50;
    encoderRightCount = encoderRightCount + 50;
    while (leftEncoder <= encoderLeftCount || rightEncoder <= encoderRightCount)
    {
        forwardBase();
    }
    encoderLeftCount = leftEncoder;
    encoderRightCount = rightEncoder;
}


void leftSmoothTurn()
{
    encoderLeftCount = encoderLeftCount + 75;
    encoderRightCount = encoderRightCount + 75;
    while (leftEncoder <= encoderLeftCount || rightEncoder <= encoderRightCount)
    {
        forwardBase();
    }
    encoderLeftCount = encoderLeftCount + 75;
    encoderRightCount = encoderRightCount + 75;
    while (leftEncoder <= encoderLeftCount || rightEncoder <= encoderRightCount)
    {
        dif = leftEncoder - encoderLeftCount + 75;
        rightBase = rightBase + dif;
        leftBase = leftBase - dif;
        forwardBase();
    }
    leftBase = 105;
    rightBase = 255;
    encoderLeftCount = encoderLeftCount + 1100;
    encoderRightCount = encoderRightCount + 1100;
    while (leftEncoder <= encoderLeftCount || rightEncoder <= encoderRightCount)
    {
        forwardBase();
    }
    encoderLeftCount = encoderLeftCount + 75;
    encoderRightCount = encoderRightCount + 75;
    while (leftEncoder <= encoderLeftCount || rightEncoder <= encoderRightCount)
    {
        dif = leftEncoder - encoderLeftCount + 75;
        rightBase = rightBase - dif;
        leftBase = leftBase + dif;
        forwardBase();
    }
    leftBase = 180;
    rightBase = 176;
    encoderLeftCount = encoderLeftCount + 75;
    encoderRightCount = encoderRightCount + 75;
    while (leftEncoder <= encoderLeftCount || rightEncoder <= encoderRightCount)
    {
        forwardBase();
    }
    encoderLeftCount = leftEncoder;
    encoderRightCount = rightEncoder;
}



void rightTurn()
{
    cellBrake();
    rightAboutTurn();
    cellStart();
}

void leftTurn()
{
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
