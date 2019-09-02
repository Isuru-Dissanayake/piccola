int leftBase =176;
int rightBase = 176;
int leftPwm;
int rightPwm;

unsigned long leftEncoder = 0;
unsigned long rightEncoder = 0;
unsigned long encoderLeftCount = 0;
unsigned long encoderRightCount = 0;

int dif = 0;
int test = 0;

float tof[5];
int wallAvailable[3];
int cellWalls[3];

int rightWall  = 1;
int leftWall = 1;

float leftP = 0.8;
float leftD = 3.4;

float leftError = 0;
float leftLastError = 0;

float rightP = 0.8;
float rightD = 3.4;

float rightError = 0;
float rightLastError = 0;

float wallP = 0.8;
float wallD = 2.7;

float wallError = 0;
float wallLastError = 0;

float correction;

char nextMove = 'F';

unsigned long time;


boolean left,right,front;
int cell =0;
