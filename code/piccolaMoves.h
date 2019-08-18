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
    encoderLeftCount = 1550;
    leftPwm = leftBase + 75;
    rightPwm = rightBase - 81;
    while (leftEncoder <= encoderLeftCount)
    {
        forward();
    }
    //brake();
    leftEncoder = 0;
    rightEncoder = 0;
    encoderLeftCount = 0;
    encoderRightCount = 0;
}

void leftTurn()
{
    leftEncoder = 0;
    rightEncoder = 0;
    encoderRightCount = 1555;
    leftPwm = leftBase - 75;
    rightPwm = rightBase + 75;
    while (rightEncoder <= encoderRightCount)
    {
        forward();
    }
    //brake();
    leftEncoder = 0;
    rightEncoder = 0;
    encoderLeftCount = 0;
    encoderRightCount = 0;
}

void cellBack()
{
    cellBrake();
    turnBack();
    cellStart();
}