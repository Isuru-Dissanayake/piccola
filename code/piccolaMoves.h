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
        encoderPid();
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
    leftBase = 200;
    rightBase = 200;
    leftWallAvailable = 0;
    rightWallAvailable = 0;
    frontWallAvailable = 0;
    encoderLeftCount = encoderLeftCount + 1273;
    encoderRightCount = encoderRightCount + 1273;
    while (leftEncoder <= encoderLeftCount || rightEncoder <= encoderRightCount)
    {
        wallFollow();
        //encoderPid();
        //tof[2] = tof3.readRangeSingleMillimeters();
        //tof[2] = tof3.readRangeSingleMillimeters();
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
    encoderLeftCount = encoderLeftCount + 200;
    encoderRightCount = encoderRightCount + 200;
    while (leftEncoder <= encoderLeftCount || rightEncoder <= encoderRightCount)
    {
        wallFollow();
        tof[2] = tof3.readRangeSingleMillimeters();
        tof[2] = tof3.readRangeSingleMillimeters();
        if (tof[2] <=240)
        {
          while (tof[2] > 133)
          {   
              wallFollow();
          }
          test = 2;
          break;
        }
    }
    encoderLeftCount = 0;
    encoderRightCount = 0;
    leftEncoder = 0;
    rightEncoder = 0;
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
    encoderLeftCount = encoderLeftCount + 180;
    encoderRightCount = encoderRightCount + 180;
    while (leftEncoder <= encoderLeftCount || rightEncoder <= encoderRightCount)
    {
        wallFollow();
        tof[2] = tof3.readRangeSingleMillimeters();
        tof[2] = tof3.readRangeSingleMillimeters();
        if (tof[2] <=240)
        {
          while (tof[2] > 135)
          {   
              wallFollow();
          }
          test = 2;
          break;
        }
    }
    encoderLeftCount = 0;
    encoderRightCount = 0;
    leftEncoder = 0;
    rightEncoder = 0;
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
