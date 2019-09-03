

void showCells(){
  for (int i=13; i>=0; i--){
    for (int j=0; j<14;j++){
      Serial.print(cells[i][j]); 
      Serial.print(' ');
    }
    Serial.println(' ');
  }
}

void showFlood(){
  for (int i=13; i>=0; i--){
    for (int j=0; j<14;j++){
      Serial.print(flood[i][j]); 
      Serial.print(' ');
    }
    Serial.println(' ');
  }
}

void showFlood2(){
  for (int i=13; i>=0; i--){
    for (int j=0; j<14;j++){
      Serial.print(flood2[i][j]); 
      Serial.print(' ');
    }
    Serial.println(' ');
  }
}
