void mazeSolve()
{
    switch (nextMove)
    {
    case 'F' :
        leftEncoder = 0;
        rightEncoder = 0;
        encoderLeftCount = 1280;
        encoderRightCount = 1280;
        while (leftEncoder <= encoderLeftCount || rightEncoder <= encoderRightCount)
        {
            forwardBase();
        }
        break;
    
    case 'R' :
        //move right
        break;

    case 'L' :
        //move left
        break;
    
    case 'B' :
        //move back
        break;
    }
}