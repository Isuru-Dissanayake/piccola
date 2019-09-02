
void leftPid()
{
    leftError = 50 - tof[0];
    leftDiff = leftError - leftLastError;
    
    if (leftDiff > 50 )
    {
        leftError = 10;
        leftDiff = 5;
    }

    else if (leftDiff < -50)
    {
        leftError = -10;
        leftDiff = -5;
    }
    
    correction = (leftError * leftP) + (leftDiff * leftD);
    leftLastError = leftError;
    
    if (correction > 50 )
    {
        correction = 15;
    }

    else if (correction < -50)
    {
        correction = -15;
    }
    
    leftPwm = leftBase + correction;
    rightPwm = rightBase - correction;
}

void rightPid()
{
    rightError = 58 - tof[4];
    rightDiff = rightError - rightLastError;
    if (rightDiff > 50 )
    {
        rightError = 10;
        rightDiff = 5;
    }

    else if (rightDiff < -50)
    {
        rightError = -10;
        rightDiff = -5;
    }
    
    correction  = (rightError * rightP) + (rightDiff * rightD);
    rightLastError = rightError;
    
    if (correction > 50 )
    {
        correction = 15;
    }

    else if (correction < -50)
    {
        correction = -15;
    }
    
    leftPwm = leftBase - correction;
    rightPwm = rightBase + correction;

}

void wallPid()
{
    wallError = tof[0] - (tof[4]-8);
    rightLastError = 58 - tof[4];
    leftLastError = 50 - tof[0];
    wallDiff = wallError - wallLastError;
    
    if (wallDiff > 50 )
    {
        wallError = 10;
        wallDiff = 5;
    }

    else if (wallDiff < -50)
    {
        wallError = -10;
        wallDiff = -5;
    }
    
    correction = (wallError * wallP) + (wallDiff * wallD);
    wallLastError = wallError;
    
    if (correction > 50 )
    {
        correction = 15;
    }

    else if (correction < -50)
    {
        correction = -15;
    }
    
    leftPwm = leftBase - correction;
    rightPwm = rightBase + correction;

}

void wallFollow()
{
    tofPid();
    checkWallsPid();
    if (wallAvailable[0] == 1 && wallAvailable[2] == 1)
    {
        wallPid();
        forward();
    }

    else if (wallAvailable[0] == 0 && wallAvailable[2] == 1)
    {
        rightPid();
        forward();
    }

    else if (wallAvailable[0] == 1 && wallAvailable[2] == 0)
    {
        leftPid();
        forward();
    }
    else if(wallAvailable[0] == 0 && wallAvailable[2] == 0)
    {
        forwardBase();
    }
}  