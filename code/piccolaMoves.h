void cellForward()
{
    leftEncoder = 0;
    rightEncoder = 0;
    encoderLeftCount = 1250;
    encoderRightCount = 1250;
    while (leftEncoder <= encoderLeftCount || rightEncoder <= encoderRightCount)
    {
        tofPid();
        if (tof[2] <=138)
        {
            break;
        }
        else
        {
            wallFollow();
        }
    }
}

void rightTurn()
{
    leftEncoder = 0;
    rightEncoder = 0;
    encoderLeftCount = 1340;
    while (leftEncoder <= 50)
    {
        leftBase = int(180+75/(1+pow(2.73,((25-rightEncoder)*0.05))));
        rightBase = int(176-86/(1+pow(2.73,((25-leftEncoder)*0.05))));
        forwardBase();
    }
    leftBase = 255;
    rightBase = 90;
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
        rightBase = int(90+86/(1+pow(2.73,((25-leftEncoder)*0.05))));
        forwardBase();
    }
    leftEncoder = 0;
    rightEncoder = 0;
    leftBase = 180;
    rightBase = 176;
    while (leftEncoder <= 50)
    {
        forwardBase();
    }
    leftEncoder = 0;
    rightEncoder = 0;
    encoderLeftCount = 0;
    encoderRightCount = 0;
}

void leftTurn()
{
    leftEncoder = 0;
    rightEncoder = 0;
    encoderRightCount = 1340;
    while (rightEncoder <= 50)
    {
        rightBase = int(176+79/(1+pow(2.73,((25-rightEncoder)*0.05))));
        leftBase = int(180-100/(1+pow(2.73,((25-leftEncoder)*0.05))));
        forwardBase();
    }
    leftBase = 80;
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
        leftBase = int(80+100/(1+pow(2.73,((25-leftEncoder)*0.05))));
        forwardBase();
    }

    leftEncoder = 0;
    rightEncoder = 0;
    leftBase = 180;
    rightBase = 176;
    while (rightEncoder <= 70)
    {
        tof[2] = tof3.readRangeSingleMillimeters();
        if (tof[2] <= 138)
        {
            brake();
            break;
        }
        else
        {
            forwardBase();
        }
    }
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