import API
import sys

x=0
y=0
orient=0
cells = [[0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0],
            [0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0],
            [0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0],
            [0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0],
            [0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0],
            [0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0],
            [0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0],
            [0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0],
            [0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0],
            [0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0],
            [0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0],
            [0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0],
            [0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0],
            [0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0],
            [0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0],
            [0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0]]
cell = 0
flood=[[14,13,12,11,10,9,8,7,7,8,9,10,11,12,13,14],
        [13,12,11,10,9,8,7,6,6,7,8,9,10,11,12,13],
        [12,11,10,9,8,7,6,5,5,6,7,8,9,10,11,12],
        [11,10,9,8,7,6,5,4,4,5,6,7,8,9,10,11],
        [10,9,8,7,6,5,4,3,3,4,5,6,7,8,9,10],
        [9,8,7,6,5,4,3,2,2,3,4,5,6,7,8,9],
        [8,7,6,5,4,3,2,1,1,2,3,4,5,6,7,8],
        [7,6,5,4,3,2,1,0,0,1,2,3,4,5,6,7],
        [7,6,5,4,3,2,1,0,0,1,2,3,4,5,6,7],
        [8,7,6,5,4,3,2,1,1,2,3,4,5,6,7,8],
        [9,8,7,6,5,4,3,2,2,3,4,5,6,7,8,9],
        [10,9,8,7,6,5,4,3,3,4,5,6,7,8,9,10],
        [11,10,9,8,7,6,5,4,4,5,6,7,8,9,10,11],
        [12,11,10,9,8,7,6,5,5,6,7,8,9,10,11,12],
        [13,12,11,10,9,8,7,6,6,7,8,9,10,11,12,13],
        [14,13,12,11,10,9,8,7,7,8,9,10,11,12,13,14]]
'''
cell
refer walls in notebook
    '''


def log(string):
    sys.stderr.write("{}\n".format(string))

def updateWalls(x,y,orient,L,R,F):
    if(L and R and F):
        if (orient==0): 
            cells[y][x]= 13
        elif (orient==1): 
            cells[y][x]= 12
        elif (orient==2): 
            cells[y][x]= 11
        elif (orient==3): 
            cells[y][x]= 14

    elif (L and R and not F):
        if (orient==0 or orient== 2): 
            cells[y][x]= 9
        elif (orient==1 or orient==3): 
            cells[y][x]= 10

    elif (L and F and not R):
        if (orient==0): 
            cells[y][x]= 8
        elif (orient==1): 
            cells[y][x]= 7
        elif (orient==2): 
            cells[y][x]= 6
        elif (orient==3): 
            cells[y][x]= 5

    elif (R and F and not L):
        if (orient==0): 
            cells[y][x]= 7
        elif (orient==1): 
            cells[y][x]= 6
        elif (orient==2): 
            cells[y][x]= 5
        elif (orient==3): 
            cells[y][x]= 8

    elif(F):
        if (orient==0): 
            cells[y][x]= 2
        elif (orient==1): 
            cells[y][x]= 3
        elif (orient==2): 
            cells[y][x]= 4
        elif (orient==3): 
            cells[y][x]= 1

    elif(L):
        if (orient==0): 
            cells[y][x]= 1
        elif (orient==1): 
            cells[y][x]= 2
        elif (orient==2): 
            cells[y][x]= 3
        elif (orient==3): 
            cells[y][x]= 4

    elif(R):
        if (orient==0): 
            cells[y][x]= 3
        elif (orient==1): 
            cells[y][x]= 4
        elif (orient==2): 
            cells[y][x]= 1
        elif (orient==3): 
            cells[y][x]= 2

