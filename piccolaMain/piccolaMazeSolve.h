void mazeSolve()
{
    //brake();
    //delay(1000);
    //time = millis();
    //brake();
    tofCell();
    tofCell();
    checkWallsCell();
    //printWallState();
    //delay(1000);
    if (cellWalls[2] == 0)
    {
        nextMove = 'R';
    }

    else if (cellWalls[1] == 0)
    {
        nextMove = 'F';
    }

    else if (cellWalls[0] == 0)
    {
        nextMove = 'L';
    }

    else if (cellWalls[0] == 1)
    {
        nextMove = 'B';
    }
    //Serial2.print(millis() - time);
    //Serial2.print("   ");
    //Serial2.println(nextMove);
    //delay(1000);
    switch (nextMove)
    {
    case 'F' :      //move forward
        cellForward();
        break;
    case 'R' :      //move right
        rightTurn();
        break;

    case 'L' :      //move left
        leftTurn();
        break;
    
    case 'B' :      //move back
        cellBack();
        break;
    }
    
}