#define PWMA PB8    //motor driver pins
#define AIN2 PA12
#define AIN1 PA7
#define STBY PA11
#define BIN1 PB0
#define BIN2 PB1
#define PWMB PB9

#define leftOut1 PB12   //interrupt pins of motors 
#define leftOut2 PB13          
#define rightOut1 PB14
#define rightOut2 PB15

#define buzzer PB11

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

void buzz()
{
    digitalWrite(buzzer, HIGH);
    delay(200);
    digitalWrite(buzzer, LOW);
    delay(200);
}

void buzzTwice()
{
    tone(buzzer,2500,1000);
    delay(75);
    noTone(buzzer);
    delay(75);
    tone(buzzer,2500,1000);
    delay(150);
    noTone(buzzer);
}

void buzzDone()
{
    tone(buzzer,2500,1000);
    delay(50);
    noTone(buzzer);
    delay(30);
    tone(buzzer,2500,1000);
    delay(50);
    noTone(buzzer);
    delay(30);
    tone(buzzer,2500,1000);
    delay(50);
    noTone(buzzer);
}