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
    stbyHigh();
    leftForward();
    analogWrite(PWMA, leftBase);
}

void leftReverseBase()
{
    stbyHigh();
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
    stbyHigh();
    rightForward();
    analogWrite(PWMB, rightBase);
}

void rightReverseBase()
{
    stbyHigh();
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
    stbyHigh();
    leftForward();
    rightForward();
    writePwm();
}

void reverse()
{
    stbyHigh();
    leftReverse();
    rightReverse();
    writePwm();
}

void brake()
{
    stbyHigh();
    leftBrake();
    rightBrake();
    delay(1000);
}

void forwardBase()
{
    stbyHigh();
    leftForward();
    rightForward();
    writeBasePwm();
}

void reverseBase()
{
    stbyHigh();
    leftReverse();
    rightReverse();
    writeBasePwm();
}

void turnRight()
{
    stbyHigh();
    leftForward();
    rightReverse();
    writeBasePwm();
}

void turnLeft()
{
    stbyHigh();
    leftReverse();
    rightForward();
    writeBasePwm();
}
