#define PWMA A0    //motor driver pins
#define AIN2 12  
#define AIN1 11
#define STBY 10
#define BIN1 9
#define BIN2 8
#define PWMB A1

#define leftOut1 2   //interrupt pins of motors
#define leftOut2 3
#define rightOut1 4
#define rightOut2 5


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