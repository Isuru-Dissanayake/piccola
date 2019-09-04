void cellStart()
{
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
    encoderRightCount= encoderRightCount + 317;
    encoderLeftCount= encoderLeftCount + 317;
    while (rightEncoder <= encoderRightCount || leftEncoder <= encoderLeftCount)
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
    brake();
}
