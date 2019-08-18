#define GPIO1 PA0         
#define GPIO2 PA1          
#define GPIO3 PA5
#define GPIO4 PA6
#define GPIO5 PA4

#define tofAddress1 43
#define tofAddress2 44
#define tofAddress3 45
#define tofAddress4 46
#define tofAddress5 47

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
    tof1.setTimeout(10);
    tof1.setAddress(tofAddress1);

    digitalWrite(GPIO2, HIGH);
    delay(10);
    tof2.init();
    tof2.configureDefault();
    //tof2.startInterleavedContinuous();
    tof2.setTimeout(10);
    tof2.setAddress(tofAddress2);

    digitalWrite(GPIO3, HIGH);
    delay(10);
    tof3.init();
    tof3.configureDefault();
    //tof2.startInterleavedContinuous();
    tof3.setTimeout(10);
    tof3.setAddress(tofAddress3);

    digitalWrite(GPIO4, HIGH);
    delay(10);
    tof4.init();
    tof4.configureDefault();
    //tof2.startInterleavedContinuous();
    tof4.setTimeout(10);
    tof4.setAddress(tofAddress4);

    digitalWrite(GPIO5, HIGH);
    delay(10);
    tof5.init();
    tof5.configureDefault();
    //Sensor1.startRangeContinuous();
    tof5.setTimeout(10);
    tof5.setAddress(tofAddress5);
}

void tofCell()
{
    
    tof[1] = tof2.readRangeSingleMillimeters();
    tof[2] = tof3.readRangeSingleMillimeters();
    tof[3] = tof4.readRangeSingleMillimeters();
    
}

void tofPid()
{
    tof[0] = tof1.readRangeSingleMillimeters();
    tof[2] = tof3.readRangeSingleMillimeters();
    tof[4] = tof5.readRangeSingleMillimeters();
}

void printTof()
{
    
    //Serial2.print(tof[0]);
    //Serial2.print(",  ");
    
    Serial2.print(tof[1]);
    Serial2.print(",  ");
    Serial2.print(tof[2]);
    Serial2.print(",  ");
    Serial2.print(tof[3]);
    Serial2.print(",  ");
    
    //Serial2.print(tof[4]);
    
    Serial2.println();
    
}


void checkWallsPid()
{
    if (tof[2] > 170)
    {
        wallAvailable[1] =  0;
    }
    else
    {
        wallAvailable[1] =  1;
    } 

    if (tof[0] <= 135)
    {
        wallAvailable[0] = 1;
    }
    else
    {
        wallAvailable[0] = 0; 
    }

    if (tof[4] <= 135)
    {
        wallAvailable[2] = 1;
    }
    else
    {
        wallAvailable[2] = 0; 
    }
}

void checkWallsCell()
{
    if (tof[2] > 150)
    {
        cellWalls[1] =  0;
    }
    else
    {
        cellWalls[1] =  1;
    } 

    if (tof[1] <= 135)
    {
        cellWalls[0] = 1;
    }
    else
    {
        cellWalls[0] = 0; 
    }

    if (tof[3] <= 135)
    {
        cellWalls[2] = 1;
    }
    else
    {
        cellWalls[2] = 0; 
    }
}



void printWallState()
{
    for (int i=0; i<3; i++)
    {
        Serial2.print(cellWalls[i]);
        Serial2.print("   ");
    }
    Serial2.println("");
}



