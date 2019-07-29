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
        rightEncoder = rightEncoder + 1;
    }
    else if (digitalRead(rightOut1) == HIGH && digitalRead(rightOut2) == HIGH)
    {
        rightEncoder = rightEncoder - 1;
    }
}

void countRightOut2()
{
    if (digitalRead(rightOut2) == HIGH && digitalRead(rightOut1) == HIGH)
    {
        rightEncoder = rightEncoder + 1;
    }
    else if (digitalRead(rightOut2) == HIGH && digitalRead(rightOut1) == LOW)
    {
        rightEncoder = rightEncoder - 1;
    }
}

void turnRightEncoder()
{   
    leftEncoder = 0;
    rightEncoder = 0;

    attachInterrupt(digitalPinToInterrupt(2), countLeftOut1, RISING);
    attachInterrupt(digitalPinToInterrupt(3), countLeftOut2, RISING);
    //attachInterrupt(digitalPinToInterrupt(4), countRightOut1, RISING);
    //attachInterrupt(digitalPinToInterrupt(5), countRightOut1, RISING);

    while ((leftEncoder <= encoderLeftCount) || (rightEncoder >= encoderRightCount))
    {
        if (leftEncoder <= encoderLeftCount)
        {
            leftForwardBase();
        }
        else
        {
            leftBrake();
        }

        if (rightEncoder >= encoderRightCount)
        {
            rightReverseBase();
        }
        else
        {
           rightBrake(); 
        }    
    }
    encoderLeftCount = 0;
    encoderRightCount = 0;
    leftEncoder = 0;
    rightEncoder = 0;
}

void turnLeftEncoder()
{   
    leftEncoder = 0;
    rightEncoder = 0;

    attachInterrupt(digitalPinToInterrupt(2), countLeftOut1, RISING);
    attachInterrupt(digitalPinToInterrupt(3), countLeftOut2, RISING);
    //attachInterrupt(digitalPinToInterrupt(4), countRightOut1, RISING);
    //attachInterrupt(digitalPinToInterrupt(5), countRightOut1, RISING);

    while ((leftEncoder >= encoderLeftCount) || (rightEncoder <= encoderRightCount))
    {
        if (leftEncoder >= encoderLeftCount)
        {
            leftReverseBase();
        }
        else
        {
            leftBrake();
        }

        if (rightEncoder <= encoderRightCount)
        {
            rightForwardBase();
        }
        else
        {
           rightBrake(); 
        }    
    }
    encoderLeftCount = 0;
    encoderRightCount = 0;
    leftEncoder = 0;
    rightEncoder = 0;
}
