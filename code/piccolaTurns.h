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
    encoderLeftCount = 0;
    encoderRightCount = 0;
    leftEncoder = 0;
    rightEncoder = 0;
    encoderRightCount= encoderRightCount + 100;
    encoderLeftCount= encoderLeftCount + 100;
    while (rightEncoder <= encoderRightCount || leftEncoder <= encoderLeftCount)
    {
        dif = leftEncoder - encoderLeftCount + 100;
        rightBase = int(70+110/(1+pow(2.73,((50-dif)*0.05))));
        leftBase = int(70+110/(1+pow(2.73,((50-dif)*0.05))));
        turnRight();
    }
    rightBase=176;
    leftBase=180;
    encoderRightCount= encoderRightCount + 703;
    encoderLeftCount= encoderLeftCount + 703;
    while(rightEncoder <= encoderRightCount || leftEncoder <= encoderLeftCount)
    {
        turnRight();
    }
    encoderRightCount= encoderRightCount + 100;
    encoderLeftCount= encoderLeftCount + 100;
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
    encoderLeftCount = 0;
    encoderRightCount = 0;
    leftEncoder = 0;
    rightEncoder = 0;
}

void rightAboutTurn()
{
    // checked
    encoderLeftCount = 0;
    encoderRightCount = 0;
    leftEncoder = 0;
    rightEncoder = 0;
    encoderRightCount= encoderRightCount + 100;
    encoderLeftCount= encoderLeftCount + 100;
    while (rightEncoder <= encoderRightCount || leftEncoder <= encoderLeftCount)
    {
        dif = leftEncoder - encoderLeftCount + 100;
        rightBase = int(70+110/(1+pow(2.73,((50-dif)*0.05))));
        leftBase = int(70+110/(1+pow(2.73,((50-dif)*0.05))));
        turnRight();
    }
    rightBase=176;
    leftBase=180;
    encoderRightCount= encoderRightCount + 230;
    encoderLeftCount= encoderLeftCount + 230;
    while(rightEncoder <= encoderRightCount)
    {
        turnRight();
    }
    encoderRightCount= encoderRightCount + 100;
    encoderLeftCount= encoderLeftCount + 100;
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
    encoderLeftCount = 0;
    encoderRightCount = 0;
    leftEncoder = 0;
    rightEncoder = 0;
}

void leftAboutTurn()
{
    encoderLeftCount = 0;
    encoderRightCount = 0;
    leftEncoder = 0;
    rightEncoder = 0;
    encoderRightCount= encoderRightCount + 100;
    encoderLeftCount= encoderLeftCount + 100;
    while (rightEncoder <= encoderRightCount || leftEncoder <= encoderLeftCount)
    {
        dif = leftEncoder - encoderLeftCount + 100;
        rightBase = int(70+110/(1+pow(2.73,((50-dif)*0.05))));
        leftBase = int(70+110/(1+pow(2.73,((50-dif)*0.05))));
        turnLeft();
    }
    rightBase=176;
    leftBase=180;
    encoderRightCount= encoderRightCount + 250;
    encoderLeftCount= encoderLeftCount + 250;
    while(rightEncoder <= encoderRightCount)
    {
        turnLeft();
    }
    
    encoderRightCount= encoderRightCount + 100;
    encoderLeftCount= encoderLeftCount + 100;
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
    encoderLeftCount = 0;
    encoderRightCount = 0;
    leftEncoder = 0;
    rightEncoder = 0;
}
