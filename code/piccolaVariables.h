int leftBase = 120;
int rightBase = 120;
int leftPwm;
int rightPwm;

int leftEncoder;
int rightEncoder;
int encoderLeftCount;
int encoderRightCount;

float tof[5];

float leftP = 7.0;
float leftD = 3.5;

float leftError;
float leftLastError;

float rightP = 7.0;
float rightD = 3.5;

float rightError;
float rightLastError;

float wallP = 7.0;
float wallD = 3.5;

float wallError;
float wallLastError;

float correction;