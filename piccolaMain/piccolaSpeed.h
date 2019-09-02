void cellStart()
{
    encoderRightCount = encoderRightCount + 300;
    encoderLeftCount = encoderLeftCount + 300;
    rightBase=70;
    leftBase=70;
    while (rightEncoder <= encoderRightCount || leftEncoder <= encoderLeftCount)
    {
        dif = leftEncoder - encoderLeftCount + 300;
        rightBase = int(70+110/(1+pow(2.73,((150-dif)*0.05))));
        leftBase = int(70+110/(1+pow(2.73,((150-dif)*0.05))));
        forwardBase();
    }
    rightBase=176;
    leftBase=180;
    encoderRightCount= encoderRightCount + 210;
    encoderLeftCount= encoderLeftCount + 210;
    while (rightEncoder <= encoderRightCount || leftEncoder <= encoderLeftCount)
    {
        wallFollow();
    }
    
    encoderLeftCount = encoderLeftCount + 100;
    encoderRightCount = encoderRightCount + 100;
    while (leftEncoder <= encoderLeftCount || rightEncoder <= encoderRightCount)
    {
        wallFollow();
        if (tof[0] <= 145)
        {
          leftWallAvailable= leftWallAvailable + 1;
        }
        else
        {
          leftWallAvailable= leftWallAvailable - 1;
        }
        if (tof[4] <= 145)
        {
          rightWallAvailable= rightWallAvailable + 1;
        }
        else
        {
          rightWallAvailable= rightWallAvailable - 1;
        }
    }
    
    encoderLeftCount = leftEncoder;
    encoderRightCount = rightEncoder;
}

void cellBrake()
{
    encoderRightCount= encoderRightCount + 310;
    encoderLeftCount= encoderLeftCount + 310;
    rightBase=176;
    leftBase=180;
    while (rightEncoder <= encoderRightCount || leftEncoder <= encoderLeftCount)
    {
        wallFollow();
    }
    encoderRightCount= encoderRightCount + 300;
    encoderLeftCount= encoderLeftCount + 300;
    while (rightEncoder <= encoderRightCount || leftEncoder <= encoderLeftCount)
    {   
        dif = leftEncoder - encoderLeftCount + 300;
        rightBase = int(180-110/(1+pow(2.73,((150-dif)*0.05))));
        leftBase = int(180-110/(1+pow(2.73,((150-dif)*0.09))));
        forwardBase();
    }
    brake();
    encoderLeftCount = leftEncoder;
    encoderRightCount = rightEncoder;
}
