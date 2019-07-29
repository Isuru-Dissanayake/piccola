void leftPid()
{
    leftError = 35 - tof[0];
    correction = (leftError * leftP) + (leftLastError * leftD);
    leftPwm = leftBase + correction;
    rightPwm = rightBase - correction;
}

void rightPid()
{
    rightError = 35 - tof[4];
}

void wallPid()
{
    wallError = tof[0] - tof[4];
}