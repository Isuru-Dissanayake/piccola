void countLeftOut1()
{
    leftEncoder = leftEncoder + 1;   
}

void countRightOut1()
{
    rightEncoder = rightEncoder + 1;
}

void turnBack()
{
    encoderRightCount= rightEncoder + 100;
    encoderLeftCount= leftEncoder + 100;
    while (rightEncoder <= encoderRightCount || leftEncoder <= encoderLeftCount)
    {
        dif = leftEncoder - encoderLeftCount + 100;
        rightBase = int(70+110/(1+pow(2.73,((50-dif)*0.05))));
        leftBase = int(70+110/(1+pow(2.73,((50-dif)*0.05))));
        turnRight();
    }
    rightBase=176;
    leftBase=180;
    encoderRightCount= rightEncoder + 703;
    encoderLeftCount= leftEncoder + 703;
    while(rightEncoder <= encoderRightCount || leftEncoder <= encoderLeftCount)
    {
        turnRight();
    }
    encoderRightCount= rightEncoder + 100;
    encoderLeftCount= leftEncoder + 100;
    while (rightEncoder <= encoderRightCount || leftEncoder <= encoderLeftCount)
    {
        dif = leftEncoder - encoderLeftCount + 100;
        rightBase = int(176-110/(1+pow(2.73,((50-dif)*0.05))));
        leftBase = int(180-110/(1+pow(2.73,((50-dif)*0.05))));
        turnRight();  
    }
    brake();
    leftBase = 180;
    rightBase = 176;
}

void rightAboutTurn()
{
    encoderRightCount= rightEncoder + 100;
    encoderLeftCount= leftEncoder + 100;
    while (rightEncoder <= encoderRightCount || leftEncoder <= encoderLeftCount)
    {
        dif = leftEncoder - encoderLeftCount + 100;
        rightBase = int(70+110/(1+pow(2.73,((50-dif)*0.05))));
        leftBase = int(70+110/(1+pow(2.73,((50-dif)*0.05))));
        turnRight();
    }
    rightBase=176;
    leftBase=180;
    encoderRightCount= rightEncoder + 240;
    encoderLeftCount= leftEncoder + 240;
    while(rightEncoder <= encoderRightCount)
    {
        turnRight();
    }
    encoderRightCount= rightEncoder + 100;
    encoderLeftCount= leftEncoder + 100;
    while (rightEncoder <= encoderRightCount || leftEncoder <= encoderLeftCount)
    {
        dif = leftEncoder - encoderLeftCount + 100;
        rightBase = int(176-110/(1+pow(2.73,((50-dif)*0.05))));
        leftBase = int(180-110/(1+pow(2.73,((50-dif)*0.05))));
        turnRight();  
    }
    brake();
    leftBase = 180;
    rightBase = 176;
}

void leftAboutTurn()
{
    encoderRightCount= rightEncoder + 100;
    encoderLeftCount= leftEncoder + 100;
    while (rightEncoder <= encoderRightCount || leftEncoder <= encoderLeftCount)
    {
        dif = leftEncoder - encoderLeftCount + 100;
        rightBase = int(70+110/(1+pow(2.73,((50-dif)*0.05))));
        leftBase = int(70+110/(1+pow(2.73,((50-dif)*0.05))));
        turnLeft();
    }
    rightBase=176;
    leftBase=180;
    encoderRightCount= rightEncoder + 262;
    encoderLeftCount= leftEncoder + 262;
    while(rightEncoder <= encoderRightCount)
    {
        turnLeft();
    }
    
    encoderRightCount= rightEncoder + 100;
    encoderLeftCount= leftEncoder + 100;
    while (rightEncoder <= encoderRightCount || leftEncoder <= encoderLeftCount)
    {
        dif = leftEncoder - encoderLeftCount + 100;
        rightBase = int(176-110/(1+pow(2.73,((50-dif)*0.05))));
        leftBase = int(180-110/(1+pow(2.73,((50-dif)*0.05))));
        turnLeft();  
    }
    brake();
    leftBase = 180;
    rightBase = 176;
}
