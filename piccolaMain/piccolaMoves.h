void mazeStart()
{
    tofStart();
    if (tof[1] <= 120 && tof[2] <= 120 && tof[3] <= 120)
    {
      delay(2000);
      
    }
}

void cellForward()
{
    leftWallAvailable = 0;
    rightWallAvailable = 0;
    frontWallAvailable = 0;
    encoderLeftCount = encoderLeftCount + 1173;
    encoderRightCount = encoderRightCount + 1173;
    while (leftEncoder <= encoderLeftCount || rightEncoder <= encoderRightCount)
    {
        wallFollow();
    }
    encoderLeftCount = encoderLeftCount + 100;
    encoderRightCount = encoderRightCount + 100;
    while (leftEncoder <= encoderLeftCount || rightEncoder <= encoderRightCount)
    {
        wallFollow();
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



void rightSmoothTurn()
{
    leftBase = 180;
    rightBase = 176;
    encoderLeftCount = encoderLeftCount + 50;
    encoderRightCount = encoderRightCount + 50;
    while (leftEncoder <= encoderLeftCount || rightEncoder <= encoderRightCount)
    {
        wallFollow();
    }
    encoderLeftCount = 0;
    encoderRightCount = 0;
    leftEncoder = 0;
    rightEncoder = 0;
    encoderLeftCount = encoderLeftCount + 50;
    while (leftEncoder <= encoderLeftCount)
    {
        dif = leftEncoder - encoderLeftCount + 50;
        rightBase = rightBase - 6 - int(dif * 1.2);
        leftBase = leftBase + dif;
        forwardBase();
    }
    leftBase = 230;
    rightBase = 60;
    encoderLeftCount = encoderLeftCount + 1132;
    encoderRightCount = rightEncoder + 290;
    while (leftEncoder <= encoderLeftCount || rightEncoder <= encoderRightCount)
    {
        if (leftEncoder <= encoderLeftCount)
        {
          leftForwardBase();
        }
        else
        {
          leftBrake();
        }
        if (rightEncoder <= encoderRightCount)
        {
          rightForwardBase();
        }
        else
        {
          rightBrake();
        }
    }
    encoderLeftCount = encoderLeftCount + 50;
    while (leftEncoder <= encoderLeftCount)
    {
        dif = leftEncoder - encoderLeftCount + 50;
        rightBase = rightBase + 6 + (dif * 2);
        leftBase = leftBase - dif;
        forwardBase();
    }
    leftBase = 180;
    rightBase = 176;
    encoderLeftCount = 0;
    encoderRightCount = 0;
    leftEncoder = 0;
    rightEncoder = 0;
    encoderLeftCount = encoderLeftCount + 160;
    encoderRightCount = encoderRightCount + 160;
    while (leftEncoder <= encoderLeftCount || rightEncoder <= encoderRightCount)
    {
        wallFollow();
    }
}


void leftSmoothTurn()
{
    leftBase = 180;
    rightBase = 176;
    encoderLeftCount = encoderLeftCount + 55;
    encoderRightCount = encoderRightCount + 55;
    while (leftEncoder <= encoderLeftCount || rightEncoder <= encoderRightCount)
    {
        wallFollow();
    }
    encoderLeftCount = 0;
    encoderRightCount = 0;
    leftEncoder = 0;
    rightEncoder = 0;
    encoderRightCount = encoderRightCount + 50;
    while (rightEncoder <= encoderRightCount)
    {
        dif = rightEncoder - encoderRightCount + 50;
        rightBase = rightBase + 4 + dif;
        leftBase = leftBase - int(dif * 1.2) - 10;
        forwardBase();
    }
    rightBase = 240;
    leftBase = 55;
    encoderRightCount = encoderRightCount + 1078;
    encoderLeftCount = leftEncoder + 260;
    while (leftEncoder <= encoderLeftCount || rightEncoder <= encoderRightCount)
    {
        if (leftEncoder <= encoderLeftCount)
        {
          leftForwardBase();
        }
        else
        {
          leftBrake();
        }
        if (rightEncoder <= encoderRightCount)
        {
          rightForwardBase();
        }
        else
        {
          rightBrake();
        }
    }
    encoderRightCount = encoderRightCount + 50;
    while (leftEncoder <= encoderLeftCount)
    {
        dif = rightEncoder - encoderRightCount + 50;
        leftBase = leftBase + 10 + (dif * 2);
        rightBase = rightBase - dif - 4;
        forwardBase();
    }
    leftBase = 180;
    rightBase = 176;
    encoderLeftCount = 0;
    encoderRightCount = 0;
    leftEncoder = 0;
    rightEncoder = 0;
    encoderLeftCount = encoderLeftCount + 200;
    encoderRightCount = encoderRightCount + 200;
    while (leftEncoder <= encoderLeftCount || rightEncoder <= encoderRightCount)
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
