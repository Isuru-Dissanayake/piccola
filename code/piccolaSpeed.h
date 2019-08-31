void cellStart()
{
    rightEncoder=0;
    leftEncoder=0;
    encoderRightCount=330;
    encoderLeftCount=330;
    rightBase=70;
    leftBase=70;
    while (rightEncoder <= 300 || leftEncoder <= 300)
    {
        rightBase = int(70+110/(1+pow(2.73,((100-leftEncoder)*0.05))));
        leftBase = int(70+110/(1+pow(2.73,((100-leftEncoder)*0.05))));
        forwardBase();
    }
    rightBase=176;
    leftBase=180;
    rightEncoder=0;
    leftEncoder=0;
    while (rightEncoder <= encoderRightCount || leftEncoder <= encoderLeftCount)
    {
        tofPid();
        wallFollow();
        //forwardBase();
    }
}

void cellBrake()
{
    rightEncoder=0;
    leftEncoder=0;
    encoderRightCount=330;
    encoderLeftCount=330;
    rightBase=176;
    leftBase=180;
    while (rightEncoder <= encoderRightCount || leftEncoder <= encoderLeftCount)
    {
        forwardBase();
    }
    rightEncoder=0;
    leftEncoder=0;
    while (rightEncoder <= 300 || leftEncoder <= 300)
    {   
        rightBase = int(176-110/(1+pow(2.73,((150-leftEncoder)*0.05))));
        leftBase = int(180-110/(1+pow(2.73,((150-leftEncoder)*0.05))));
        forwardBase();
    }
    brake();
}
