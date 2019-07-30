void leftPid()
{
    leftError = 35 - tof[0];
    correction = (leftError * leftP) + ((leftError - leftLastError) * leftD);
    leftLastError = leftError;
    leftPwm = leftBase + correction;
    rightPwm = rightBase - correction;
}

void rightPid()
{
    rightError = 35 - tof[4];
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