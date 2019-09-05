
void leftPid()
{
    leftError = 85 - tof[0];
    leftDiff = leftError - leftLastError;
    
    if (leftDiff > 50 )
    {
        leftError = 10;
        leftDiff = 5;
    }

    else if (leftDiff < -50)
    {
        leftError = -10;
        leftDiff = -5;
    }
    
    correction = (leftError * leftP) + (leftDiff * leftD);
    leftLastError = leftError;
    
    if (correction > 50 )
    {
        correction = 15;
    }

    else if (correction < -50)
    {
        correction = -15;
    }
    
    leftPwm = leftBase + correction;
    rightPwm = rightBase - correction;
}

void rightPid()
{
    rightError = 80 - tof[4];
    rightDiff = rightError - rightLastError;
    if (rightDiff > 50 )
    {
        rightError = 10;
        rightDiff = 5;
    }

    else if (rightDiff < -50)
    {
        rightError = -10;
        rightDiff = -5;
    }
    
    correction  = (rightError * rightP) + (rightDiff * rightD);
    rightLastError = rightError;
    
    if (correction > 50 )
    {
        correction = 15;
    }

    else if (correction < -50)
    {
        correction = -15;
    }
    
    leftPwm = leftBase - correction;
    rightPwm = rightBase + correction;

}


void wallPid()
{
    wallError = tof[0] - (tof[4]-8);
    rightLastError = 58 - tof[4];
    leftLastError = 50 - tof[0];
    wallDiff = wallError - wallLastError;
    
    if (wallDiff > 50 )
    {
        wallError = 10;
        wallDiff = 5;
    }

    else if (wallDiff < -50)
    {
        wallError = -10;
        wallDiff = -5;
    }
    
    correction = (wallError * wallP) + (wallDiff * wallD);
    wallLastError = wallError;
    
    if (correction > 50 )
    {
        correction = 10;
    }

    else if (correction < -50)
    {
        correction = -10;
    }
    
    leftPwm = leftBase - correction;
    rightPwm = rightBase + correction;

}

void encoderPid()
{
    encoderError = leftEncoder - rightEncoder;
    if (encoderError > 50 )
    {
        encoderError = 10;
    }
    else if (encoderError < -50)
    {
        encoderError = -10;
    }
    encoderCorrection = float(encoderError * encoderP) + float(encoderLastError * encoderD);
    encoderLastError = encoderError;
    leftPwm = leftBase - encoderCorrection;
    rightPwm = rightBase + encoderCorrection;
    forward();
}

void wallFollow()
{
    tofPid();
    if (tof[0] <= 135 && tof[4] <= 135)
    {
        state = 0;
        if (state != preState)
        {
          jump = 5;
          wallLastError = 0;
        }
        if (jump>0)
        {
          //forwardBase();
          encoderPid();
          jump = jump-1;
        }
        else
        {
          wallPid();
          forward();
        }
    }

    else if (tof[0] > 135 && tof[4] <= 135)
    {
        state = 1;
        if (state != preState)
        {
          jump = 5;
          rightLastError = 0;
        }
        if (jump>0)
        {
          encoderPid();
          //forwardBase();
          jump = jump-1;
        }
        else
        {
          rightPid();
          forward();
        }
    }

    else if (tof[0] <= 135 && tof[4] > 135)
    {
        state = 2;
        if (state != preState)
        {
          jump = 5;
          leftLastError = 0;
        }
        if (jump>0)
        {
          encoderPid();
          //forwardBase();
          jump = jump-1;
        }
        else
        {
          leftPid();
          forward();
        }
    }
    else if(tof[0] > 135 && tof[4] > 135)
    {
        state = 3;
        encoderPid();
        //forwardBase();
        wallLastError = 0;
    }
    preState = state;
}  
