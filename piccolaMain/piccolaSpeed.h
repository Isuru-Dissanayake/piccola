void cellStart()
{
    rightEncoder=0;
    leftEncoder=0;
    encoderRightCount=620;
    encoderLeftCount=620;
    //rightBase=70;
    //leftBase=70;
    rightBase=176;
    leftBase=180;
    while (rightEncoder <= encoderRightCount || leftEncoder <= encoderLeftCount)
    {
        //rightBase = int(70+110/(1+pow(2.73,((310-rightEncoder)*0.012))));
        //leftBase = int(70+110/(1+pow(2.73,((310-leftEncoder)*0.012))));
        //forwardBase();
        tofPid();
        wallFollow();
    }
    
    rightBase=176;
    leftBase=180;
    //forwardBase();
}

void cellBrake()
{
    rightEncoder=0;
    leftEncoder=0;
    encoderRightCount=620;
    encoderLeftCount=620;
    rightBase=176;
    leftBase=180;
    
    while (rightEncoder <= encoderRightCount || leftEncoder <= encoderLeftCount)
    {   
        //rightBase = int(176-110/(1+pow(2.73,((310-rightEncoder)*0.012))));
        //leftBase = int(180-110/(1+pow(2.73,((310-leftEncoder)*0.012))));
        //forwardBase();
        tofPid();
        wallFollow();
    }
    //brake();
    leftBase=180;
    rightBase=176;
}