def isAccessible(x,y,x1,y1):
    '''returns True if mouse can move to x1,y1 from x,y (two adjescent cells)
    '''
    if (x==x1):
        if(y>y1):
            if(cells[y][x]==4 or cells[y][x]==5 or cells[y][x]==6 or cells[y][x]==10 or cells[y][x]==11 or cells[y][x]==12 or cells[y][x]==14 ):
                return (False)
            else:
                return(True)
        else:
            if(cells[y][x]==2 or cells[y][x]==7 or cells[y][x]==8 or cells[y][x]==10 or cells[y][x]==12 or cells[y][x]==13 or cells[y][x]==14 ):
                return (False)
            else:
                return(True)
            
    elif (y==y1):
        if(x>x1):
            if(cells[y][x]==1 or cells[y][x]==5 or cells[y][x]==8 or cells[y][x]==9 or cells[y][x]==11 or cells[y][x]==13 or cells[y][x]==14 ):
                return (False)
            else:
                return (True)
        else:
            if(cells[y][x]==3 or cells[y][x]==6 or cells[y][x]==7 or cells[y][x]==9 or cells[y][x]==11 or cells[y][x]==12 or cells[y][x]==13 ):
                return (False)
            else:
                return (True)

def getSurrounds(x,y):
    ''' returns x1,y1,x2,y2,x3,y3,x4,y4 the four surrounding square
    '''
    x3= x-1
    y3=y
    x0=x
    y0=y+1
    x1=x+1
    y1=y
    x2=x
    y2=y-1
    if(x1>=16):
        x1=-1
    if(y0>=16):
        y0=-1
    return (x0,y0,x1,y1,x2,y2,x3,y3)  #order of cells- north,east,south,west

def isConsistant(x,y):
    '''returns True if the value of current squre is one
    greater than the minumum value in an accessible neighbour
    '''
    x0,y0,x1,y1,x2,y2,x3,y3 = getSurrounds(x,y)
    val= flood[y][x]
    minVals=[-1,-1,-1,-1]
    if (x0>=0 and y0>=0):
        if (isAccessible(x,y,x0,y0)):
            minVals[0]=flood[y0][x0]
    if (x1>=0 and y1>=0):
        if (isAccessible(x,y,x1,y1)):
            minVals[1]=flood[y1][x1]
    if (x2>=0 and y2>=0):
        if (isAccessible(x,y,x2,y2)):
            minVals[2]=flood[y2][x2]
    if (x3>=0 and y3>=0):
        if (isAccessible(x,y,x3,y3)):
            minVals[3]=flood[y3][x3]

    minCount=0
    for i in range(4):
        if minVals[i]== -1:
            pass
        elif minVals[i]== val+1 :
            pass
        elif minVals[i]== val-1 :
            minCount+=1
            pass

    #minVal= min(minVals)

    #return(minVal)
    
    if (minCount>0):
        return (True)
    else:
        return (False)

def makeConsistant(x,y):
    x0,y0,x1,y1,x2,y2,x3,y3 = getSurrounds(x,y)

    val= flood[y][x]
    minVals=[-1,-1,-1,-1]
    if (x0>=0 and y0>=0):
        if (isAccessible(x,y,x0,y0)):
            minVals[0]=flood[y0][x0]
            #if (flood[y0][x0]<minVal):
            #minVals.append(flood[y0][x0])
                #minVal= flood[y0][x0]
    if (x1>=0 and y1>=0):
        if (isAccessible(x,y,x1,y1)):
            minVals[1]=flood[y1][x1]
            #if (flood[y1][x1]<minVal):
            #minVals.append(flood[y1][x1])
                #minVal= flood[y1][x1]
    if (x2>=0 and y2>=0):
        if (isAccessible(x,y,x2,y2)):
            minVals[2]=flood[y2][x2]
            #if (flood[y2][x2]<minVal):
            #minVals.append(flood[y1][x1])
                #minVal= flood[y2][x2]
    if (x3>=0 and y3>=0):
        if (isAccessible(x,y,x3,y3)):
            minVals[3]=flood[y3][x3]
            #if (flood[y3][x3]<minVal):
            #minVals.append(flood[y1][x1])
                #minVal= flood[y3][x3]

    for i in range(4):
        if minVals[i]== -1:
            minVals[i]= 1000

    minVal= min(minVals)
    flood[y][x]= minVal+1

