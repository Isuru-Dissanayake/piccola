void cellForward()
{
    leftEncoder = 0;
    rightEncoder = 0;
    encoderLeftCount = 1250;
    encoderRightCount = 1250;
    while (leftEncoder <= encoderLeftCount || rightEncoder <= encoderRightCount)
    {
        tofPid();
        checkWallsPid();
        wallFollow();
    }
}

void rightTurn()
{
    leftEncoder = 0;
    rightEncoder = 0;
    encoderLeftCount = 1400;
    while (leftEncoder <= 50)
    {
        leftBase = int(180+75/(1+pow(2.73,((25-rightEncoder)*0.05))));
        rightBase = int(176-115/(1+pow(2.73,((25-leftEncoder)*0.05))));
        forwardBase();
    }
    leftEncoder = 0;
    rightEncoder = 0;
    while (leftEncoder <= encoderLeftCount)
    {
        forwardBase();
    }

    leftEncoder = 0;
    rightEncoder = 0;
    while (leftEncoder <= 60)
    {
        leftBase = int(255-75/(1+pow(2.73,((25-rightEncoder)*0.05))));
        rightBase = int(56+130/(1+pow(2.73,((25-leftEncoder)*0.05))));
        forwardBase();
    }
    //brake();
    leftEncoder = 0;
    rightEncoder = 0;
    leftBase = 180;
    rightBase = 176;
    encoderLeftCount = 0;
    encoderRightCount = 0;
}

void leftTurn()
{
    leftEncoder = 0;
    rightEncoder = 0;
    encoderRightCount = 1410;
    while (rightEncoder <= 50)
    {
        rightBase = int(176+79/(1+pow(2.73,((25-rightEncoder)*0.05))));
        leftBase = int(180-90/(1+pow(2.73,((25-leftEncoder)*0.05))));
        forwardBase();
    }
    leftBase = 90;
    rightBase = 255;
    leftEncoder = 0;
    rightEncoder = 0;
    while (rightEncoder <= encoderRightCount)
    {
        forwardBase();
    }

    leftEncoder = 0;
    rightEncoder = 0;
    while (rightEncoder <= 50)
    {
        rightBase = int(255-79/(1+pow(2.73,((25-rightEncoder)*0.05))));
        leftBase = int(90+90/(1+pow(2.73,((25-leftEncoder)*0.05))));
        forwardBase();
    }

    leftEncoder = 0;
    rightEncoder = 0;
    leftBase = 180;
    rightBase = 176;
    while (rightEncoder <= 10)
    {
        forwardBase();
    }
    //brake();
    leftEncoder = 0;
    rightEncoder = 0;
    leftBase = 180;
    rightBase = 176;
    encoderLeftCount = 0;
    encoderRightCount = 0;
}

void cellBack()
{
    cellBrake();
    turnBack();
    cellStart();
}