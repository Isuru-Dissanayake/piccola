int leftBase =176;
int rightBase = 176;
int leftPwm;
int rightPwm;

unsigned long leftEncoder = 0;
unsigned long rightEncoder = 0;
unsigned long encoderLeftCount = 0;
unsigned long encoderRightCount = 0;

int dif = 0;

byte tof[5];
byte wallAvailable[3];
byte cellWalls[3];

byte rightWall  = 1;
byte leftWall = 1;

float leftP = 0.8;
float leftD = 3.4;

byte leftError = 0;
byte leftLastError = 0;

float rightP = 0.8;
float rightD = 3.4;

byte rightError = 0;
byte rightLastError = 0;

float wallP = 0.8;
float wallD = 2.7;

byte wallError = 0;
byte wallLastError = 0;

float correction;

char nextMove = 'F';

unsigned long time;


boolean left,right,front;
int cell =0;
