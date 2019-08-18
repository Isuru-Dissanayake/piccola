void mazeSolve()
{
    tofCell();
    checkWallsCell();
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