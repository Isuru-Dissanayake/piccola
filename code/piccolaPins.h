#define PWMA PB8    //motor driver pins
#define AIN2 PA12
#define AIN1 PA7
#define STBY PA11
#define BIN1 PB0
#define BIN2 PB1
#define PWMB PB9

#define leftOut1 2   //interrupt pins of motors 
#define leftOut2 3          
#define rightOut1 4
#define rightOut2 5

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

void motorDiver()
{
    pinMode(PWMA, OUTPUT);
    pinMode(AIN2, OUTPUT);
    pinMode(AIN1, OUTPUT);
    pinMode(STBY, OUTPUT);
    pinMode(BIN1, OUTPUT);
    pinMode(BIN2, OUTPUT);
    pinMode(PWMB, OUTPUT);
}

void motorInterrupt()
{
    pinMode(leftOut1, INPUT);
    pinMode(leftOut2, INPUT);
    pinMode(rightOut1, INPUT);
    pinMode(rightOut2, INPUT);
}