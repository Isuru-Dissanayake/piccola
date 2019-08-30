#include <QueueArray.h>
#include <StackArray.h>

byte x=0;
byte y=0;
byte xprev=0;
byte yprev=0;
byte orient=0;
byte state=0;
boolean shortPath= false;
byte x_0;
byte y_0;
byte x_1;
byte y_1;
byte x_2;
byte y_2;
byte x_3;
byte y_3;
byte mazeSize = 16;
boolean L,R,F;
char dir;
char turning;
QueueArray <byte> queue;
//StackArray <byte> stack;

byte cells[16][16] = {{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
            {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
            {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
            {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
            {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
            {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
            {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
            {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
            {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
            {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
            {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
            {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
            {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
            {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
            {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
            {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}};

byte flood2[16][16] = {{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
            {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
            {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
            {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
            {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
            {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
            {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
            {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
            {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
            {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
            {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
            {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
            {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
            {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
            {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
            {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}};

byte flood[16][16]={{14,13,12,11,10,9,8,7,7,8,9,10,11,12,13,14},
        {13,12,11,10,9,8,7,6,6,7,8,9,10,11,12,13},
        {12,11,10,9,8,7,6,5,5,6,7,8,9,10,11,12},
        {11,10,9,8,7,6,5,4,4,5,6,7,8,9,10,11},
        {10,9,8,7,6,5,4,3,3,4,5,6,7,8,9,10},
        {9,8,7,6,5,4,3,2,2,3,4,5,6,7,8,9},
        {8,7,6,5,4,3,2,1,1,2,3,4,5,6,7,8},
        {7,6,5,4,3,2,1,0,0,1,2,3,4,5,6,7},
        {7,6,5,4,3,2,1,0,0,1,2,3,4,5,6,7},
        {8,7,6,5,4,3,2,1,1,2,3,4,5,6,7,8},
        {9,8,7,6,5,4,3,2,2,3,4,5,6,7,8,9},
        {10,9,8,7,6,5,4,3,3,4,5,6,7,8,9,10},
        {11,10,9,8,7,6,5,4,4,5,6,7,8,9,10,11},
        {12,11,10,9,8,7,6,5,5,6,7,8,9,10,11,12},
        {13,12,11,10,9,8,7,6,6,7,8,9,10,11,12,13},
        {14,13,12,11,10,9,8,7,7,8,9,10,11,12,13,14}};


byte orientation(byte orient, char turning){
  if (turning== 'L'){
        orient-=1;
        if (orient==-1)
            orient=3;
  }
    else if(turning== 'R'){
        orient+=1;
        if (orient==4)
            orient=0;
    }
    else if(turning== 'B'){
        if (orient==0)
            orient=2;
        else if (orient==1)
            orient=3;
        else if (orient==2)
            orient=0;
        else if (orient==3)
            orient=1;
    }

    return(orient);
}

byte updateCoordinates(byte x, byte y, byte orient){
  if (orient==0)
        y++;
    if (orient==1)
        x++;
    if (orient==2)
        y--;
    if (orient==3)
        x--;

    return(x,y);
}



void updateWalls(byte x, byte y, byte orient, boolean L, boolean R, boolean F){
    if(L && R && F){
        if (orient==0)
            cells[y][x]= 13;
        else if (orient==1)
            cells[y][x]= 12;
        else if (orient==2)
            cells[y][x]= 11;
        else if (orient==3)
            cells[y][x]= 14;
    }

    else if (L && R && !F){
        if (orient==0 || orient== 2)
            cells[y][x]= 9;
        else if (orient==1 || orient==3)
            cells[y][x]= 10;
    }

    else if (L && F && !R){
        if (orient==0)
            cells[y][x]= 8;
        else if (orient==1)
            cells[y][x]= 7;
        else if (orient==2)
            cells[y][x]= 6;
        else if (orient==3)
            cells[y][x]= 5;
    }

    else if (R && F && !L){
        if (orient==0)
            cells[y][x]= 7;
        else if (orient==1)
            cells[y][x]= 6;
        else if (orient==2)
            cells[y][x]= 5;
        else if (orient==3)
            cells[y][x]= 8;
    }

    else if(F){
        if (orient==0)
            cells[y][x]= 2;
        else if (orient==1)
            cells[y][x]= 3;
        else if (orient==2)
            cells[y][x]= 4;
        else if (orient==3)
            cells[y][x]= 1;
    }

    else if(L){
        if (orient==0)
            cells[y][x]= 1;
        else if (orient==1)
            cells[y][x]= 2;
        else if (orient==2)
            cells[y][x]= 3;
        else if (orient==3)
            cells[y][x]= 4;
    }

    else if(R){
        if (orient==0)
            cells[y][x]= 3;
        else if (orient==1)
            cells[y][x]= 4;
        else if (orient==2)
            cells[y][x]= 1;
        else if (orient==3)
            cells[y][x]= 2;
    }

    else
        cells[y][x]= 15;


}

boolean isAccessible(byte x, byte y, byte xNext, byte yNext){
  if (x==xNext){
        if(y>yNext){
            if(cells[y][x]==4 || cells[y][x]==5 || cells[y][x]==6 || cells[y][x]==10 || cells[y][x]==11 || cells[y][x]==12 || cells[y][x]==14 || cells[yNext][xNext]==2 || cells[yNext][xNext]==7 || cells[yNext][xNext]==8 || cells[yNext][xNext]==10 || cells[yNext][xNext]==12 || cells[yNext][xNext]==13 || cells[yNext][xNext]==14 )
                return (false);
            else
                return(true);
        }
        else{
            if(cells[y][x]==2 || cells[y][x]==7 || cells[y][x]==8 || cells[y][x]==10 || cells[y][x]==12 || cells[y][x]==13 || cells[y][x]==14 || cells[yNext][xNext]==4 || cells[yNext][xNext]==5 || cells[yNext][xNext]==6 || cells[yNext][xNext]==10 || cells[yNext][xNext]==11 || cells[yNext][xNext]==12 || cells[yNext][xNext]==14 )
                return (false);
            else
                return(true);
        }
  }
    else if (y==yNext){
        if(x>xNext){
            if(cells[y][x]==1 || cells[y][x]==5 || cells[y][x]==8 || cells[y][x]==9 || cells[y][x]==11 || cells[y][x]==13 || cells[y][x]==14 || cells[yNext][xNext]==3 || cells[yNext][xNext]==6 || cells[yNext][xNext]==7 || cells[yNext][xNext]==9 || cells[yNext][xNext]==11 || cells[yNext][xNext]==12 || cells[yNext][xNext]==13 )
                return (false);
            else
                return (true);
        }
        else{
            if(cells[y][x]==3 || cells[y][x]==6 || cells[y][x]==7 || cells[y][x]==9 || cells[y][x]==11 || cells[y][x]==12 || cells[y][x]==13 || cells[yNext][xNext]==1 || cells[yNext][xNext]==5 || cells[yNext][xNext]==8 || cells[yNext][xNext]==9 || cells[yNext][xNext]==11 || cells[yNext][xNext]==13 || cells[yNext][xNext]==14 )
                return (false);
            else
                return (true);
        }


    }

}

byte getSurrounds(byte x,byte y){
    x_3= x-1;
    y_3=y;
    x_0=x;
    y_0=y+1;
    x_1=x+1;
    y_1=y;
    x_2=x;
    y_2=y-1;
    if(x_1>= mazeSize){
        x_1=-1;}
    if(y_0>= mazeSize){
        y_0=-1;}
    return (x_0,y_0,x_1,y_1,x_2,y_2,x_3,y_3);  //order of cells- north,east,south,west
}

void changeDestination(byte destinationy,byte destinationx){
  byte yrun=0;
  byte xrun=0;
  for (int i=0;i<16;i++){
        for (int j=0;j<16;j++){
            flood2[i][j]=0;
        }
 }


    flood[destinationy][destinationx]=0;

    queue.enqueue(destinationy);
    queue.enqueue(destinationx);


    while (!queue.isEmpty ()){
        yrun=queue.dequeue();
        xrun=queue.dequeue();

        x_0,y_0,x_1,y_1,x_2,y_2,x_3,y_3= getSurrounds(xrun,yrun);

        if(x_0>=0 && y_0>=0 ){
            if (flood[y_0][x_0]==255){
                flood[y_0][x_0]= flood[yrun][xrun]+1;
                queue.enqueue(y_0);
                queue.enqueue(x_0);
        }
        }
        if(x_1>=0 && y_1>=0 ){
            if (flood[y_1][x_1]==255){
                flood[y_1][x_1]= flood[yrun][xrun]+1;
                queue.enqueue(y_1);
                queue.enqueue(x_1);
            }
        }
        if(x_2>=0 && y_2>=0 ){
            if (flood[y_2][x_2]==255){
                flood[y_2][x_2]= flood[yrun][xrun]+1;
                queue.enqueue(y_2);
                queue.enqueue(x_2);
            }
        }
        if(x_3>=0 && y_3>=0 ){
            if (flood[y_3][x_3]==255){
                flood[y_3][x_3]= flood[yrun][xrun]+1;
                queue.enqueue(y_3);
                queue.enqueue(x_3);
            }
        }

}
}


void floodFill2(){

  for (int i=0;i<16;i++){
        for (int j=0;j<16;j++){
            flood2[i][j]=0;
        }
 }

    flood2[7][7]=1;
    flood2[8][7]=1;
    flood2[7][8]=1;
    flood2[8][8]=1;

    queue.enqueue(7);
    queue.enqueue(7);
    queue.enqueue(8);
    queue.enqueue(7);
    queue.enqueue(7);
    queue.enqueue(8);
    queue.enqueue(8);
    queue.enqueue(8);

    byte xrun=0;
    byte yrun=0;

     while (!queue.isEmpty ()){
        yrun=queue.dequeue();
        xrun=queue.dequeue();

        x_0,y_0,x_1,y_1,x_2,y_2,x_3,y_3= getSurrounds(xrun,yrun);
        if(x_0>=0 && y_0>=0 && cells[y_0][x_0]!=0){
            if (flood2[y_0][x_0]==0){
                if (isAccessible(xrun,yrun,x_0,y_0)){
                    flood2[y_0][x_0]= flood2[yrun][xrun]+1;
                    queue.enqueue(y_0);
                    queue.enqueue(x_0);
                }
            }
        }
        if(x_1>=0 && y_1>=0 && flood2[y_1][x_1]!=0){
            if (flood2[y_1][x_1]==0){
                if (isAccessible(xrun,yrun,x_1,y_1)){
                    flood2[y_1][x_1]= flood2[yrun][xrun]+1;
                    queue.enqueue(y_1);
                    queue.enqueue(x_1);
                }
            }
        }
        if(x_2>=0 && y_2>=0 && cells[y_2][x_2]!=0){
            if (flood2[y_2][x_2]==0){
                if (isAccessible(xrun,yrun,x_2,y_2)){
                    flood2[y_2][x_2]=flood2[yrun][xrun]+1;
                    queue.enqueue(y_2);
                    queue.enqueue(x_2);
                }
            }
        }
        if(x_3>=0 && y_3>=0 && cells[y_3][x_3]!=0){
            if (flood2[y_3][x_3]==0){
                if (isAccessible(xrun,yrun,x_3,y_3)){
                    flood2[y_3][x_3]=flood2[yrun][xrun]+1;
                    queue.enqueue(y_3);
                    queue.enqueue(x_3);
                }
            }
        }
     }

}


void floodFill3(){

    byte xrun=0;
    byte yrun=0;
    while (!queue.isEmpty ()){

        yrun=queue.dequeue();
        xrun=queue.dequeue();

        x_0,y_0,x_1,y_1,x_2,y_2,x_3,y_3= getSurrounds(xrun,yrun);
        if(x_0>=0 && y_0>=0 ){
            if (flood[y_0][x_0]==255){
                if (isAccessible(xrun,yrun,x_0,y_0)){
                    flood[y_0][x_0]=flood[yrun][xrun]+1;
                    queue.enqueue(y_0);
                    queue.enqueue(x_0);
                }
            }
        }
        if(x_1>=0 and y_1>=0){
            if (flood[y_1][x_1]==255){
                if (isAccessible(xrun,yrun,x_1,y_1)){
                    flood[y_1][x_1]=flood[yrun][xrun]+1;
                    queue.enqueue(y_1);
                    queue.enqueue(x_1);
                }
            }
        }
        if(x_2>=0 and y_2>=0 ){
            if (flood[y_2][x_2]==255){
                if (isAccessible(xrun,yrun,x_2,y_2)){
                    flood[y_2][x_2]=flood[yrun][xrun]+1;
                    queue.enqueue(y_2);
                    queue.enqueue(x_2);
                }
            }
        }
        if(x_3>=0 and y_3>=0 ){
            if (flood[y_3][x_3]==255){
                if (isAccessible(xrun,yrun,x_3,y_3)){
                    flood[y_3][x_3]=flood[yrun][xrun]+1;
                    queue.enqueue(y_3);
                    queue.enqueue(x_3);
                }
            }
        }
    }
}



char toMove(byte x,byte y,byte xprev,byte yprev,byte orient){
    x_0,y_0,x_1,y_1,x_2,y_2,x_3,y_3 = getSurrounds(x,y);
    byte val= flood[y][x];
    byte prev=0;
    byte minVals[4]={1000,1000,1000,1000};

    if (isAccessible(x,y,x_0,y_0)){
        if (x_0==xprev && y_0==yprev)
            prev=0;
        minVals[0]= flood[y_0][x_0];
    }

    if (isAccessible(x,y,x_1,y_1)){
        if (x_1==xprev && y_1==yprev)
            prev=1;
        minVals[1]= flood[y_1][x_1];
    }

    if (isAccessible(x,y,x_2,y_2)){
        if (x_2==xprev && y_2==yprev)
            prev=2;
        minVals[2]= flood[y_2][x_2];
    }

    if (isAccessible(x,y,x_3,y_3)){
        if (x_3==xprev && y_3==yprev)
            prev=3;
        minVals[3]= flood[y_3][x_3];
    }

    byte minVal=minVals[0];
    byte minCell=0;
    byte noMovements=0;

    for (int i=4; i<4;i++){
        if (minVals[i]!=1000)
            noMovements+=1;
    }

    for (int i=4; i<4;i++){
        if (minVals[i]<minVal){
            if (noMovements==1){
                minVal= minVals[i];
                minCell= i;
            }
            else{
                if(i!=prev){
                    minVal= minVals[i];
                    minCell= i;
                }
            }
        }
    }

    if (minCell==orient)
        return ('F');
    else if((minCell==orient-1) || (minCell== orient+3))
        return('L');
    else if ((minCell==orient+1) || (minCell== orient-3))
        return('R');
    else
        return('B');


}


char toMove2(byte x,byte y,byte xprev,byte yprev,byte orient){

    x_0,y_0,x_1,y_1,x_2,y_2,x_3,y_3 = getSurrounds(x,y);
    byte val= flood2[y][x];
    byte minCell=0;
    if (isAccessible(x,y,x_0,y_0)){
        if (flood2[y_0][x_0]==val-1)
            minCell=0;
    }

    if (isAccessible(x,y,x_1,y_1)){
        if (flood2[y_1][x_1]==val-1)
            minCell=1;
    }

    if (isAccessible(x,y,x_2,y_2)){
        if (flood2[y_2][x_2]==val-1)
            minCell=2;
    }

    if (isAccessible(x,y,x_3,y_3)){
        if (flood2[y_3][x_3]==val-1)
            minCell=3;
    }


    if (minCell==orient)
        return ('F');
    else if((minCell==orient-1) || (minCell== orient+3))
        return('L');
    else if ((minCell==orient+1) || (minCell== orient-3))
        return('R');
    else
        return('B');

}





void appendZero(){

    for (int i=0; i<16; i++){
        for (int j=0; j<16; j++){
            flood[i][j]=255;
        }
    }

    flood[7][7]=0;
    flood[8][7]=0;
    flood[7][8]=0;
    flood[8][8]=0;

    queue.enqueue(7);
    queue.enqueue(7);
    queue.enqueue(8);
    queue.enqueue(7);
    queue.enqueue(7);
    queue.enqueue(8);
    queue.enqueue(8);
    queue.enqueue(8);
}

void appendDestination(byte x,byte y){

    for (int i=0; i<16; i++){
        for (int j=0; j<16; j++){
            flood[i][j]=255;
        }
    }

    flood[y][x]=0;

    queue.enqueue(y);
    queue.enqueue(x);
}


char maze(boolean L, boolean R, boolean F){

  updateWalls(x,y,orient,L,R,F);


  if (flood[y][x]!=0){

            if (state==0){
                appendZero();}

            floodFill3();
  }

        else{
            if (state==0){
                //x,y,xprev,yprev,orient= center(x,y,orient)
                changeDestination(15,0);
                state+=1;
            }

            floodFill2();
        }


        if (shortPath){
            dir= toMove2(x,y,xprev,yprev,orient);}
        else{
            dir= toMove(x,y,xprev,yprev,orient);}

        if (dir=='L'){
            orient = orientation(orient,'L');
        }

        else if (dir=='R'){
            orient = orientation(orient,'R');
        }

        else if (dir=='B'){
            orient = orientation(orient,'L');
            orient = orientation(orient,'L');
        }

        xprev=x;
        yprev=y;
        x,y = updateCoordinates(x,y,orient);
        return(dir);

}
