char bluetoothWalls[3];

void showCells(){
  for (int i=0; i<14; i++){
    for (int j=0; j<14;j++){
      Serial2.print(cells[i][j]); 
      Serial2.print(' ');
    }
    Serial2.println(' ');
  }
}

void showFlood(){
  for (int i=0; i<14; i++){
    for (int j=0; j<14;j++){
      Serial2.print(flood[i][j]); 
      Serial2.print(' ');
    }
    Serial2.println(' ');
  }
}

void showFlood2(){
  for (int i=0; i<14; i++){
    for (int j=0; j<14;j++){
      Serial2.print(flood2[i][j]); 
      Serial2.print(' ');
    }
    Serial2.println(' ');
  }
}

void getWalls(){
  if (Serial2.available()){
    bluetoothWalls[3] =Serial2.read();
    if(bluetoothWalls[0]=='1'){
      L= true;
    }
    else{
      L=false;
    }
    if(bluetoothWalls[1]=='1'){
      F= true;
    }
    else{
      F=false;
    }
    if(bluetoothWalls[2]=='1'){
      R= true;
    }
    else{
      R=false;
    }
    Serial2.println(maze(L,R,F));
  }
}
