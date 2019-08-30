void cellStart()
{
    rightEncoder=0;
    leftEncoder=0;
    encoderRightCount=635;
    encoderLeftCount=635;
    rightBase=70;
    leftBase=70;

    while (rightEncoder <= encoderRightCount || leftEncoder <= encoderLeftCount)
    {
        rightBase = int(70+110/(1+pow(2.73,((317-rightEncoder)*0.012))));
        leftBase = int(70+110/(1+pow(2.73,((317-leftEncoder)*0.012))));
        forwardBase();
    }
    rightBase=176;
    leftBase=180;
    //forwardBase();
}

void cellBrake()
{
    rightEncoder=0;
    leftEncoder=0;
    encoderRightCount=635;
    encoderLeftCount=635;
    rightBase=176;
    leftBase=180;
    while (rightEncoder <= encoderRightCount || leftEncoder <= encoderLeftCount)

    {
        rightBase = int(176-110/(1+pow(2.73,((317-rightEncoder)*0.012))));
        leftBase = int(180-110/(1+pow(2.73,((317-leftEncoder)*0.012))));
        forwardBase();  
    }
    brake();
}
