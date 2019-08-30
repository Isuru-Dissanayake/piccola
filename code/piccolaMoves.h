void mazeStart()
{
    rightEncoder=0;
    leftEncoder=0;
    encoderRightCount=900;
    encoderLeftCount=900;
    rightBase=60;
    leftBase=60;

    while (rightEncoder <= encoderRightCount || leftEncoder <= encoderLeftCount)
    {
        rightBase = int(70+110/(1+pow(2.73,((300-rightEncoder)*0.012))));
        leftBase = int(70+110/(1+pow(2.73,((300-leftEncoder)*0.012))));
        forwardBase();
    }
    rightBase=177;
    leftBase=180;
    //forwardBase();
}

void cellForward()
{
    leftEncoder = 0;
    rightEncoder = 0;
    encoderLeftCount = 1275;
    encoderRightCount = 1275;
    while (leftEncoder <= encoderLeftCount || rightEncoder <= encoderRightCount)
    {
        tofPid();
        wallFollow();
        //forwardBase();
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
        tof[2] = tof3.readRangeSingleMillimeters();
        if (tof[2] <= 138)
        {
            //brake();
            break;
        }
        else
        {
            forwardBase();
        }
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
        rightBase = int(176+70/(1+pow(2.73,((25-rightEncoder)*0.05))));
        leftBase = int(180-95/(1+pow(2.73,((25-leftEncoder)*0.05))));
        forwardBase();
    }
    leftBase = 85;
    rightBase = 246;
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
        rightBase = int(246-70/(1+pow(2.73,((25-rightEncoder)*0.05))));
        leftBase = int(85+95/(1+pow(2.73,((25-leftEncoder)*0.05))));
        forwardBase();
    }

    leftEncoder = 0;
    rightEncoder = 0;
    leftBase = 180;
    rightBase = 176;
    while (rightEncoder <= 60)
    {
        tof[2] = tof3.readRangeSingleMillimeters();
        if (tof[2] <= 138)
        {
            //brake();
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