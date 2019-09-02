void cellStart()
{
    encoderRightCount = encoderRightCount + 300;
    encoderLeftCount = encoderLeftCount + 300;
    rightBase=70;
    leftBase=70;
    test = leftEncoder;
    while (rightEncoder <= encoderRightCount || leftEncoder <= encoderLeftCount)
    {
        dif = leftEncoder - encoderLeftCount + 300;
        rightBase = int(70+110/(1+pow(2.73,((150-dif)*0.05))));
        leftBase = int(70+110/(1+pow(2.73,((150-dif)*0.05))));
        forwardBase();
    }
    rightBase=176;
    leftBase=180;
    encoderRightCount= encoderRightCount + 310;
    encoderLeftCount= encoderLeftCount + 310;
    while (rightEncoder <= encoderRightCount || leftEncoder <= encoderLeftCount)
    {
        //tofPid();
        //wallFollow();
        wallPid();
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
        //tofPid();
        //wallFollow();
        wallPid();
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
    test = leftEncoder - test;
    encoderLeftCount = leftEncoder;
    encoderRightCount = rightEncoder;
}
