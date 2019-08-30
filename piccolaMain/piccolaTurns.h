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

void turnBack()
{
    rightBase=177;
    leftBase=180;
    encoderLeftCount = 930;
    encoderRightCount = -930;
    turnRightEncoder();
}

void rightAboutTurn(){
  leftBase=180;
  rightBase=180;
  encoderRightCount= 500;
  encoderLeftCount= 500;
  while(rightEncoder <= encoderRightCount){
  turnRight();}
}

void leftAboutTurn(){
  leftBase=180;
  rightBase=180;
  encoderRightCount= 500;
  encoderLeftCount= 500;
  while(leftEncoder <= encoderleftCount){
  turnLeft();}
}
