void countLeftOut1()
{
    if (digitalRead(leftOut1) == HIGH && digitalRead(leftOut2) == LOW)
    {
        leftEncoder = leftEncoder + 1;
    }
    else if (digitalRead(leftOut1) == HIGH && digitalRead(leftOut2) == HIGH)
    {
        leftEncoder = leftEncoder - 1;
    }
}

void countLeftOut2()
{
    if (digitalRead(leftOut2) == HIGH && digitalRead(leftOut1) == HIGH)
    {
        leftEncoder = leftEncoder + 1;
    }
    else if (digitalRead(leftOut2) == HIGH && digitalRead(leftOut1) == LOW) 
    {
        leftEncoder = leftEncoder - 1;
    }
}

void countRightOut1()
{
    if (digitalRead(rightOut1) == HIGH && digitalRead(rightOut2) == LOW)
    {
        rightEncoder = rightEncoder - 1;
    }
    else if (digitalRead(rightOut1) == HIGH && digitalRead(rightOut2) == HIGH)
    {
        rightEncoder = rightEncoder + 1;
    }
}

void countRightOut2()
{
    if (digitalRead(rightOut2) == HIGH && digitalRead(rightOut1) == HIGH)
    {
        rightEncoder = rightEncoder - 1;
    }
    else if (digitalRead(rightOut2) == HIGH && digitalRead(rightOut1) == LOW)
    {
        rightEncoder = rightEncoder + 1;
    }
}

void turnRightEncoder()
{   
    leftEncoder = 0;
    rightEncoder = 0;
    while (leftEncoder <= encoderLeftCount || rightEncoder >= encoderRightCount)
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
    while (rightEncoder <= encoderRightCount || leftEncoder >= encoderLeftCount)
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

void turnNinetyLeft()
{
    encoderRightCount = 440;
    encoderLeftCount = -440;
    turnLeftEncoder();
}

void turnNinetyRight()
{
    encoderLeftCount = 440;
    encoderRightCount = -440;
    turnRightEncoder();
}

void rightTurn()
{
    leftEncoder = 0;
    rightEncoder = 0;
    encoderLeftCount = 1500;
    leftPwm = leftBase + 75;
    rightPwm = rightBase - 80;
    while (leftEncoder <= encoderLeftCount)
    {
        forward();
    }
    brake();
    leftEncoder = 0;
    rightEncoder = 0;
    encoderLeftCount = 0;
    encoderRightCount = 0;
}

void leftTurn()
{
    leftEncoder = 0;
    rightEncoder = 0;
    encoderRightCount = 1500;
    leftPwm = leftBase - 85;
    rightPwm = rightBase + 75;
    while (rightEncoder <= encoderRightCount)
    {
        forward();
    }
    brake();
    leftEncoder = 0;
    rightEncoder = 0;
    encoderLeftCount = 0;
    encoderRightCount = 0;
}