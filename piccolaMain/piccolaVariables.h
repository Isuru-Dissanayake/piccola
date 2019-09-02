int leftBase =180;
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
float leftI=0.01;

float leftError = 0;
float leftLastError = 0;
float leftSumError=0;

float rightP = 0.8;
float rightD =3.4;
float rightI=0.01;

float rightError = 0;
float rightLastError = 0;
float rightSumError=0;

float wallP = 0.7;
float wallI = 0;
float wallD = 0.8;//0.8;

float wallP2 = 0.8;
float wallI2 = 0;
float wallD2 = 2.5;//0.8;

float wallError = 0;
float wallLastError = 0;
float wallSumError = 0;

float wallError2 = 0;
float wallLastError2 = 0;
float wallSumError2 = 0;

float correction;
float correction2;

char nextMove = 'F';

unsigned long time;


boolean left,right,front;
int cell =0;
/*boolean  L = true;
boolean  R= true;
boolean  F= false; */




int state=0;
int prevState=0;
long jump=0;
