VL6180X tof1;
VL6180X tof2;
VL6180X tof3;
VL6180X tof4;
VL6180X tof5;

void tofSetup()
{
    pinMode(GPIO1, OUTPUT);
    pinMode(GPIO2, OUTPUT);
    pinMode(GPIO3, OUTPUT);
    pinMode(GPIO4, OUTPUT);
    pinMode(GPIO5, OUTPUT);
    digitalWrite(GPIO1, LOW);
    digitalWrite(GPIO2, LOW);
    digitalWrite(GPIO3, LOW);
    digitalWrite(GPIO4, LOW);
    digitalWrite(GPIO5, LOW);

    Wire.begin();

    digitalWrite(GPIO1, HIGH);
    delay(10);
    tof1.init();
    tof1.configureDefault();
    tof1.setTimeout(500);
    tof1.setAddress(tofAddress1);

    digitalWrite(GPIO2, HIGH);
    delay(10);
    tof2.init();
    tof2.configureDefault();
    //Sensor1.startRangeContinuous();
    tof2.setTimeout(500);
    tof2.setAddress(tofAddress2);

    digitalWrite(GPIO3, HIGH);
    delay(10);
    tof3.init();
    tof3.configureDefault();
    //Sensor1.startRangeContinuous();
    tof3.setTimeout(500);
    tof3.setAddress(tofAddress3);

    digitalWrite(GPIO4, HIGH);
    delay(10);
    tof4.init();
    tof4.configureDefault();
    //Sensor1.startRangeContinuous();
    tof4.setTimeout(500);
    tof4.setAddress(tofAddress4);

    digitalWrite(GPIO5, HIGH);
    delay(10);
    tof5.init();
    tof5.configureDefault();
    //Sensor1.startRangeContinuous();
    tof5.setTimeout(500);
    tof5.setAddress(tofAddress5);
}

void tofRead()
{
    tof[0] = tof1.readRangeSingleMillimeters();
    tof[1] = tof2.readRangeSingleMillimeters();
    tof[2] = tof3.readRangeSingleMillimeters();
    tof[3] = tof4.readRangeSingleMillimeters();
    tof[4] = tof5.readRangeSingleMillimeters();
}

void printTof()
{
    Serial.print(tof[0]);
    Serial.print(",  ");
    Serial.print(tof[1]);
    Serial.print(",  ");
    Serial.print(tof[2]);
    Serial.print(",  ");
    Serial.print(tof[3]);
    Serial.print(",  ");
    Serial.print(tof[4]);
    Serial.println();
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