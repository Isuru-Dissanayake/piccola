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

void cellBack()
{
    cellBrake();
    turnBack();
    cellStart();
}