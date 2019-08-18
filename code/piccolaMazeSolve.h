void mazeSolve()
{
    tofCell();
    
    switch (nextMove)
    {
    case 'F' :      //move forward
        cellForwad();
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