char bluetoothWalls;

void showCells(){
  for (int i=0; i<14; i++){
    for (int j=0; j<14;j++){
      Serial.print(cells[i][j]); 
      Serial.print(' ');
    }
    Serial.println(' ');
  }
}

void showFlood(){
  for (int i=0; i<14; i++){
    for (int j=0; j<14;j++){
      Serial.print(flood[i][j]); 
      Serial.print(' ');
    }
    Serial.println(' ');
  }
}

void showFlood2(){
  for (int i=0; i<14; i++){
    for (int j=0; j<14;j++){
      Serial.print(flood2[i][j]); 
      Serial.print(' ');
    }
    Serial.println(' ');
  }
}

void getWalls(){
  while(1){
  //Serial.println('waiting');
  if (Serial.available()){
    bluetoothWalls =Serial.read();
    if(bluetoothWalls=='a'){
      L= true;
      R=false;
      F=false;
    }
    if(bluetoothWalls=='b'){
      L= false;
      R= true;
      F=false;
    }
    if(bluetoothWalls=='c'){
      L= false;
      R=false;
      F=true;
    }
    if(bluetoothWalls=='d'){
      L= true;
      R=false;
      F=true;
    }
    if(bluetoothWalls=='e'){
      L= false;
      R=true;
      F=true;
    }
    if(bluetoothWalls=='f'){
      L= true;
      R=true;
      F=false;
    }
    if(bluetoothWalls=='g'){
      L= true;
      R=true;
      F=true;
    }
    
    updateWalls(x,y,orient,L,R,F);
    Serial.println(x);
    Serial.println(y);
    Serial.println(L);
    Serial.println(F);
    Serial.println(R);

    //6x_0,y_0,x_1,y_1,x_2,y_2,x_3,y_3 = getSurrounds(x,y);

    
    Serial.println(' ');
    Serial.println(toMove(x,y,xprev,yprev,orient));

    
    
   
    
    Serial.println(' ');
    break;
  }
  }
}
