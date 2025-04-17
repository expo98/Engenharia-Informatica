int largura_base=9;

const int ON=HIGH;
const int OFF=LOW;
const int led=13;


void setup() {
  Serial.begin(9600);
  pinMode(led, OUTPUT);
  while (largura_base%2==0){
    largura_base += 1;
  }

}

void loop() {
  
  if(largura_base==1){
    Serial.println("   *");
  }
  else if(largura_base==3){
    Serial.println("   *");
    Serial.println("  ***");
  }  
  else if(largura_base==5){
    Serial.println("   *");
    Serial.println("  ***");
    Serial.println(" *****");
  }
  else if(largura_base==7){
    Serial.println("   *");
    Serial.println("  ***");
    Serial.println(" *****");
    Serial.println("*******");
  }
  else if(largura_base==9){
    Serial.println("    *");
    Serial.println("   ***");
    Serial.println("  *****");
    Serial.println(" *******");
    Serial.println("*********");
  }  
  digitalWrite(led, HIGH);
  delay(500);
  digitalWrite(led, LOW);
  delay(1000);
}