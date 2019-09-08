void mazeStart()
{
    selectMode = 0;
    buzz();
    while(1)
    {
      tofStart();
      tofStart();
      if (tof[1] <= 120 && tof[2] <= 120 && tof[3] <= 120)
      {
        buzzTwice();
        selectMode = 1;
        delay(1000);
        break;
      }
    }
    buzz();
    time = 0;
    while(time < 50)
    {
      tofStart();
      tofStart();
      if (tof[1] <= 120 && tof[2] <= 120 && tof[3] <= 120)
      {
        buzzTwice();
        selectMode = 2;
        delay(1000);
        break;
      }
      time = time + 1;
    }

    if (selectMode == 2)
    {
      buzz();
      time = 0;
      while(time < 50)
      {
        tofStart();
        tofStart();
        if (tof[1] <= 120 && tof[2] <= 120 && tof[3] <= 120)
        {
          buzzTwice();
          selectMode = 3;
          delay(1000);
          break;
        }
        time = time + 1;
      }
    }
    buzzDone();
}

void cellForward()
{
    leftWallAvailable = 0;
    rightWallAvailable = 0;
    frontWallAvailable = 0;
    encoderLeftCount = encoderLeftCount + 1123;
    encoderRightCount = encoderRightCount + 1123;
    while (leftEncoder <= encoderLeftCount || rightEncoder <= encoderRightCount)
    {
        wallFollow();
    }
    encoderLeftCount = encoderLeftCount + 150;
    encoderRightCount = encoderRightCount + 150;
    while (leftEncoder <= encoderLeftCount || rightEncoder <= encoderRightCount)
    {
        wallFollow();
        //encoderPid();
        if (tof[2] <= 180)
        {
          frontWallAvailable = frontWallAvailable + 1;
        }
        else
        {
          frontWallAvailable = frontWallAvailable - 1;
        }
        if (tof[0] <= 150)
        {
          leftWallAvailable= leftWallAvailable + 1;
        }
        else
        {
          leftWallAvailable= leftWallAvailable - 1;
        }
        if (tof[4] <= 150)
        {
          rightWallAvailable= rightWallAvailable + 1;
        }
        else
        {
          rightWallAvailable= rightWallAvailable - 1;
        }
    }
}

void cellFastForward()
{
    leftBase = 180;
    rightBase = 176;
    leftWallAvailable = 0;
    rightWallAvailable = 0;
    frontWallAvailable = 0;
    encoderLeftCount = encoderLeftCount + 1273;
    encoderRightCount = encoderRightCount + 1273;
    while (leftEncoder <= encoderLeftCount || rightEncoder <= encoderRightCount)
    {
        wallFollow();
        if (tof[2] <=240)
        {
          while (tof[2] > 150)
          {   
              wallFollow();
          }
          leftEncoder = encoderLeftCount + 1;
          rightEncoder = encoderRightCount + 1;
          test = 2;
          break;
        }
    }
}


void leftSmoothTurn()
{
    leftBase = 180;
    rightBase = 176;
    encoderLeftCount = 0;
    encoderRightCount = 0;
    leftEncoder = 0;
    rightEncoder = 0;
    encoderRightCount = encoderRightCount + 300;
    while (rightEncoder <= encoderRightCount)
    {
        dif = rightEncoder - encoderRightCount + 300;
        rightBase = rightBase + int(dif * 0.1);
        leftBase = leftBase - int(dif/3);
        forwardBase();
    }
    rightBase = 210;
    leftBase = 70;
    encoderLeftCount = 0;
    encoderRightCount = 0;
    leftEncoder = 0;
    rightEncoder = 0;
    encoderRightCount = encoderRightCount + 860;
    while (rightEncoder <= encoderRightCount)
    {
        //rightForwardBase();
        //leftBrake();
        forwardBase();
    }
    encoderLeftCount = 0;
    encoderRightCount = 0;
    leftEncoder = 0;
    rightEncoder = 0;
    encoderRightCount = encoderRightCount + 300;
    while (rightEncoder <= encoderRightCount)
    {
        dif = rightEncoder - encoderRightCount + 300;
        rightBase = rightBase - int(dif * 0.1);
        leftBase = leftBase + int(dif/3);
        forwardBase();
    }
    leftBase = 180;
    rightBase = 176;
    encoderRightCount = encoderRightCount + 200;
    while (rightEncoder <= encoderRightCount)
    {
        wallFollow();
    }
}


void rightSmoothTurn()
{
    leftBase = 180;
    rightBase = 176;
    encoderLeftCount = 0;
    encoderRightCount = 0;
    leftEncoder = 0;
    rightEncoder = 0;
    encoderLeftCount = encoderLeftCount + 300;
    while (leftEncoder <= encoderLeftCount)
    {
        dif = leftEncoder - encoderLeftCount + 300;
        leftBase = leftBase + int(dif * 0.1);
        rightBase = rightBase - int(dif/3);
        forwardBase();
    }
    leftBase = 210;
    rightBase = 70;
    encoderLeftCount = 0;
    encoderRightCount = 0;
    leftEncoder = 0;
    rightEncoder = 0;
    encoderLeftCount = encoderLeftCount + 840;
    while (leftEncoder <= encoderLeftCount)
    {
        //leftForwardBase();
        //rightBrake();
        forwardBase();
    }
    encoderLeftCount = encoderLeftCount + 300;
    while (leftEncoder <= encoderLeftCount)
    {
        dif = leftEncoder - encoderLeftCount + 300;
        leftBase = leftBase - int(dif * 0.1);
        rightBase = rightBase + int(dif/3);
        forwardBase();
    }
    leftBase = 180;
    rightBase = 176;
    encoderLeftCount = encoderLeftCount + 200;
    while (leftEncoder <= encoderLeftCount)
    {
        wallFollow();
    }
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
