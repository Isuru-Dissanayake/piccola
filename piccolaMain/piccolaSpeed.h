
void cellStart()
{
    encoderRightCount = rightEncoder + 300;
    encoderLeftCount = leftEncoder + 300;
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
    encoderRightCount= rightEncoder + 300;
    encoderLeftCount= leftEncoder + 100;
    while (rightEncoder <= encoderRightCount || leftEncoder <= encoderLeftCount)
    {
        tofPid();
        wallFollow();
        //forwardBase();
    }
}

void cellBrake()
{
    encoderRightCount= rightEncoder + 300;
    encoderLeftCount= leftEncoder + 300;
    rightBase=176;
    leftBase=180;
    while (rightEncoder <= encoderRightCount || leftEncoder <= encoderLeftCount)
    {
        tofPid();
        wallFollow();
        //forwardBase();
    }
    encoderRightCount= rightEncoder + 300;
    encoderLeftCount= leftEncoder + 300;
    while (rightEncoder <= encoderRightCount || leftEncoder <= encoderLeftCount)
    {   
        dif = leftEncoder - encoderLeftCount + 300;
        rightBase = int(180-110/(1+pow(2.73,((150-dif)*0.05))));
        leftBase = int(180-110/(1+pow(2.73,((150-dif)*0.09))));
        forwardBase();
    }
    brake();
}

