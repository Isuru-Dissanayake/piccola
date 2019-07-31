#define PWMA A0    //motor driver pins
#define AIN2 12  
#define AIN1 11
#define STBY 10
#define BIN1 9
#define BIN2 8
#define PWMB A1

#define leftOut1 2   //interrupt pins of motors 
#define leftOut2 13          
#define rightOut1 A2
#define rightOut2 A3

#define GPIO1 7           
#define GPIO2 6           
#define GPIO3 5 
#define GPIO4 4
#define GPIO5 3

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