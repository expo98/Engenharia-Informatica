
int ledPin=3;
int poten=0;
int volt;

void setup() {
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);

}

void loop() {
	volt = analogRead(poten);
	analogWrite(ledPin,volt/4);
}

int converteStr(String istr){
  int val=0;
  int pot=1;

  for (int i=istr.length()-1;i>=0;i=i-1){
      if((istr[i]>='0') && (istr[i]<='9')){
          val=val+(istr[i]-48)*pot;
          por=pot*10;
      } else return (250);
  }
  return(val);
}