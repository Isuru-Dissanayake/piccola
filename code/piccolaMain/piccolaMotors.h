void stbyHigh()
{
    digitalWrite(STBY, HIGH);
}

void stbyLow()
{
    digitalWrite(STBY, LOW);
}

void leftForward()
{
    digitalWrite(AIN1, HIGH);
    digitalWrite(AIN2, LOW);
}

void leftReverse()
{
    digitalWrite(AIN1, LOW);
    digitalWrite(AIN2, HIGH);
}

void leftBrake()
{
    digitalWrite(AIN1, HIGH);
    digitalWrite(AIN2, HIGH);
}

void leftForwardBase()
{
    leftForward();
    analogWrite(PWMA, leftBase);
}

void leftReverseBase()
{
    leftReverse();
    analogWrite(PWMA, leftBase);
}

void rightForward()
{
    digitalWrite(BIN1, HIGH);
    digitalWrite(BIN2, LOW);
}

void rightReverse()
{
    digitalWrite(BIN1, LOW);
    digitalWrite(BIN2, HIGH);
}

void rightBrake()
{
    digitalWrite(BIN1, HIGH);
    digitalWrite(BIN2, HIGH);
}

void rightForwardBase()
{
    rightForward();
    analogWrite(PWMB, rightBase);
}

void rightReverseBase()
{
    rightReverse();
    analogWrite(PWMB, rightBase);
}

void writePwm()
{
    analogWrite(PWMA, leftPwm);
    analogWrite(PWMB, rightPwm);
}

void writeBasePwm()
{
    analogWrite(PWMA, leftBase);
    analogWrite(PWMB, rightBase);
}

void forward()
{
    leftForward();
    rightForward();
    writePwm();
}

void reverse()
{
    leftReverse();
    rightReverse();
    writePwm();
}

void brake()
{
    leftBrake();
    rightBrake();
    delay(100);
}

void forwardBase()
{
    leftForward();
    rightForward();
    writeBasePwm();
}

void reverseBase()
{
    leftReverse();
    rightReverse();
    writeBasePwm();
}

void turnRight()
{
    leftForward();
    rightReverse();
    writeBasePwm();
}

void turnLeft()
{
    leftReverse();
    rightForward();
    writeBasePwm();
}