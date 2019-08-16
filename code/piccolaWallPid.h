void leftPid()
{
    leftError = 60 - tof[0];
    correction = (leftError * leftP) + ((leftError - leftLastError) * leftD);
    leftLastError = leftError;
    leftPwm = leftBase + correction;
    rightPwm = rightBase - correction;
}

void rightPid()
{
    rightError = 60 - tof[4];
    correction  = (rightError * rightP) + ((rightError - rightLastError) * rightD);
    rightLastError = rightError;
    leftPwm = leftBase - correction;
    rightPwm = rightBase + correction;

}

void wallPid()
{
    wallError = tof[0] - tof[4];
    correction = (wallError * wallP) + ((wallError - wallLastError) * wallD);
    wallLastError = wallError;
    leftPwm = leftBase - correction;
    rightPwm = rightBase + correction;
}

void wallFollow()
{
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
