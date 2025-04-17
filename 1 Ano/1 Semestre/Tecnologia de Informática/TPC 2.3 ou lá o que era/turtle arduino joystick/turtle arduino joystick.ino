
int minX=1024;
int maxX=0;
int minY=1024;
int maxY=0;

void setup() {
  Serial.begin(9600); 
  
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  //Calibração
  for (int i=0; i<20; i++){
    int X = analogRead(A1);
    int Y = analogRead(A0);
    if (X > maxX) maxX=X;
    if (X < minX) minX=X;
    if (Y > maxY) maxY=Y;
    if (Y < minY) minY=Y;
  }
}

void loop() {
  int auxX = ReadX(maxX, minX);
  Serial.println("X:"+ String(auxX));
  int auxY = ReadY(minY, maxY);
  Serial.println("Y:" + String(auxY));
  delay(100);
}

int ReadX(int max, int min){
  int leitura = analogRead(A1);
  if ( leitura < min || leitura > max){
    return (leitura-512);
  }
  return 0;
}

int ReadY(int max, int min){
  int leitura = analogRead(A0);
  if ( (leitura < min) || (leitura > max)){
    return (leitura-512);
  }
  return 0;
}