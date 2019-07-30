void tofRead()
{
    
}

void checkWalls()
{
    wallAvailable[5] ={0};
    cellWalls[3] = {0};

    //check left wall availability
    if (tof[0] <= 100)
    {
        cellWalls[0] =  1;
        wallAvailable[0] = 1;
    }
    else
    {
        tofRead();
        if (tof[0] <= 100)
        {
            cellWalls[0] = 1;
            wallAvailable[0] = 1;
        }
        else
        {
            tofRead();
            if (tof[0] <= 100)
            {
                cellWalls[0] = 1;
                wallAvailable[0] = 1;
            }
            else
            {
                cellWalls[0] = 0;
                wallAvailable[0] = 0;
            }
            
        }
        
    }

    //check right wall availability
    if (tof[4] <= 100)
    {
        cellWalls[2] =  1;
        wallAvailable[4] = 1;
    }
    else
    {
        tofRead();
        if (tof[4] <= 100)
        {
            cellWalls[2] = 1;
            wallAvailable[4] = 1;
        }
        else
        {
            tofRead();
            if (tof[4] <= 100)
            {
                cellWalls[2] = 1;
                wallAvailable[4] = 1;
            }
            else
            {
                cellWalls[2] = 0;
                wallAvailable[4] = 0;
            }
            
        }
        
    }

    //check front wall availability
    if (tof[2] > 40)
    {
        cellWalls[1] =  0;
        wallAvailable[2] = 0;
    }
    else
    {
        tofRead();
        if (tof[2] > 40)
        {
            cellWalls[1] = 0;
            wallAvailable[2] = 0;
        }
        else
        {
            tofRead();
            if (tof[2] > 40)
            {
                cellWalls[1] = 0;
                wallAvailable[2] = 0;
            }
            else
            {
                cellWalls[1] = 1;
                wallAvailable[2] = 1;
            }
            
        }
        
    }

    //check left-forward wall availability
    if (tof[1] <= 200)
    {
        wallAvailable[1] = 1;
    }
    else
    {
        tofRead();
        if (tof[1] <= 200)
        {
            wallAvailable[1] = 1;
        }
        else
        {
            tofRead();
            if (tof[1] <= 200)
            {
                wallAvailable[1] = 1;
            }
            else
            {
                wallAvailable[1] = 0;
            }
            
        }
        
    }
    
    //check left-forward wall availability
    if (tof[3] <= 200)
    {
        wallAvailable[3] = 1;
    }
    else
    {
        tofRead();
        if (tof[3] <= 200)
        {
            wallAvailable[3] = 1;
        }
        else
        {
            tofRead();
            if (tof[3] <= 200)
            {
                wallAvailable[3] = 1;
            }
            else
            {
                wallAvailable[3] = 0;
            }
            
        }
        
    }
    
}