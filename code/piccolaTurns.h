void countLeftOut1()
{
    leftEncoder = leftEncoder + 1;   
}

void countRightOut1()
{
    rightEncoder = rightEncoder + 1;
}


void turnRightEncoder()
{   
    leftEncoder = 0;
    rightEncoder = 0;
    while (leftEncoder <= encoderLeftCount || rightEncoder <= encoderRightCount)
    {
        if (rightEncoder >= encoderRightCount) 
        {
            rightReverseBase();
        }
        else
        {
            rightBrake();
        }
        
        if (leftEncoder <= encoderLeftCount)
        {
            leftForwardBase();
        }
        else
        {
            leftBrake();
        } 
    }
    brake();
    encoderLeftCount = 0;
    encoderRightCount = 0;
    leftEncoder = 0;
    rightEncoder = 0;
}

void turnLeftEncoder()
{   
    leftEncoder = 0;
    rightEncoder = 0;
    while (rightEncoder <= encoderRightCount || leftEncoder <= encoderLeftCount)
    {
        if (rightEncoder <= encoderRightCount) 
        {
            rightForwardBase();
        }
        else
        {


            rightBrake();
        }
        
        if (leftEncoder >= encoderLeftCount)
        {
            leftReverseBase();
        }
        else
        {
            leftBrake();
        }
        
    }
    brake();
    encoderLeftCount = 0;
    encoderRightCount = 0;
    leftEncoder = 0;
    rightEncoder = 0;
}

void turnBack()
{
    rightBase=177;
    leftBase=180;
    encoderLeftCount = 930;
    encoderRightCount = 930;
    turnRightEncoder();
}

void rightAboutTurn()
{
    leftEncoder=0;
    rightEncoder=0;
    while (rightEncoder <= 100 || leftEncoder <= 100)
    {
        rightBase = int(70+110/(1+pow(2.73,((50-rightEncoder)*0.05))));
        leftBase = int(70+110/(1+pow(2.73,((50-leftEncoder)*0.05))));
        turnRight();
    }
    rightBase=176;
    leftBase=180;
    while(rightEncoder <= 350)
    {
        turnRight();
    }
    while (rightEncoder <= 450 || leftEncoder <= 450)
    {
        rightBase = int(176-110/(1+pow(2.73,((50-rightEncoder)*0.05))));
        leftBase = int(180-110/(1+pow(2.73,((50-leftEncoder)*0.05))));
        turnRight();  
    }
    brake();
}

void leftAboutTurn()
{
    leftEncoder=0;
    rightEncoder=0;
    while (rightEncoder <= 100 || leftEncoder <= 100)
    {
        rightBase = int(70+110/(1+pow(2.73,((50-rightEncoder)*0.05))));
        leftBase = int(70+110/(1+pow(2.73,((50-leftEncoder)*0.05))));
        turnLeft();
    }
    rightBase=176;
    leftBase=180;
    
    while(rightEncoder <= 362)
    {
        turnLeft();
    }
    while (rightEncoder <= 462 || leftEncoder <= 462)
    {
        rightBase = int(176-110/(1+pow(2.73,((50-rightEncoder)*0.05))));
        leftBase = int(180-110/(1+pow(2.73,((50-leftEncoder)*0.05))));
        turnLeft();  
    }
    brake();
}