def floodFill(x,y,xprev,yprev):
    '''updates the flood matrix such that every square is consistant (current cell is x,y)
    '''
    if not isConsistant(x,y):
        flood[y][x]= flood[yprev][xprev]+1
        
    stack=[]
    stack.append(x)
    stack.append(y)
    x0,y0,x1,y1,x2,y2,x3,y3= getSurrounds(x,y)
    if(x0>=0 and y0>=0):
        if (isAccessible(x,y,x0,y0)):
            stack.append(x0)
            stack.append(y0)
    if(x1>=0 and y1>=0):
        if (isAccessible(x,y,x1,y1)):
            stack.append(x1)
            stack.append(y1)
    if(x2>=0 and y2>=0):
        if (isAccessible(x,y,x2,y2)):
            stack.append(x2)
            stack.append(y2)
    if(x3>=0 and y3>=0):
        if (isAccessible(x,y,x3,y3)):
            stack.append(x3)
            stack.append(y3)

    while (len(stack)!= 0):
        yrun= stack.pop()
        xrun= stack.pop()

        if isConsistant(xrun,yrun):
            pass
        else:
            makeConsistant(xrun,yrun)
            stack.append(xrun)
            stack.append(yrun)
            x0,y0,x1,y1,x2,y2,x3,y3= getSurrounds(xrun,yrun)
            if(x0>=0 and y0>=0):
                if (isAccessible(xrun,yrun,x0,y0)):
                    stack.append(x0)
                    stack.append(y0)
            if(x1>=0 and y1>=0):
                if (isAccessible(xrun,yrun,x1,y1)):
                    stack.append(x1)
                    stack.append(y1)
            if(x2>=0 and y2>=0):
                if (isAccessible(xrun,yrun,x2,y2)):
                    stack.append(x2)
                    stack.append(y2)
            if(x3>=0 and y3>=0):
                if (isAccessible(xrun,yrun,x3,y3)):
                    stack.append(x3)
                    stack.append(y3)
        #break




    '''if isConsistant(x,y):
        return
    else:
        #API.setText(x,y,str(isConsistant(x,y)))
        #return
        fill=True
        while(fill==True):
            fill= False
            #API.setColor(x,y,'green')
            for yrun in range(16):
                for xrun in range(16):
                    if (isConsistant(xrun,yrun)):
                       pass
                    else:
                        fill = True
                        makeConsistant(xrun,yrun)

            #break 
                        
            if (fill==False):    
                break

        API.setColor(x,y,'green')

        
            for yrun in range(y+1):
                for xrun in range(x):
                    if not (isConsistant(xrun,yrun)):
                        fill = True
                        makeConsistant(xrun,yrun)

            for yrun in range(y+1,16):
                for xrun in range(x+1):
                    if not (isConsistant(xrun,yrun)):
                        fill = True
                        makeConsistant(xrun,yrun)

            for yrun in range(y,16):
                for xrun in range(x+1,16):
                    if not (isConsistant(xrun,yrun)):
                        fill = True
                        makeConsistant(xrun,yrun) 

            for yrun in range(y):
                for xrun in range(x,16):
                    if not (isConsistant(xrun,yrun)):
                        fill = True
                        makeConsistant(xrun,yrun)  ''' 
                        
def toMove(x,y,xprev,yprev,orient):
    '''returns the direction to turn into L,F,R or B
    '''
    x0,y0,x1,y1,x2,y2,x3,y3 = getSurrounds(x,y)
    val= flood[y][x]
    prev=0
    minVals=[1000,1000,1000,1000]

    if (isAccessible(x,y,x0,y0)):
        if (x0==xprev and y0==yprev):
            prev=0
        minVals[0]= flood[y0][x0]

    if (isAccessible(x,y,x1,y1)):
        if (x1==xprev and y1==yprev):
            prev=1
        minVals[1]= flood[y1][x1]

    if (isAccessible(x,y,x2,y2)):
        if (x2==xprev and y2==yprev):
            prev=2
        minVals[2]= flood[y2][x2]

    if (isAccessible(x,y,x3,y3)):
        if (x3==xprev and y3==yprev):
            prev=3
        minVals[3]= flood[y3][x3]

    minVal=minVals[0]
    minCell=0
    noMovements=0
    for i in minVals:
        if (i!=1000):
            noMovements+=1

    '''for i in range(4):
        if (minVals[i]<minVal):
            minVal= minVals[i]
            minCell= i'''

    for i in range(4):
        if (minVals[i]<minVal):
            if (noMovements==1):
                minVal= minVals[i]
                minCell= i
            else:
                if(i==prev):
                    pass
                else:
                    minVal= minVals[i]
                    minCell= i

    if (minCell==orient):
        return ('F')
    elif((minCell==orient-1) or (minCell== orient+3)):
        return('L')
    elif ((minCell==orient+1) or (minCell== orient-3)):
        return('R')
    else:
        return('B')


