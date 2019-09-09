void cellStart()
{
    leftWallAvailable = 0;
    rightWallAvailable = 0;
    frontWallAvailable = 0;
    encoderRightCount = encoderRightCount + 220;
    encoderLeftCount = encoderLeftCount + 220;
    rightBase=70;
    leftBase=70;
    while (rightEncoder <= encoderRightCount || leftEncoder <= encoderLeftCount)
    {
        dif = leftEncoder - encoderLeftCount + 220;
        rightBase = 70 + int(dif/2);
        leftBase = 70 + int(dif/2);
        forwardBase();
    }
    rightBase=176;
    leftBase=180;
    encoderRightCount= encoderRightCount + 267;
    encoderLeftCount= encoderLeftCount + 267;
    while (rightEncoder <= encoderRightCount || leftEncoder <= encoderLeftCount)
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
        if (tof[0] <= 160)
        {
          leftWallAvailable= leftWallAvailable + 1;
        }
        else
        {
          leftWallAvailable= leftWallAvailable - 1;
        }
        if (tof[4] <= 160)
        {
          rightWallAvailable= rightWallAvailable + 1;
        }
        else
        {
          rightWallAvailable= rightWallAvailable - 1;
        }
    }
}

void cellBrake()
{
    encoderRightCount= encoderRightCount + 417;
    encoderLeftCount= encoderLeftCount + 417;
    rightBase=176;
    leftBase=180;
    while (rightEncoder <= encoderRightCount || leftEncoder <= encoderLeftCount)
    {
        wallFollow();
    }
    encoderRightCount= encoderRightCount + 220;
    encoderLeftCount= encoderLeftCount + 220;
    if (F == true)
    {
      tof[2] = tof3.readRangeSingleMillimeters();
      while (tof[2] > 52)
      {   
          tof[2] = tof3.readRangeSingleMillimeters();
          dif = leftEncoder - encoderLeftCount + 220;
          rightBase = 176 - int(dif*0.75);
          leftBase = 180 - int(dif*0.85);
          if (rightBase <= 70)
          {
            rightBase = 70;
          }
          if (leftBase <= 70)
          {
            leftBase = 70;
          }
          forwardBase();
      }

      leftBase = 70;
      rightBase = 70;
      tof[2] = tof3.readRangeSingleMillimeters();
      while (tof[2] < 50)
      {   
          reverseBase();
          tof[2] = tof3.readRangeSingleMillimeters();
      }
    }
    else
    {
      while (rightEncoder <= encoderRightCount || leftEncoder <= encoderLeftCount)
      {   
          dif = leftEncoder - encoderLeftCount + 220;
          rightBase = 176 - int(dif/2);
          leftBase = 180 - int((dif*3)/5);
          if (rightBase <= 70)
          {
            rightBase = 70;
          }
          if (leftBase <= 70)
          {
            leftBase = 70;
          }
          forwardBase();
      }
    }
    brake();
}
