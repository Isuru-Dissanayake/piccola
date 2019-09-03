void cellStart()
{
    encoderRightCount = encoderRightCount + 110;
    encoderLeftCount = encoderLeftCount + 110;
    rightBase=70;
    leftBase=70;
    while (rightEncoder <= encoderRightCount || leftEncoder <= encoderLeftCount)
    {
        dif = leftEncoder - encoderLeftCount + 110;
        //rightBase = int(70+110/(1+pow(2.73,((150-dif)*0.05))));
        //leftBase = int(70+110/(1+pow(2.73,((150-dif)*0.05))));
        rightBase = 70 + dif;
        leftBase = 70 +dif;
        forwardBase();
    }
    rightBase=176;
    leftBase=180;
    encoderRightCount= encoderRightCount + 400;
    encoderLeftCount= encoderLeftCount + 400;
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
    
    //encoderLeftCount = leftEncoder;
    //encoderRightCount = rightEncoder;
}

void cellBrake()
{
    encoderRightCount= encoderRightCount + 500;
    encoderLeftCount= encoderLeftCount + 500;
    rightBase=176;
    leftBase=180;
    while (rightEncoder <= encoderRightCount || leftEncoder <= encoderLeftCount)
    {
        wallFollow();
    }
    encoderRightCount= encoderRightCount + 110;
    encoderLeftCount= encoderLeftCount + 110;
    while (rightEncoder <= encoderRightCount || leftEncoder <= encoderLeftCount)
    {   
        dif = leftEncoder - encoderLeftCount + 110;
        //rightBase = int(180-110/(1+pow(2.73,((150-dif)*0.05))));
        //leftBase = int(180-110/(1+pow(2.73,((150-dif)*0.09))));
        rightBase = 70 + dif;
        leftBase = 70 +dif;
        forwardBase();
    }
    brake();
    //encoderLeftCount = leftEncoder;
    //encoderRightCount = rightEncoder;
}
