void cellStart()
{rightEncoder=0;
leftEncoder=0;
encoderRightCount=600;
encoderLeftCount=600;
rightBase=60;
leftBase=60;

while (rightEncoder <= encoderRightCount || leftEncoder <= encoderLeftCount)
    {

      rightBase = int(70+110/(1+pow(2.73,((300-rightEncoder)*0.012))));
      leftBase = int(70+110/(1+pow(2.73,((300-leftEncoder)*0.012))));
      forwardBase();
    }
 rightBase=175;
 leftBase=180;
forwardBase();
}

void cellBrake()
{
rightEncoder=0;
leftEncoder=0;
encoderRightCount=600;
encoderLeftCount=600;
rightBase=175;
leftBase=180;

while (rightEncoder <= encoderRightCount || leftEncoder <= encoderLeftCount)
    {
      rightBase = int(180-110/(1+pow(2.73,((300-rightEncoder)*0.012))));
      leftBase = int(180-110/(1+pow(2.73,((300-leftEncoder)*0.012))));
      
        forwardBase();
        
    }
    brake();
}
