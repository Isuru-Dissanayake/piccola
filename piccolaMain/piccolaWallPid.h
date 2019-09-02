void leftPid()
{
    leftError = 50 - tof[0];
    //wallLastError = 0 - (leftError * 2);
    correction = (leftError * leftP) + ((leftError - leftLastError) * leftD +  +(leftSumError*leftI));
    leftLastError = leftError;
    leftSumError = leftSumError + leftError;
    if (leftSumError> 4000){
      leftSumError= 4000;
    }
    else if (leftSumError<- 4000){
      leftSumError= -4000;
    }
    /*if (correction > 50 )
    {
        correction = 10;
    }

    else if (correction < -50)
    {
        correction = -10;
    }*/
    
    leftPwm = leftBase + correction;
    rightPwm = rightBase - correction;
}

void rightPid()
{
    rightError = 58 - tof[4];
    //wallLastError = rightError * 2;
    correction  = (rightError * rightP) + ((rightError - rightLastError) * rightD   +(rightSumError*rightI));
    rightLastError = rightError;
    rightSumError = rightSumError + rightError;
    if (rightSumError> 4000){
      rightSumError= 4000;
    }
    else if (rightSumError<-4000){
      rightSumError= -4000;
    }
   /* if (correction > 50 )
    {
        correction = 10;
    }

    else if (correction < -50)
    {
        correction = -10;
    }*/
    
    leftPwm = leftBase - correction;
    rightPwm = rightBase + correction;

}

void wallPid()
{
    wallError = tof[0] - (tof[4]-8);
    rightLastError = 58 - tof[4];
    leftLastError = 50 - tof[0];
    correction = (wallError * wallP) + ((wallError - wallLastError) * wallD  +(wallSumError*wallI));
    wallLastError = wallError;
    wallSumError = wallSumError + wallError;
    
    if (wallSumError> 4000){
      wallSumError=4000;
    }
    else if (wallSumError<-4000){
      wallSumError= -4000;
    }
    /*if (correction > 50 )
    {
        correction = 10;
    }

    else if (correction < -50)
    {
        correction = -10;
    }*/
    
    leftPwm = leftBase - correction;
    rightPwm = rightBase + correction;

}

/*

void wallPid()
{
    tofCell();
    if (tof[1] < 255 && tof[3] < 255)
    {
        wallError = tof[1] - tof[3];
    }
    else
    {
        if (tof[1] >= 255 && tof[3] >= 255)
        {
            wallError = 0;
        }
        else
        {
            if (tof[1] >= 255)
            {
                wallError = 170 - (2*tof[3]);
            }
            else if (tof[3] >= 255)
            {
                wallError = (2*tof[1]) - 170;
            }
        }
    }
    correction = (wallError * wallP) + (wallSumError * wallI) + ((wallError - wallLastError) * wallD);
    wallLastError = wallError;
    wallSumError = wallSumError + wallError;
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
    forward();
}*/

void wallFollow()
{
    tofPid();
    checkWallsPid();
    if (wallAvailable[0] == 1 && wallAvailable[2] == 1)
    {
        wallPid();
        forward();
    }

    else if (wallAvailable[0] == 0 && wallAvailable[2] == 1)
    {
        rightPid();
        forward();
    }

    else if (wallAvailable[0] == 1 && wallAvailable[2] == 0)
    {
        leftPid();
        forward();
    }
    else if(wallAvailable[0] == 0 && wallAvailable[2] == 0)
    {
        forwardBase();
    }
}  