def toMoveBack(x,y,xprev,yprev,orient):
    '''returns the direction to turn into L,F,R or B
    '''
    x0,y0,x1,y1,x2,y2,x3,y3 = getSurrounds(x,y)
    val= flood[y][x]
    prev=0
    minVals=[1000,1000,1000,1000]

    if (isAccessible(x,y,x0,y0)):
        if (x0==xprev and y0==yprev):
            prev=0
        minVals[0]= flood[y0][x0]

    if (isAccessible(x,y,x1,y1)):
        if (x1==xprev and y1==yprev):
            prev=1
        minVals[1]= flood[y1][x1]

    if (isAccessible(x,y,x2,y2)):
        if (x2==xprev and y2==yprev):
            prev=2
        minVals[2]= flood[y2][x2]

    if (isAccessible(x,y,x3,y3)):
        if (x3==xprev and y3==yprev):
            prev=3
        minVals[3]= flood[y3][x3]

    maxVal=minVals[0]
    minCell=0
    noMovements=0
    for i in minVals:
        if (i!=1000):
            noMovements+=1

    for i in range(4):
        if (minVals[i]!=1000 and minVals[i]> maxVal):
            if (noMovements==1):
                minVal= minVals[i]
                minCell= i

            else:
                if(i==prev):
                    pass
                else:
                    minVal= minVals[i]
                    minCell= i

    #return(minCell)
    if (minCell==orient):
        return ('F')
    elif((minCell==orient-1) or (minCell== orient+3)):
        return('L')
    elif ((minCell==orient+1) or (minCell== orient-3)):
        return('R')
    else:
        return('B')

#def deadEnd(x,y):


def showFlood(xrun,yrun):
    for x in range(16):
        for y in range(16):
            API.setText(x,y,str(flood[y][x]))

def main():
    x=0
    y=0
    xprev=0
    yprev=0
    orient=0

    while True:

        L= API.wallLeft()
        R= API.wallRight()
        F= API.wallFront()
        updateWalls(x,y,orient,L,R,F)

        if (flood[y][x]!=0):
            floodFill(x,y,xprev,yprev)
        else:
            while(True):
                pass
        '''if (flood[y][x]!=0):
            floodFill(x,y)

        else:    #robot is inside the middle 
            API.turnLeft()
            orient = API.orientation(orient,'L')
            API.turnLeft()
            orient = API.orientation(orient,'L')
            log("moveForward")
            showFlood(x,y)
            API.moveForward()
            x,y = API.updateCoordinates(x,y,orient)

            while(True):
                L= API.wallLeft()
                R= API.wallRight()
                F= API.wallFront()
                updateWalls(x,y,orient,L,R,F)
                if (flood[y][x]!=0):
                    floodFill(x,y)

                direction= toMoveBack(x,y,xprev,yprev,orient)

                if (direction=='L'):
                    API.turnLeft()
                    orient = API.orientation(orient,'L')

                elif (direction=='R'):
                    API.turnRight()
                    orient = API.orientation(orient,'R')

                elif (direction=='B'):
                    API.turnLeft()
                    orient = API.orientation(orient,'L')
                    API.turnLeft()
                    orient = API.orientation(orient,'L')

                log("moveForward")
                showFlood(x,y)
                API.moveForward()
                xprev=x
                yprev=y
                x,y = API.updateCoordinates(x,y,orient)'''
                

        direction= toMove(x,y,xprev,yprev,orient)

        
        if (direction=='L'):
            API.turnLeft()
            orient = API.orientation(orient,'L')

        elif (direction=='R'):
            API.turnRight()
            orient = API.orientation(orient,'R')

        elif (direction=='B'):
            API.turnLeft()
            orient = API.orientation(orient,'L')
            API.turnLeft()
            orient = API.orientation(orient,'L')


        log("moveForward")
        showFlood(x,y)
        API.moveForward()
        xprev=x
        yprev=y
        x,y = API.updateCoordinates(x,y,orient)
        
        

if __name__ == "__main__":
    main()
