int leftBase =180;
int rightBase = 176;
int leftPwm;
int rightPwm;

int leftEncoder;
int rightEncoder;
int encoderLeftCount;
int encoderRightCount;

float tof[5];
int wallAvailable[3];
int cellWalls[3];

float leftP = 0.15;
float leftD = 0;

float leftError = 0;
float leftLastError = 0;

float rightP = 0.15;
float rightD = 0;

float rightError = 0;
float rightLastError = 0;

float wallP = 0.15;
float wallD = 0.02;

float wallError = 0;
float wallLastError = 0;

float correction;

char nextMove = 'F';
