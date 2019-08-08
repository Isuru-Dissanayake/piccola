int leftBase =180;
int rightBase = 173;
int leftPwm;
int rightPwm;

int leftEncoder;
int rightEncoder;
int encoderLeftCount;
int encoderRightCount;

float tof[5];
int wallAvailable[5];
int cellWalls[3];

float leftP = 7.0;
float leftD = 3.5;

float leftError = 0;
float leftLastError = 0;

float rightP = 7.0;
float rightD = 3.5;

float rightError = 0;
float rightLastError = 0;

float wallP = 7.0;
float wallD = 3.5;

float wallError = 0;
float wallLastError = 0;

float correction;

char nextMove = 'F';
